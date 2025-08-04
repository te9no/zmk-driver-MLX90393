# Technology Stack

## Core Technologies
- **Operating System**: Zephyr RTOS
- **Framework**: ZMK (Zephyr Mechanical Keyboard) firmware
- **Language**: C (embedded C for Zephyr)
- **Build System**: CMake + Zephyr build system
- **Hardware Interface**: I2C communication protocol
- **Sensor**: MLX90393 3-axis magnetic sensor from Melexis

## Dependencies
- **Zephyr Subsystems**: 
  - I2C driver subsystem
  - Input subsystem
  - Sensor framework
  - Work queue system
  - Timer API
- **ZMK Framework**: Behavior binding system

## Configuration Systems
- **Kconfig**: Build-time configuration system
- **Device Tree**: Hardware description and runtime configuration
- **YAML Bindings**: Device tree property validation

## Development Tools
- **west**: Zephyr's meta-tool for project management
- **CMake**: Build system generator
- **Git**: Version control
- **just**: Command runner (mentioned in CLAUDE.md for build commands)