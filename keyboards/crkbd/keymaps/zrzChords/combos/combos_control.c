#include "combos_control.h"

const uint16_t PROGMEM left_enter[]    = { KC_B,  LT(2, KC_SPC),   COMBO_END };  // B+SPC      → Enter
const uint16_t PROGMEM left_bspc[]     = { KC_G,  LT(2, KC_SPC),   COMBO_END };  // G+SPC      → Bspc
const uint16_t PROGMEM t_SPC_DEL[]     = { KC_T,  LT(2, KC_SPC),   COMBO_END };  // T+SPC      → Del
const uint16_t PROGMEM n_ENT_spc[]     = { KC_N,  RCTL_T(KC_ENT),  COMBO_END };  // N+Enter    → Spc
const uint16_t PROGMEM caps_combo[]    = { KC_Z,  KC_X, KC_C,       COMBO_END };  // Z+X+C      → CapsLock
const uint16_t PROGMEM app_menu_combo[] = { KC_M, KC_N,             COMBO_END };  // M+N        → Context menu
const uint16_t PROGMEM alt_tab_combo[] = { LALT_T(KC_TAB), KC_A,   COMBO_END };  // Tab+A      → Alt+Tab (hold)

// --- Puntuación: combos de dos teclas en la mano izquierda ---
// Lógica: bottom row adyacentes, sin conflicto con símbolos existentes
// : y " se obtienen con Shift+; y Shift+' respectivamente (Shift es ahora dedicado KC_LSFT)
const uint16_t PROGMEM left_comma[]  = { KC_Z, KC_X,        COMBO_END };  // Z+X → ,
const uint16_t PROGMEM left_dot[]    = { KC_X, KC_C,        COMBO_END };  // X+C → .
const uint16_t PROGMEM left_semi[]   = { KC_C, KC_V,        COMBO_END };  // C+V → ;
const uint16_t PROGMEM left_quote[]  = { KC_Q, KC_W,        COMBO_END };  // Q+W → '
