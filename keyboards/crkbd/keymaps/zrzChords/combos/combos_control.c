#include "combos_control.h"

const uint16_t PROGMEM left_enter[]     = { KC_F,  KC_LALT,         COMBO_END };
const uint16_t PROGMEM left_bspc[]      = { KC_G,  KC_LALT,         COMBO_END };
const uint16_t PROGMEM t_SPC_DEL[]      = { KC_T,  KC_LALT,         COMBO_END };
const uint16_t PROGMEM n_ENT_spc[]      = { KC_N,  KC_ENT,          COMBO_END };

// Esc, Tab y Space liberados de la mano izquierda -> ahora son combos
const uint16_t PROGMEM esc_combo[]         = { KC_Q,  KC_E,     COMBO_END };
const uint16_t PROGMEM tab_combo[]         = { KC_A,  KC_D,     COMBO_END };
const uint16_t PROGMEM left_spc[]          = { KC_B,  KC_LALT,  COMBO_END };

const uint16_t PROGMEM left_comma[]     = { KC_D,  KC_V,            COMBO_END };
const uint16_t PROGMEM left_dot[]       = { KC_F,  KC_B,            COMBO_END };
const uint16_t PROGMEM left_semi[]      = { KC_E,  KC_V,            COMBO_END };
const uint16_t PROGMEM left_colon[]     = { KC_R,  KC_B,            COMBO_END };

const uint16_t PROGMEM left_apos[]         = { KC_S, KC_F, COMBO_END };
const uint16_t PROGMEM left_shift_enter[]  = { KC_Z, KC_X, COMBO_END };

// Cambiar de escritorio (equivalente al gesto de 3 dedos del touchpad)
const uint16_t PROGMEM workspace_next[]  = { KC_U, KC_I, COMBO_END };
const uint16_t PROGMEM workspace_prev[]  = { KC_H, KC_K, COMBO_END };
