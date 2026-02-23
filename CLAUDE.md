# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is a fork of [QMK Firmware](https://qmk.fm/) focused on a custom **Corne (crkbd) keyboard** keymap called `zrzChords`. The main work happens in `keyboards/crkbd/keymaps/zrzChords/`.

## Build Commands

All build operations use Docker via helper scripts in `keyboards/crkbd/keymaps/zrzChords/scripts/`. Run from the repo root (`/c/Projects/qmk_firmware`):

```bash
# Build the Docker image (one-time setup)
./keyboards/crkbd/keymaps/zrzChords/scripts/build_image.sh

# Compile firmware
./keyboards/crkbd/keymaps/zrzChords/scripts/compile_crkbd.sh

# Flash firmware to keyboard (requires hardware connected)
./keyboards/crkbd/keymaps/zrzChords/scripts/flash_crkbd.sh

# Clean build artifacts
./keyboards/crkbd/keymaps/zrzChords/scripts/clean_crkbd.sh
```

The Docker image is named `qmk-corne` and built from `./docker/`. The output `.hex` file lands at the repo root as `crkbd_rev1_zrzChords.hex`.

## zrzChords Keymap Architecture

The keymap is split into focused modules:

```
keyboards/crkbd/keymaps/zrzChords/
├── keymap.c              # Layer definitions, combo_t array, LED map, matrix_scan_user
├── config.h              # Feature flags (TAPPING_TERM=150, COMBO_VARIABLE_LEN, OLED, RGB)
├── rules.mk              # Build feature toggles (COMBO_ENABLE, RGB_MATRIX, OLED, etc.)
├── keycodes/
│   └── keycodes.h        # custom_keycodes enum (LLOCK, SELWORD, GIT_*, symbol keycodes)
├── combos/
│   ├── combos.c/h        # Combo framework glue, process_combo_event dispatcher
│   ├── combos_symbols.c/h   # Symbol key combos (both base layer and numpad layer)
│   ├── combos_git.c/h       # Git command macro combos
│   ├── combos_control.c/h   # Enter, Backspace, Delete, Caps, Select Word
│   ├── combos_function.c/h  # F1–F12 combos
│   ├── combos_media.c/h     # Play/pause, volume, track combos
│   ├── combos_misc.c/h      # Email, username, password, signature macros
│   └── combos_spanish.c/h   # Spanish accented characters (tildes, ñ, ¡, ¿)
├── features/
│   ├── layer_lock.c/h    # Layer Lock (LLOCK) — locks current layer active
│   └── select_word.c/h   # Select Word (SELWORD) — word selection helper
├── handlers/
│   └── keycode_handler.c/h  # process_record_user logic; Shift+Backspace → Delete
├── rgb/
│   └── rgb_indicators.c/h   # Per-layer RGB LED map rendering (ledmap[][42][3])
├── oled/
│   └── oled_render.c/h   # OLED: master shows layer+keylog, secondary shows logo
├── init/
│   └── init_user.c/h     # keyboard_post_init_user setup
└── utils/
    └── keylog.c/h        # Last-keypress logging for OLED display
```

## Key Design Patterns

### Combo system (`COMBO_VARIABLE_LEN`)
- `combo_t key_combos[]` in `keymap.c` maps combo arrays to keycodes using `COMBO()` or `COMBO_ACTION()`.
- Simple keycodes use `COMBO(array_name, KC_xxx)`.
- Complex actions (macros, strings) use `COMBO_ACTION(array_name)` and are handled in `process_combo_event()` inside the relevant `combos_*.c` file.
- Each combo group declares its key arrays as `extern const uint16_t PROGMEM name[]` in the `.h` and defines them in the `.c`.
- Adding a new combo requires: (1) add the key array, (2) add an entry to `key_combos[]` in `keymap.c`, (3) if `COMBO_ACTION`, add the enum value to `keycodes.h` and the case in `process_combo_event`.

### Layers (3 layers defined)
- Layer 0: QWERTY base
- Layer 1: Navigation + Numpad (arrow keys left, numpad both sides)
- Layer 2: Numbers + Navigation (digits 1–9,0 left; nav cluster right)

### RGB LED map
- `ledmap[][42][3]` in `keymap.c` — one entry per key position per layer, stored in `PROGMEM`.
- Color macros: `MG_CYAN`, `MG_RED`, `MG_BLUE`, `MG_PURPLE`, `MG_GREEN`, `___off___`.
- `rgb_indicators.c` maps keymap indices to physical LED indices accounting for the split layout mirror.

### Custom keycode handling flow
`process_record_user` → `handle_keycode()` in `keycode_handler.c` → calls `process_layer_lock`, `process_select_word`, then the switch for custom behavior (e.g., Shift+BSPC = DEL).
