#include "combos_control.h"

const uint16_t PROGMEM left_enter[]    = { KC_B,  LT(2, KC_SPC),   COMBO_END };  // B+SPC      → Enter
const uint16_t PROGMEM left_bspc[]     = { KC_G,  LT(2, KC_SPC),   COMBO_END };  // G+SPC      → Bspc
const uint16_t PROGMEM t_SPC_DEL[]     = { KC_T,  LT(2, KC_SPC),   COMBO_END };  // T+SPC      → Del
const uint16_t PROGMEM n_ENT_spc[]     = { KC_N,  LCTL_T(KC_ENT),  COMBO_END };  // N+Enter    → Spc
const uint16_t PROGMEM z_x_lsft_caps[] = { KC_Z,  KC_X, SFT_T(KC_SCLN), COMBO_END }; // Z+X+Shift → Caps
