# Task Completion Checklist

## Mandatory Steps After Any Code Changes

### 1. Build Verification (CRITICAL)
**ALWAYS run the build verification after any implementation or modification:**

```bash
export ZMK_CONFIG=zmk-config-MKB2
just init
XDG_RUNTIME_DIR=/tmp just build MKB_L_MODULE_RZT
```

**Important Notes:**
- Build may take several minutes to complete
- Wait for the build to finish completely before determining success
- If build fails, fix issues and retry until it passes
- No commits should be made with failing builds

### 2. Code Quality Checks
- Follow Zephyr coding conventions
- Ensure proper error handling
- Use appropriate log levels
- Maintain consistent naming conventions

### 3. Documentation Updates
- Update README.md if new features are added
- Update device tree binding documentation if properties change
- Update Kconfig help text if configuration options change

### 4. ZMK/Zephyr Compliance
Before making ANY implementation changes, MUST:
1. Consult ZMK repository expert via Deepwiki MCP server (`zmkfirmware/zmk`)
2. Consult Zephyr repository expert via Deepwiki MCP server (`zephyrproject-rtos/zephyr`) if needed
3. Validate implementation strategy with experts
4. Only proceed after expert consultation

### 5. Branch Strategy
- No breaking changes without bumping branch name
- Current stable branch: `v1`
- Breaking changes require new branch: `v2`
- Non-breaking changes: create branches from `v1` with prefix `v1-`

### 6. Final Verification
- Ensure no secrets or sensitive data in code
- Verify license headers are present
- Test configuration works in target environment (if possible)