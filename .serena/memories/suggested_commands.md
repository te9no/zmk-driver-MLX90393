# Essential Development Commands

## Build Commands (from CLAUDE.md)
The project uses a specific build process with just and custom configuration:

```bash
# Set ZMK configuration environment
export ZMK_CONFIG=zmk-config-MKB2

# Initialize the build environment
just init

# Build the module (example target)
XDG_RUNTIME_DIR=/tmp just build MKB_L_MODULE_RZT
```

**Important**: Build verification is MANDATORY after any implementation or modification.

## Windows-Specific Commands
Since the development environment is Windows:

```cmd
# Directory navigation
dir                     # List directory contents (equivalent to ls)
cd <path>              # Change directory
type <file>            # Display file contents (equivalent to cat)

# File operations
copy <src> <dest>      # Copy files
move <src> <dest>      # Move/rename files
del <file>             # Delete files
mkdir <dir>            # Create directory

# Git operations
git status             # Check repository status
git diff               # Show changes
git add .              # Stage changes
git commit -m "msg"    # Commit changes
```

## Development Workflow
1. Make code changes
2. Run build verification: `export ZMK_CONFIG=zmk-config-MKB2 && just init && XDG_RUNTIME_DIR=/tmp just build MKB_L_MODULE_RZT`
3. Fix any build errors and repeat until build passes
4. Commit changes only after successful build

## Debug Commands
```bash
# Enable debug logging in board configuration
CONFIG_ZMK_INPUT_MLX90393_LOG_LEVEL=4

# View Zephyr build logs
# (Specific commands depend on build output location)
```