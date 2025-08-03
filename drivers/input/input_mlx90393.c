/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT melexis_mlx90393_input

#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/input/input.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/util.h>

#include <drivers/behavior.h>

LOG_MODULE_REGISTER(input_mlx90393, CONFIG_ZMK_INPUT_MLX90393_LOG_LEVEL);

/* MLX90393 I2C commands */
#define MLX90393_CMD_START_BURST   0x10
#define MLX90393_CMD_START_WAKEUP  0x11
#define MLX90393_CMD_START_SINGLE  0x3E
#define MLX90393_CMD_READ_MEASURE  0x4E
#define MLX90393_CMD_READ_REG      0x50
#define MLX90393_CMD_WRITE_REG     0x60
#define MLX90393_CMD_EXIT          0x80
#define MLX90393_CMD_MEMORY_RECALL 0xD0
#define MLX90393_CMD_MEMORY_STORE  0xE0
#define MLX90393_CMD_RESET         0xF0

/* Register addresses */
#define MLX90393_REG_CUSTOMER_ID   0x00
#define MLX90393_REG_CTRL1         0x02
#define MLX90393_REG_CTRL2         0x03
#define MLX90393_REG_CTRL3         0x04

/* Status register bits */
#define MLX90393_STATUS_DRDY       BIT(0)
#define MLX90393_STATUS_BUSY       BIT(1)
#define MLX90393_STATUS_BREAK      BIT(2)
#define MLX90393_STATUS_WOC        BIT(3)
#define MLX90393_STATUS_SMMODE     BIT(4)
#define MLX90393_STATUS_ERROR      BIT(5)
#define MLX90393_STATUS_SEP        BIT(6)
#define MLX90393_STATUS_RS         BIT(7)

struct mlx90393_config {
    struct i2c_dt_spec i2c;
    uint32_t polling_interval_ms;
    int32_t z_press_threshold;
    int32_t z_hysteresis;
    int32_t deadzone_x;
    int32_t deadzone_y;
    int32_t deadzone_z;
    int32_t movement_threshold;
    uint32_t auto_calibration_timeout_s;
    const struct device *normal_binding;
    const struct device *pressed_binding;
};

struct mlx90393_data {
    struct k_work_delayable work;
    struct k_timer calibration_timer;
    int16_t baseline_x;
    int16_t baseline_y;
    int16_t baseline_z;
    int16_t last_x;
    int16_t last_y;
    int16_t last_z;
    bool pressed_state;
    bool calibrated;
    uint32_t calibration_samples;
    int32_t calibration_sum_x;
    int32_t calibration_sum_y;
    int32_t calibration_sum_z;
};

static int mlx90393_write_cmd(const struct device *dev, uint8_t cmd) {
    const struct mlx90393_config *config = dev->config;
    uint8_t status;
    int ret;

    ret = i2c_write_read_dt(&config->i2c, &cmd, 1, &status, 1);
    if (ret < 0) {
        LOG_ERR("Failed to write command 0x%02x: %d", cmd, ret);
        return ret;
    }

    if (status & MLX90393_STATUS_ERROR) {
        LOG_ERR("MLX90393 error status: 0x%02x", status);
        return -EIO;
    }

    return 0;
}

static int mlx90393_read_measurement(const struct device *dev, int16_t *x, int16_t *y, int16_t *z) {
    const struct mlx90393_config *config = dev->config;
    uint8_t cmd = MLX90393_CMD_READ_MEASURE;
    uint8_t data[7];
    int ret;

    ret = i2c_write_read_dt(&config->i2c, &cmd, 1, data, sizeof(data));
    if (ret < 0) {
        LOG_ERR("Failed to read measurement: %d", ret);
        return ret;
    }

    if (data[0] & MLX90393_STATUS_ERROR) {
        LOG_ERR("MLX90393 measurement error: 0x%02x", data[0]);
        return -EIO;
    }

    *x = (int16_t)((data[1] << 8) | data[2]);
    *y = (int16_t)((data[3] << 8) | data[4]);
    *z = (int16_t)((data[5] << 8) | data[6]);

    return 0;
}

static int mlx90393_start_measurement(const struct device *dev) {
    return mlx90393_write_cmd(dev, MLX90393_CMD_START_SINGLE | 0x0E); // X, Y, Z + T
}

static void mlx90393_calibration_timeout(struct k_timer *timer) {
    struct mlx90393_data *data = CONTAINER_OF(timer, struct mlx90393_data, calibration_timer);
    
    if (data->calibration_samples >= 100) {
        data->baseline_x = data->calibration_sum_x / data->calibration_samples;
        data->baseline_y = data->calibration_sum_y / data->calibration_samples;
        data->baseline_z = data->calibration_sum_z / data->calibration_samples;
        data->calibrated = true;
        
        LOG_INF("Auto-calibration completed: baseline X=%d, Y=%d, Z=%d", 
                data->baseline_x, data->baseline_y, data->baseline_z);
    }
    
    data->calibration_samples = 0;
    data->calibration_sum_x = 0;
    data->calibration_sum_y = 0;
    data->calibration_sum_z = 0;
}

static void mlx90393_work_handler(struct k_work *work) {
    struct k_work_delayable *dwork = k_work_delayable_from_work(work);
    struct mlx90393_data *data = CONTAINER_OF(dwork, struct mlx90393_data, work);
    const struct device *dev = CONTAINER_OF(data, struct device, data);
    const struct mlx90393_config *config = dev->config;
    
    int16_t x, y, z;
    int ret;

    ret = mlx90393_start_measurement(dev);
    if (ret < 0) {
        goto reschedule;
    }

    k_msleep(2); // Wait for measurement to complete

    ret = mlx90393_read_measurement(dev, &x, &y, &z);
    if (ret < 0) {
        goto reschedule;
    }

    // Apply deadzone filtering
    int16_t rel_x = x - data->baseline_x;
    int16_t rel_y = y - data->baseline_y;
    int16_t rel_z = z - data->baseline_z;

    if (abs(rel_x) < config->deadzone_x) rel_x = 0;
    if (abs(rel_y) < config->deadzone_y) rel_y = 0;
    if (abs(rel_z) < config->deadzone_z) rel_z = 0;

    // Check for movement for auto-calibration
    bool movement_detected = (abs(rel_x) > config->movement_threshold ||
                             abs(rel_y) > config->movement_threshold ||
                             abs(rel_z) > config->movement_threshold);

    if (movement_detected) {
        k_timer_stop(&data->calibration_timer);
        data->calibration_samples = 0;
        data->calibration_sum_x = 0;
        data->calibration_sum_y = 0;
        data->calibration_sum_z = 0;
    } else if (!k_timer_status_get(&data->calibration_timer)) {
        // Start calibration timer if not already running
        k_timer_start(&data->calibration_timer, 
                     K_SECONDS(config->auto_calibration_timeout_s), K_NO_WAIT);
        data->calibration_samples = 0;
        data->calibration_sum_x = 0;
        data->calibration_sum_y = 0;
        data->calibration_sum_z = 0;
    } else {
        // Accumulate calibration data
        data->calibration_samples++;
        data->calibration_sum_x += x;
        data->calibration_sum_y += y;
        data->calibration_sum_z += z;
    }

    // Z-axis state detection with hysteresis
    bool new_pressed_state = data->pressed_state;
    
    if (!data->pressed_state && rel_z > config->z_press_threshold) {
        new_pressed_state = true;
    } else if (data->pressed_state && rel_z < (config->z_press_threshold - config->z_hysteresis)) {
        new_pressed_state = false;
    }

    // Generate input events only if there's movement or state change
    if (movement_detected || new_pressed_state != data->pressed_state) {
        // Select appropriate behavior binding
        const struct device *binding = new_pressed_state ? 
            config->pressed_binding : config->normal_binding;

        if (new_pressed_state != data->pressed_state) {
            LOG_DBG("State changed to %s", new_pressed_state ? "pressed" : "normal");
            data->pressed_state = new_pressed_state;
        }

        // Generate relative movement events
        if (rel_x != 0) {
            input_report_rel(dev, INPUT_REL_X, rel_x, true, K_FOREVER);
        }
        if (rel_y != 0) {
            input_report_rel(dev, INPUT_REL_Y, rel_y, true, K_FOREVER);
        }
        if (rel_z != 0) {
            input_report_rel(dev, INPUT_REL_WHEEL, rel_z, true, K_FOREVER);
        }

        // Trigger behavior binding if configured
        if (binding != NULL) {
            behavior_keymap_binding_pressed(binding, (struct zmk_behavior_binding_event){});
            behavior_keymap_binding_released(binding, (struct zmk_behavior_binding_event){});
        }
    }

    data->last_x = x;
    data->last_y = y;
    data->last_z = z;

reschedule:
    k_work_reschedule(&data->work, K_MSEC(config->polling_interval_ms));
}

static int mlx90393_init(const struct device *dev) {
    const struct mlx90393_config *config = dev->config;
    struct mlx90393_data *data = dev->data;
    int ret;

    if (!device_is_ready(config->i2c.bus)) {
        LOG_ERR("I2C bus not ready");
        return -ENODEV;
    }

    // Reset sensor
    ret = mlx90393_write_cmd(dev, MLX90393_CMD_RESET);
    if (ret < 0) {
        LOG_ERR("Failed to reset MLX90393: %d", ret);
        return ret;
    }

    k_msleep(10); // Wait for reset

    // Wake up sensor
    ret = mlx90393_write_cmd(dev, MLX90393_CMD_START_WAKEUP);
    if (ret < 0) {
        LOG_ERR("Failed to wake up MLX90393: %d", ret);
        return ret;
    }

    // Initialize data structure
    data->calibrated = false;
    data->pressed_state = false;
    data->calibration_samples = 0;
    data->calibration_sum_x = 0;
    data->calibration_sum_y = 0;
    data->calibration_sum_z = 0;

    // Initialize work and timer
    k_work_init_delayable(&data->work, mlx90393_work_handler);
    k_timer_init(&data->calibration_timer, mlx90393_calibration_timeout, NULL);

    // Start periodic reading
    k_work_schedule(&data->work, K_MSEC(config->polling_interval_ms));

    LOG_INF("MLX90393 input driver initialized");

    return 0;
}

#define MLX90393_INST(n)                                                                          \
    static const struct mlx90393_config mlx90393_config_##n = {                                  \
        .i2c = I2C_DT_SPEC_INST_GET(n),                                                          \
        .polling_interval_ms = DT_INST_PROP(n, polling_interval_ms),                             \
        .z_press_threshold = DT_INST_PROP(n, z_press_threshold),                                 \
        .z_hysteresis = DT_INST_PROP(n, z_hysteresis),                                           \
        .deadzone_x = DT_INST_PROP(n, deadzone_x),                                               \
        .deadzone_y = DT_INST_PROP(n, deadzone_y),                                               \
        .deadzone_z = DT_INST_PROP(n, deadzone_z),                                               \
        .movement_threshold = DT_INST_PROP(n, movement_threshold),                               \
        .auto_calibration_timeout_s = DT_INST_PROP(n, auto_calibration_timeout_s),               \
        .normal_binding = DEVICE_DT_GET_OR_NULL(DT_INST_PROP(n, normal_binding)),                \
        .pressed_binding = DEVICE_DT_GET_OR_NULL(DT_INST_PROP(n, pressed_binding)),              \
    };                                                                                            \
                                                                                                  \
    static struct mlx90393_data mlx90393_data_##n;                                               \
                                                                                                  \
    DEVICE_DT_INST_DEFINE(n, mlx90393_init, NULL, &mlx90393_data_##n, &mlx90393_config_##n,     \
                          POST_KERNEL, CONFIG_ZMK_INPUT_MLX90393_INIT_PRIORITY, NULL);

DT_INST_FOREACH_STATUS_OKAY(MLX90393_INST)