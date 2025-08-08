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
#include <stdlib.h>

LOG_MODULE_REGISTER(input_mlx90393, CONFIG_ZMK_INPUT_MLX90393_LOG_LEVEL);

// MLX90393 I2C Address is 0x0C (from Arduino sample)
#define MLX90393_ADDR 0x0C

struct mlx90393_config {
    struct i2c_dt_spec i2c;
    uint32_t polling_interval_ms;
};

struct mlx90393_data {
    struct k_work_delayable work;
    const struct device *dev;
    int16_t baseline_x;
    int16_t baseline_y; 
    int16_t baseline_z;
    int16_t last_x;
    int16_t last_y;
    int16_t last_z;
    bool calibrated;
    uint32_t calibration_count;
    int32_t sum_x;
    int32_t sum_y;
    int32_t sum_z;
};

// Simple I2C write helper based on Arduino Wire.beginTransmission/write/endTransmission
static int mlx90393_write(const struct device *dev, uint8_t *data, size_t len) {
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

    // Start single measurement mode, ZYX enabled (Arduino: Wire.write(0x3E))
    cmd = 0x3E;
    ret = mlx90393_write(dev, &cmd, 1);
    if (ret < 0) {
        LOG_ERR("Failed to start measurement: %d", ret);
        goto reschedule;
    }
    
    // Read status byte (Arduino: Wire.requestFrom(Addr, 1))
    ret = mlx90393_read(dev, read_data, 1);
    if (ret < 0) {
        LOG_ERR("Failed to read start status: %d", ret);
        goto reschedule;
    }
    
    // Wait for measurement (Arduino: delay(100))
    k_msleep(100);
    
    // Send read measurement command (Arduino: Wire.write(0x4E))
    cmd = 0x4E;
    ret = mlx90393_write(dev, &cmd, 1);
    if (ret < 0) {
        LOG_ERR("Failed to send read command: %d", ret);
        goto reschedule;
    }
    
    // Read 7 bytes of data (Arduino: Wire.requestFrom(Addr, 7))
    // status, xMag msb, xMag lsb, yMag msb, yMag lsb, zMag msb, zMag lsb
    ret = mlx90393_read(dev, read_data, 7);
    if (ret < 0) {
        LOG_ERR("Failed to read measurement data: %d", ret);
        goto reschedule;
    }
    
    // Convert the data (Arduino: int xMag = data[1] * 256 + data[2])
    x = (int16_t)(read_data[1] * 256 + read_data[2]);
    y = (int16_t)(read_data[3] * 256 + read_data[4]);
    z = (int16_t)(read_data[5] * 256 + read_data[6]);
    
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
        goto reschedule; // Skip input during calibration
    }
    
    // Calculate relative movement from baseline
    int16_t rel_x = x - data->baseline_x;
    int16_t rel_y = y - data->baseline_y;
    int16_t rel_z = z - data->baseline_z;
    
    // Apply deadzone (ignore small movements)
    const int16_t deadzone = 5;
    if (abs(rel_x) < deadzone) rel_x = 0;
    if (abs(rel_y) < deadzone) rel_y = 0;
    if (abs(rel_z) < deadzone) rel_z = 0;
    
    // Scale down sensitivity (divide by 4 for gentler movement)
    rel_x /= 4;
    rel_y /= 4;
    rel_z /= 4;
    
    // Always show sensor values (even at INFO level for debugging)
    LOG_INF("Sensor values - Raw: X:%d Y:%d Z:%d, Baseline: X:%d Y:%d Z:%d, Relative: X:%d Y:%d Z:%d", 
            x, y, z, data->baseline_x, data->baseline_y, data->baseline_z, rel_x, rel_y, rel_z);
    
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
    if (rel_z != 0) {
        input_report_rel(dev, INPUT_REL_WHEEL, rel_z, true, K_FOREVER);
        movement_detected = true;
    }
    
    if (movement_detected) {
        LOG_INF(">>> INPUT GENERATED: X:%d Y:%d Z:%d", rel_x, rel_y, rel_z);
    }

reschedule:
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
    data->last_x = 0;
    data->last_y = 0;
    data->last_z = 0;
    data->calibrated = false;
    data->calibration_count = 0;
    data->sum_x = 0;
    data->sum_y = 0;
    data->sum_z = 0;

    // Initialize work
    k_work_init_delayable(&data->work, mlx90393_work_handler);

    // Start periodic reading
    k_work_schedule(&data->work, K_MSEC(config->polling_interval_ms));

    LOG_INF("MLX90393 input driver initialized successfully");
    return 0;
}

#define MLX90393_INST(n)                                                                          \
    static const struct mlx90393_config mlx90393_config_##n = {                                  \
        .i2c = I2C_DT_SPEC_INST_GET(n),                                                          \
        .polling_interval_ms = DT_INST_PROP_OR(n, polling_interval_ms, 10),                      \
    };                                                                                            \
                                                                                                  \
    static struct mlx90393_data mlx90393_data_##n;                                               \
                                                                                                  \
    DEVICE_DT_INST_DEFINE(n, mlx90393_init, NULL, &mlx90393_data_##n, &mlx90393_config_##n,     \
                          POST_KERNEL, CONFIG_ZMK_INPUT_MLX90393_INIT_PRIORITY, NULL);

DT_INST_FOREACH_STATUS_OKAY(MLX90393_INST)