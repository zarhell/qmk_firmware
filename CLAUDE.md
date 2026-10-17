# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is a fork of [QMK Firmware](https://qmk.fm/) focused on a custom **Corne (crkbd) keyboard** keymap called `zrzChords`. The main work happens in `keyboards/crkbd/keymaps/zrzChords/`.

## Build Commands

All build operations use Docker via helper scripts in `keyboards/crkbd/keymaps/zrzChords/scripts/`. Run from the repo root (`/c/Projects/qmk_firmware`):

```bash
# Build the Docker image (one-time setup)
./keyboards/crkbd/keymaps/zrzChords/scripts/build_image.sh

# Compile firmware (or `qmk compile -kb crkbd -km zrzChords` if Docker is not available)
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
├── config.h              # Feature flags (TAPPING_TERM, COMBO_TERM, DBL_TAP_MS, COMBO_VARIABLE_LEN, OLED, RGB, MV_FAST_MAX/MV_SLOW_MAX)
├── rules.mk              # Build feature toggles (COMBO_ENABLE, RGB_MATRIX, OLED, etc.) and SRC list
├── keycodes/
│   └── keycodes.h        # custom_keycodes enum (LLOCK, WIN_SWAP, GUI_CTL, MO1_ALT, MO1_MS, MV_*)
├── combos/
│   ├── combos.c/h        # Combo framework glue (get_combo_len / includes)
│   ├── combos_symbols.c/h   # Symbol combos (2- and 3-key, left hand)
│   └── combos_control.c/h   # Enter, Backspace, Delete, Space, punctuation, Caps Word (LSFT+Z+X)
├── features/
│   └── layer_lock.c/h    # Layer Lock (LLOCK) — locks current layer active
├── handlers/
│   └── keycode_handler.c/h  # process_record_user logic: Shift+Backspace → Delete, virtual mouse, double-tap keys, Esc unlock, WIN_SWAP
├── rgb/
│   └── rgb_indicators.c/h   # Per-layer RGB LED map rendering (ledmap[][42])
├── oled/
│   └── oled_render.c/h   # OLED: master shows layer+keylog, secondary shows logo/cat
├── init/
│   └── init_user.c/h     # keyboard_post_init_user setup
└── utils/
    └── keylog.c/h        # Last-keypress logging for OLED display
```

There are no accent combos: accents come from AltGr + vowel (US-International layout). `RALT_T(KC_TAB)` on the left and `KC_RALT` on the right provide AltGr on both hands.

## Key Design Patterns

### Combo system (`COMBO_VARIABLE_LEN`)
- `combo_t key_combos[]` in `keymap.c` maps combo arrays to keycodes using `COMBO()` or `COMBO_ACTION()`.
- Simple keycodes use `COMBO(array_name, KC_xxx)`.
- Complex actions use `COMBO_ACTION(array_name)` and a `process_combo_event()` handler (none currently defined).
- Each combo group declares its key arrays as `extern const uint16_t PROGMEM name[]` in the `.h` and defines them in the `.c`.
- Adding a new combo requires: (1) add the key array, (2) add an entry to `key_combos[]` in `keymap.c`.
- Some 2-key combos are subsets of 3-key combos (e.g. `W+V` inside `W+D+V`); the shorter one fires after `COMBO_TERM` if the third key does not arrive.

### Layers (4 layers defined)
- Layer 0: QWERTY base. Left thumbs: `GUI_CTL`, `MO1_ALT`, `KC_SPC`; right thumbs: `KC_ENT`, `MO1_MS`, `MO(2)`. `KC_ESC` top-left (with a Layer Lock active, Esc unlocks and returns to layer 0), `RALT_T(KC_TAB)` on the left home row.
- Layer 1: Navigation + clipboard (left; Z/X/C/V = undo/cut/copy/paste, F position = Omarchy clipboard history) and numpad (right; 0 on N).
- Layer 2: F1–F12 (left, shifted one column right, no media keys); mouse buttons, arrows, wheel, `QK_BOOT` in the top-right corner (right).
- Layer 3: Brackets and mouse buttons (left); virtual mouse (right).
- Unused keys in layers 1–3 are `XXXXXXX`; `_______` is kept only for thumbs, modifiers and layer keys so layers release correctly.

### Double-tap keys (`dtap_t` in `keycode_handler.c`)
- A double tap is tap, release, press again within `DBL_TAP_MS`; it is decided at press time, so there is no added latency.
- `GUI_CTL` (left outer thumb): tap/hold = Super; double-tap and hold = left Ctrl.
- `MO1_ALT` (left middle thumb): tap/hold = layer 1 (Layer Lock aware); double-tap and hold = left Alt.
- `MO1_MS` (right middle thumb): tap/hold = layer 1 (Layer Lock aware); double-tap and hold = layer 3.

### Caps Word
- The `LSFT + Z + X` combo (`CW_TOGG`) toggles Caps Word; only the left Shift can trigger it. `caps_word_press_user()` in `keymap.c` keeps it on for A–Z, digits, `-`, `_`, Backspace/Delete and the custom layer/mod keys. Omarchy maps `KC_CAPS` to Compose (`compose:caps`), so Caps Lock is not used.

### Virtual mouse (layer 3, right hand)
- `U I O / J K L / M , .` move the pointer in 8 directions (`MV_NW`…`MV_SE`); one tap held = slow, double-tap held = fast.
- `mouse_virtual()` sets `mk_max_speed` (`MV_FAST_MAX` / `MV_SLOW_MAX` in `config.h`, tuned for `MOUSEKEY_INTERVAL 8`) and uses `MS_ACL2` (fast) or `MS_ACL0` (slow) plus the direction mouse keys. Movement is relative; there is no absolute positioning.

### RGB LED map
- `ledmap[][42]` in `keymap.c` — one entry per key position for layers 1–3, stored in `PROGMEM` as palette indices.
- Color macros: `MG_CYAN`, `MG_RED`, `MG_BLUE`, `MG_PURPLE`, `___off___` (palette in `rgb_indicators.c`).
- With a Layer Lock active the underglow background blinks white.
- `rgb_indicators.c` maps keymap indices to physical LED indices accounting for the split layout mirror.

### Custom keycode handling flow
`process_record_user` → `handle_keycode()` in `keycode_handler.c` → `process_layer_lock`, then the `MV_*` range check, then the switch for custom behavior (Shift+BSPC = DEL, Esc unlocks Layer Lock, double-tap keys, `WIN_SWAP`).
