#include "combos_symbols.h"

// Nota: top-left key es LGUI_T(KC_ESC) tras el refactor de Layer 0
const uint16_t PROGMEM bracket_combo[]    = { LGUI_T(KC_ESC), KC_Q, COMBO_END };  // ESC+Q → [
const uint16_t PROGMEM curly_brace_combo[] = { LGUI_T(KC_ESC), KC_A, COMBO_END }; // ESC+A → {
const uint16_t PROGMEM paren_combo[]      = { LGUI_T(KC_ESC), KC_Z, COMBO_END };  // ESC+Z → (

// Cierre de brackets — mismo anchor ESC, tecla adyacente derecha
const uint16_t PROGMEM bracket_close_combo[] = { LGUI_T(KC_ESC), KC_W, COMBO_END };  // ESC+W → ]
const uint16_t PROGMEM curly_close_combo[]   = { LGUI_T(KC_ESC), KC_S, COMBO_END };  // ESC+S → }
const uint16_t PROGMEM paren_close_combo[]   = { LGUI_T(KC_ESC), KC_X, COMBO_END };  // ESC+X → )

const uint16_t PROGMEM left_slsh[] = { KC_X, KC_D, KC_R, COMBO_END };
const uint16_t PROGMEM left_bsls[] = { KC_W, KC_D, KC_V, COMBO_END };
const uint16_t PROGMEM left_pipe[] = { KC_E, KC_D, KC_C, COMBO_END };
const uint16_t PROGMEM left_circ[] = { KC_F, KC_E, KC_S, COMBO_END };
const uint16_t PROGMEM left_lower_than[] = { KC_E, KC_S, KC_C, COMBO_END };
const uint16_t PROGMEM left_greather_than[] = { KC_E, KC_F, KC_C, COMBO_END };
const uint16_t PROGMEM left_grv[] = { KC_R, LALT_T(KC_G), COMBO_END };
const uint16_t PROGMEM left_tild[] = { KC_Q, KC_F, COMBO_END };
const uint16_t PROGMEM left_hash[] = { KC_T, KC_R, KC_E, COMBO_END };
const uint16_t PROGMEM left_perc[] = { KC_W, KC_V, COMBO_END };
const uint16_t PROGMEM left_exlm[] = { KC_W, KC_E, KC_F, COMBO_END };
const uint16_t PROGMEM left_ques[] = { KC_S, KC_D, KC_R, COMBO_END };
const uint16_t PROGMEM left_dlr[] = { KC_X, KC_C, KC_R, COMBO_END };
const uint16_t PROGMEM left_at[] = { KC_W, KC_D, KC_F, COMBO_END };
const uint16_t PROGMEM left_ampr[] = { LALT_T(KC_G), KC_D, COMBO_END };
const uint16_t PROGMEM left_astr[] = { KC_B, KC_V, KC_C, COMBO_END };

const uint16_t PROGMEM left_eq[]   = { KC_R, KC_T,        COMBO_END };
const uint16_t PROGMEM left_min[]  = { KC_F, LALT_T(KC_G),        COMBO_END };
const uint16_t PROGMEM left_unds[] = { KC_V, KC_B,        COMBO_END };
const uint16_t PROGMEM left_plus[] = { KC_D, KC_F, LALT_T(KC_G), COMBO_END };
