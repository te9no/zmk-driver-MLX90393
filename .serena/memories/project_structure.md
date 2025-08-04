# Project Structure and Components

## Root Level Files
- **CMakeLists.txt**: Root build configuration, conditionally includes drivers subdirectory
- **Kconfig**: Configuration system entry point, defines CONFIG_ZMK_INPUT_MLX90393 options
- **README.md**: Comprehensive documentation in Japanese with usage examples
- **.gitignore**: Git ignore patterns

## Driver Implementation (`drivers/`)
- **drivers/input/input_mlx90393.c**: Main driver implementation
  - I2C communication functions
  - State detection logic (normal/pressed based on Z-axis)
  - Auto-calibration functionality
  - Behavior binding integration
  - Work queue and timer management
- **drivers/input/CMakeLists.txt**: Driver-specific build configuration
- **drivers/CMakeLists.txt**: Drivers subdirectory build configuration

## Device Tree Configuration (`dts/`)
- **dts/bindings/input/melexis,mlx90393-input.yaml**: Device tree binding definition
  - Property definitions and validation
  - Default values and descriptions
  - Usage examples

## Zephyr Module Integration (`zephyr/`)
- **zephyr/module.yml**: Zephyr module metadata
  - Kconfig file specification
  - Module build integration

## Key Data Structures (from code analysis)
- **mlx90393_config**: Configuration structure with I2C device spec and thresholds
- **mlx90393_data**: Runtime data including calibration state, baselines, and work structures

## Key Functions (from code analysis)
- **mlx90393_init()**: Driver initialization
- **mlx90393_work_handler()**: Main periodic work handler
- **mlx90393_read_measurement()**: Sensor data reading
- **mlx90393_calibration_timeout()**: Auto-calibration timer callback
- **mlx90393_write_cmd()**: I2C command writing
- **mlx90393_start_measurement()**: Sensor measurement initiation