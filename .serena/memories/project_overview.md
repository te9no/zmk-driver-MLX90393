# ZMK MLX90393 Magnetic Sensor Driver Module

## Project Purpose
This is a ZMK (Zephyr Mechanical Keyboard) firmware module providing an input driver for the MLX90393 3-axis magnetic sensor. The driver reads magnetic field data via I2C and generates mouse input events based on Z-axis threshold detection, supporting two states (normal/pressed) with different behavior bindings.

## Key Features
- **I2C Communication**: Communicates with MLX90393 sensor over I2C
- **Dual State Detection**: Z-axis threshold-based normal/pressed state detection
- **Hysteresis Support**: Prevents state oscillation with configurable hysteresis
- **Auto-calibration**: Automatic baseline calibration after 30 seconds of inactivity
- **Deadzone Filtering**: Filters small movements on all axes
- **Behavior Binding System**: State-dependent behavior binding for different keyboard actions

## Architecture
- **Main Driver**: `drivers/input/input_mlx90393.c` - Core driver implementation
- **Device Tree Binding**: `dts/bindings/input/melexis,mlx90393-input.yaml` - Configuration schema
- **Build System**: Zephyr module with CMakeLists.txt and Kconfig integration
- **Module Definition**: `zephyr/module.yml` - Zephyr module metadata

## Target Platform
- **Framework**: Zephyr RTOS (underlying ZMK)
- **Communication**: I2C bus
- **Input System**: Zephyr input subsystem integration
- **Build System**: Zephyr/CMake based