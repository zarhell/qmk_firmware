#include "combos_control.h"

// --- Combos con Space (KC_SPC puro en Layer 0 thumb izq. 3) ---
const uint16_t PROGMEM left_enter[]     = { KC_B,  KC_SPC,          COMBO_END };  // B+SPC       → Enter
const uint16_t PROGMEM left_bspc[]      = { LALT_T(KC_G),  KC_SPC,  COMBO_END };  // G+SPC       → Bspc
const uint16_t PROGMEM t_SPC_DEL[]      = { KC_T,  KC_SPC,          COMBO_END };  // T+SPC       → Del
const uint16_t PROGMEM n_ENT_spc[]      = { KC_N,  RCTL_T(KC_ENT),  COMBO_END };  // N+Enter     → Spc
const uint16_t PROGMEM app_menu_combo[] = { KC_M,  KC_N,            COMBO_END };  // M+N         → Context menu

// --- CapsLock: LSFT+Z+X ---
// Lógica: Shift + dos teclas bottom-left es intuitivo (Shift = mayúsculas → CapsLock).
// left_comma={Z,X} es subconjunto 2-key; QMK prioriza el 3-key si las tres
// se presionan dentro de COMBO_TERM (35ms). Resto de combos con Z/X usan ESC,D,R,C — sin conflicto.
const uint16_t PROGMEM caps_combo[]     = { KC_LSFT, KC_Z, KC_X,    COMBO_END };  // LSFT+Z+X   → CapsLock

// --- Puntuación: combos de dos teclas en la mano izquierda ---
// : y " se obtienen con Shift sostenido + el mismo combo (; y ')
const uint16_t PROGMEM left_comma[]     = { KC_Z,  KC_X,            COMBO_END };  // Z+X         → ,
const uint16_t PROGMEM left_dot[]       = { KC_X,  KC_C,            COMBO_END };  // X+C         → .
const uint16_t PROGMEM left_semi[]      = { KC_C,  KC_V,            COMBO_END };  // C+V         → ;
const uint16_t PROGMEM left_quote[]     = { KC_Q,  KC_W,            COMBO_END };  // Q+W         → '
