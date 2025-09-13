/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT melexis_mlx90393_input

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/input/input.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include <zmk/hid.h>
#include <stdlib.h>
#include <stdbool.h>

LOG_MODULE_REGISTER(input_mlx90393, CONFIG_ZMK_INPUT_MLX90393_LOG_LEVEL);

// MLX90393 command codes (per datasheet / Arduino reference)
#define MLX90393_CMD_START_SINGLE_ZYX 0x3E
#define MLX90393_CMD_READ_MEAS_ZYX    0x4E

struct mlx90393_config {
    struct i2c_dt_spec i2c;
    uint32_t polling_interval_ms;
    uint16_t deadzone_x;
    uint16_t deadzone_y;
    uint16_t deadzone_z;
    uint16_t z_press_threshold;
    uint16_t z_hysteresis;
    uint16_t conv_delay_ms; // conversion delay between start and read
    uint16_t scale_x;       // scale divisor for X
    uint16_t scale_y;       // scale divisor for Y
    uint16_t scale_z;       // scale divisor for Z
    uint16_t x_hysteresis;  // hysteresis width around X deadzone
    uint16_t y_hysteresis;  // hysteresis width around Y deadzone
    bool disable_wheel;     // if true, do not report REL_WHEEL from Z
    uint16_t report_threshold_x; // min |X| to report after processing
    uint16_t report_threshold_y; // min |Y| to report after processing
    bool disable_press;     // if true, do not report BTN_MIDDLE
    uint16_t middle_hold_release_ms; // inactivity timeout for auto middle hold
};

struct mlx90393_data {
    struct k_work_delayable work;
    const struct device *dev;
    int16_t baseline_x;
    int16_t baseline_y; 
    int16_t baseline_z;
    bool calibrated;
    uint32_t calibration_count;
    int32_t sum_x;
    int32_t sum_y;
    int32_t sum_z;
    bool measuring; // two-phase non-blocking state
    bool pressed;   // Z-press detected state
    bool x_active;  // XY Schmitt gating state
    bool y_active;
    bool auto_middle_active; // auto-hold middle when moving without press
    struct k_work_delayable middle_release_work;
};

static void mlx90393_middle_release_work(struct k_work *work) {
    struct k_work_delayable *dwork = k_work_delayable_from_work(work);
    struct mlx90393_data *data = CONTAINER_OF(dwork, struct mlx90393_data, middle_release_work);
    const struct device *dev = data->dev;
    const struct mlx90393_config *config = dev->config;
    if (data->auto_middle_active && !data->pressed) {
        if (!config->disable_press) {
            input_report_key(dev, INPUT_BTN_2, 0, true, K_FOREVER);
        }
        data->auto_middle_active = false;
        LOG_DBG("Auto middle released after inactivity");
    }
}

// Simple I2C write helper based on Arduino Wire.beginTransmission/write/endTransmission
static int mlx90393_write(const struct device *dev, const uint8_t *data, size_t len) {
    const struct mlx90393_config *config = dev->config;
    return i2c_write_dt(&config->i2c, data, len);
}

// Simple I2C read helper based on Arduino Wire.requestFrom/read
static int mlx90393_read(const struct device *dev, uint8_t *data, size_t len) {
    const struct mlx90393_config *config = dev->config;
    return i2c_read_dt(&config->i2c, data, len);
}

static void mlx90393_work_handler(struct k_work *work) {
    struct k_work_delayable *dwork = k_work_delayable_from_work(work);
    struct mlx90393_data *data = CONTAINER_OF(dwork, struct mlx90393_data, work);
    const struct device *dev = data->dev;
    const struct mlx90393_config *config = dev->config;
    
    uint8_t cmd;
    uint8_t read_data[7];
    int ret;
    int16_t x, y, z;

    // Two-phase non-blocking measurement: start -> delayed read
    if (!data->measuring) {
        // Phase 1: Start single measurement mode, ZYX enabled (Arduino: Wire.write(0x3E))
        cmd = MLX90393_CMD_START_SINGLE_ZYX;
        ret = mlx90393_write(dev, &cmd, 1);
        if (ret < 0) {
            LOG_ERR("Failed to start measurement: %d", ret);
            goto reschedule_poll;
        }

        // Optional: Read status byte (Arduino: Wire.requestFrom(Addr, 1))
        ret = mlx90393_read(dev, read_data, 1);
        if (ret < 0) {
            LOG_WRN("Failed to read start status: %d", ret);
            // continue anyway; schedule read after conversion time
        }

        data->measuring = true;
        k_work_reschedule(&data->work, K_MSEC(config->conv_delay_ms));
        return;
    }

    // Phase 2: Read measurement after conversion time
    cmd = MLX90393_CMD_READ_MEAS_ZYX;
    ret = mlx90393_write(dev, &cmd, 1);
    if (ret < 0) {
        LOG_ERR("Failed to send read command: %d", ret);
        goto reschedule_poll;
    }
    // Read 7 bytes of data (status + XYZ)
    ret = mlx90393_read(dev, read_data, 7);
    if (ret < 0) {
        LOG_ERR("Failed to read measurement data: %d", ret);
        goto reschedule_poll;
    }
    // Convert the data (big endian MSB:LSB for each axis)
    x = (int16_t)sys_get_be16(&read_data[1]);
    y = (int16_t)sys_get_be16(&read_data[3]);
    z = (int16_t)sys_get_be16(&read_data[5]);
    
    // Auto-calibration: collect baseline for first 50 readings
    if (!data->calibrated) {
        data->sum_x += x;
        data->sum_y += y; 
        data->sum_z += z;
        data->calibration_count++;
        
        // Show calibration progress every 10 readings
        if ((data->calibration_count % 10) == 0) {
            LOG_INF("Calibration %d/50 - Current: X:%d Y:%d Z:%d", 
                    data->calibration_count, x, y, z);
        }
        
        if (data->calibration_count >= 50) {
            data->baseline_x = data->sum_x / 50;
            data->baseline_y = data->sum_y / 50;
            data->baseline_z = data->sum_z / 50;
            data->calibrated = true;
            LOG_INF("*** Calibration COMPLETE! Baseline: X=%d Y=%d Z=%d ***", 
                    data->baseline_x, data->baseline_y, data->baseline_z);
        }
        goto reschedule_poll; // Skip input during calibration
    }
    
    // Calculate relative movement from baseline
    int16_t rel_x = x - data->baseline_x;
    int16_t rel_y = y - data->baseline_y;
    int16_t rel_z = z - data->baseline_z;
    int16_t rel_z_raw = rel_z; // preserve for press detection before scaling
    
    // Apply XY Schmitt gating with hysteresis around deadzone
    int absx = abs(rel_x);
    int absy = abs(rel_y);
    int off_thr_x = (int)config->deadzone_x - (int)config->x_hysteresis;
    int off_thr_y = (int)config->deadzone_y - (int)config->y_hysteresis;
    if (off_thr_x < 0) off_thr_x = 0;
    if (off_thr_y < 0) off_thr_y = 0;

    if (!data->x_active) {
        if (absx >= (int)config->deadzone_x) {
            data->x_active = true;
        }
    } else {
        if (absx <= off_thr_x) {
            data->x_active = false;
        }
    }

    if (!data->y_active) {
        if (absy >= (int)config->deadzone_y) {
            data->y_active = true;
        }
    } else {
        if (absy <= off_thr_y) {
            data->y_active = false;
        }
    }

    if (!data->x_active) rel_x = 0;
    if (!data->y_active) rel_y = 0;
    // Keep Z simple deadzone
    if (abs(rel_z) < (int)config->deadzone_z) rel_z = 0;
    
    // Scale down sensitivity based on DT scale_* divisors
    if (config->scale_x > 1) { rel_x /= (int)config->scale_x; }
    if (config->scale_y > 1) { rel_y /= (int)config->scale_y; }
    if (config->scale_z > 1) { rel_z /= (int)config->scale_z; }
    
    // Apply per-axis minimal report threshold after scaling
    if (abs(rel_x) < (int)config->report_threshold_x) rel_x = 0;
    if (abs(rel_y) < (int)config->report_threshold_y) rel_y = 0;

    // Detailed per-cycle values as debug to reduce log volume
    LOG_DBG("Raw: X:%d Y:%d Z:%d | Baseline: X:%d Y:%d Z:%d | Rel: X:%d Y:%d Z:%d", 
            x, y, z, data->baseline_x, data->baseline_y, data->baseline_z, rel_x, rel_y, rel_z);
    
    // Z-press threshold/hysteresis detection (button state)
    bool prev_pressed = data->pressed;
    int zmag = abs(rel_z_raw);
    if (!data->pressed) {
        if (zmag >= (int)config->z_press_threshold) {
            data->pressed = true;
        }
    } else {
        if (zmag <= (int)config->z_press_threshold - (int)config->z_hysteresis) {
            data->pressed = false;
        }
    }

    if (data->pressed != prev_pressed) {
        if (!config->disable_press) {
            input_report_key(dev, INPUT_BTN_2, data->pressed ? 1 : 0, true, K_FOREVER);
        }
        // Also toggle Left Shift modifier at the HID level
        if (data->pressed) {
            zmk_hid_register_mod(MOD_LSFT);
        } else {
            zmk_hid_unregister_mod(MOD_LSFT);
        }
        LOG_INF("Button %s (rel_z_raw=%d, thr=%u, hyst=%u)%s — Shift %s",
                data->pressed ? "DOWN" : "UP", rel_z_raw,
                config->z_press_threshold, config->z_hysteresis,
                config->disable_press ? " [middle-suppressed]" : "",
                data->pressed ? "ON" : "OFF");
    }

    // Generate input events only if there's actual movement
    bool movement_detected = false;
    if (rel_x != 0) {
        input_report_rel(dev, INPUT_REL_X, rel_x, true, K_FOREVER);
        movement_detected = true;
    }
    if (rel_y != 0) {
        input_report_rel(dev, INPUT_REL_Y, rel_y, true, K_FOREVER);
        movement_detected = true;
    }
    if (!config->disable_wheel && rel_z != 0) {
        input_report_rel(dev, INPUT_REL_WHEEL, rel_z, true, K_FOREVER);
        LOG_INF("### REL_WHEEL reported from Z: %d", rel_z);
        movement_detected = true;
    }
    
    // Auto-hold middle button when XY movement occurs without Z press
    if ((rel_x != 0 || rel_y != 0) && !data->pressed && config->middle_hold_release_ms > 0) {
        if (!data->auto_middle_active) {
            if (!config->disable_press) {
                input_report_key(dev, INPUT_BTN_2, 1, true, K_FOREVER);
            }
            data->auto_middle_active = true;
            LOG_DBG("Auto middle engaged on XY movement");
        }
        k_work_reschedule(&data->middle_release_work, K_MSEC(config->middle_hold_release_ms));
    }

    if (movement_detected) {
        LOG_INF(">>> INPUT GENERATED: X:%d Y:%d Z:%d", rel_x, rel_y, rel_z);
    }

reschedule_poll:
    data->measuring = false;
    k_work_reschedule(&data->work, K_MSEC(config->polling_interval_ms));
}

static int mlx90393_init(const struct device *dev) {
    const struct mlx90393_config *config = dev->config;
    struct mlx90393_data *data = dev->data;
    uint8_t reg_config[4];
    uint8_t status;
    int ret;

    if (!device_is_ready(config->i2c.bus)) {
        LOG_ERR("I2C bus not ready");
        return -ENODEV;
    }

    LOG_INF("Initializing MLX90393 at address 0x%02X", config->i2c.addr);
    LOG_INF("Config: disable_wheel=%d disable_press=%d rpt_thr(x,y)=(%u,%u)",
            config->disable_wheel, config->disable_press,
            config->report_threshold_x, config->report_threshold_y);

    // Arduino initialization sequence
    // First register write: Wire.write(0x60); Wire.write(0x00); Wire.write(0x5C); Wire.write(0x00);
    reg_config[0] = 0x60;  // Write register command
    reg_config[1] = 0x00;  // AH = 0x00, BIST disabled
    reg_config[2] = 0x5C;  // AL = 0x5C, Hall plate spinning rate = DEFAULT, GAIN_SEL = 5
    reg_config[3] = 0x00;  // Select address register, (0x00 << 2)
    
    ret = mlx90393_write(dev, reg_config, 4);
    if (ret < 0) {
        LOG_ERR("Failed to write first register config: %d", ret);
        return ret;
    }
    
    // Read status (Arduino: Wire.requestFrom(Addr, 1))
    ret = mlx90393_read(dev, &status, 1);
    if (ret < 0) {
        LOG_ERR("Failed to read first config status: %d", ret);
        return ret;
    }
    LOG_INF("First config status: 0x%02x", status);

    // Second register write: Wire.write(0x60); Wire.write(0x02); Wire.write(0xB4); Wire.write(0x08);
    reg_config[0] = 0x60;  // Write register command
    reg_config[1] = 0x02;  // AH = 0x02
    reg_config[2] = 0xB4;  // AL = 0xB4, RES for magnetic measurement = 0
    reg_config[3] = 0x08;  // Select address register, (0x02 << 2)
    
    ret = mlx90393_write(dev, reg_config, 4);
    if (ret < 0) {
        LOG_ERR("Failed to write second register config: %d", ret);
        return ret;
    }
    
    // Read status
    ret = mlx90393_read(dev, &status, 1);
    if (ret < 0) {
        LOG_ERR("Failed to read second config status: %d", ret);
        return ret;
    }
    LOG_INF("Second config status: 0x%02x", status);
    
    // Wait 300ms (Arduino: delay(300))
    k_msleep(300);

    // Initialize data structure
    data->dev = dev;
    data->baseline_x = 0;
    data->baseline_y = 0;
    data->baseline_z = 0;
    data->calibrated = false;
    data->calibration_count = 0;
    data->sum_x = 0;
    data->sum_y = 0;
    data->sum_z = 0;
    data->measuring = false;
    data->pressed = false;
    data->x_active = false;
    data->y_active = false;
    data->auto_middle_active = false;

    // Initialize work
    k_work_init_delayable(&data->work, mlx90393_work_handler);
    k_work_init_delayable(&data->middle_release_work, mlx90393_middle_release_work);

    // Start periodic reading
    k_work_schedule(&data->work, K_MSEC(config->polling_interval_ms));

    LOG_INF("MLX90393 input driver initialized successfully");
    return 0;
}

#define MLX90393_INST(n)                                                                          \
    static const struct mlx90393_config mlx90393_config_##n = {                                  \
        .i2c = I2C_DT_SPEC_INST_GET(n),                                                          \
        .polling_interval_ms = DT_INST_PROP_OR(n, polling_interval_ms, 10),                      \
        .deadzone_x = DT_INST_PROP_OR(n, deadzone_x, 3),                                         \
        .deadzone_y = DT_INST_PROP_OR(n, deadzone_y, 3),                                         \
        .deadzone_z = DT_INST_PROP_OR(n, deadzone_z, 5),                                         \
        .z_press_threshold = DT_INST_PROP_OR(n, z_press_threshold, 50),                           \
        .z_hysteresis = DT_INST_PROP_OR(n, z_hysteresis, 10),                                     \
        .conv_delay_ms = DT_INST_PROP_OR(n, conv_delay_ms, 100),                                  \
        .scale_x = DT_INST_PROP_OR(n, scale_x, 4),                                                \
        .scale_y = DT_INST_PROP_OR(n, scale_y, 4),                                                \
        .scale_z = DT_INST_PROP_OR(n, scale_z, 4),                                                \
        .x_hysteresis = DT_INST_PROP_OR(n, x_hysteresis, 0),                                      \
        .y_hysteresis = DT_INST_PROP_OR(n, y_hysteresis, 0),                                      \
        .disable_wheel = DT_PROP(DT_DRV_INST(n), disable_wheel),                                 \
        .report_threshold_x = DT_INST_PROP_OR(n, report_threshold_x, 1),                          \
        .report_threshold_y = DT_INST_PROP_OR(n, report_threshold_y, 1),                          \
        .disable_press = DT_PROP(DT_DRV_INST(n), disable_press),                                  \
        .middle_hold_release_ms = DT_INST_PROP_OR(n, middle_hold_release_ms, 200),                \
    };                                                                                            \
                                                                                                  \
    static struct mlx90393_data mlx90393_data_##n;                                               \
                                                                                                  \
    DEVICE_DT_INST_DEFINE(n, mlx90393_init, NULL, &mlx90393_data_##n, &mlx90393_config_##n,     \
                          POST_KERNEL, CONFIG_ZMK_INPUT_MLX90393_INIT_PRIORITY, NULL);

DT_INST_FOREACH_STATUS_OKAY(MLX90393_INST)
