# Code Style and Conventions

## File Structure
```
├── CMakeLists.txt              # Root build configuration
├── Kconfig                     # Configuration options entry point
├── drivers/
│   ├── input/
│   │   ├── CMakeLists.txt      # Driver-specific build config
│   │   └── input_mlx90393.c    # Main driver implementation
├── dts/bindings/input/
│   └── melexis,mlx90393-input.yaml  # Device tree binding
└── zephyr/
    └── module.yml              # Zephyr module definition
```

## Naming Conventions
- **Files**: Snake case with descriptive prefixes
  - `input_mlx90393.c` for driver files
  - `melexis,mlx90393-input.yaml` for device tree bindings
- **Functions**: Snake case with module prefix
  - `mlx90393_write_cmd()`
  - `mlx90393_read_measurement()`
- **Structs**: Snake case with module prefix
  - `mlx90393_config`
  - `mlx90393_data`
- **Config Options**: UPPERCASE with module prefix
  - `CONFIG_ZMK_INPUT_MLX90393`
  - `CONFIG_ZMK_INPUT_MLX90393_LOG_LEVEL`

## Documentation Standards
- **License Headers**: MIT license header on all files
- **YAML Documentation**: Comprehensive property descriptions in device tree bindings
- **Kconfig Help**: Detailed help text for all configuration options
- **Comments**: Japanese and English mixed documentation (README in Japanese)

## Zephyr-Specific Conventions
- **Device Tree Compatible**: Format `vendor,device-function`
- **Log Module**: `LOG_MODULE_REGISTER()` for logging
- **Init Priority**: Configurable via Kconfig
- **Work Queues**: Use `k_work_delayable` for periodic tasks
- **Timers**: Use `k_timer` for timeout functionality