#include "combos_control.h"

const uint16_t PROGMEM left_enter[]         = { KC_B,    LT(1, KC_SPC), COMBO_END };
const uint16_t PROGMEM left_bspc[]          = { KC_G,    LT(1, KC_SPC), COMBO_END };
const uint16_t PROGMEM n_ENT_spc[]          = { KC_N,    KC_ENT,        COMBO_END };
const uint16_t PROGMEM z_x_lsft_caps[]      = { KC_Z,    KC_X,          KC_LSFT, COMBO_END };
const uint16_t PROGMEM t_SPC_DEL[]          = { KC_T,    LT(1, KC_SPC), COMBO_END };
const uint16_t PROGMEM dot_slsh_rsft_app[]  = { KC_DOT,  KC_SLSH, KC_RSFT, COMBO_END };
const uint16_t PROGMEM select_word[]        = { KC_A,    KC_T,   COMBO_END };
const uint16_t PROGMEM gui_a_tab[]          = { KC_LEFT_GUI, KC_A, COMBO_END };

// — Clipboard
const uint16_t PROGMEM copy_combo[]         = { KC_C, KC_D, COMBO_END };
const uint16_t PROGMEM cut_combo[]          = { KC_X, KC_D, COMBO_END };
const uint16_t PROGMEM paste_combo[]        = { KC_V, KC_D, COMBO_END };
const uint16_t PROGMEM undo_combo[]         = { KC_Z, KC_A, COMBO_END };
