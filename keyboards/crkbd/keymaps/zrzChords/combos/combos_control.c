#include "combos_control.h"

// --- Select Word ---
const uint16_t PROGMEM sel_word_combo[] = { KC_E, KC_T, COMBO_END };  // E+T → SELWORD

// --- Combos con Space (KC_SPC puro en Layer 0 thumb izq. 3) ---
const uint16_t PROGMEM left_enter[]     = { KC_B,  KC_SPC,          COMBO_END };  // B+SPC       → Enter
const uint16_t PROGMEM left_bspc[]      = { LALT_T(KC_G),  KC_SPC,  COMBO_END };  // G+SPC       → Bspc
const uint16_t PROGMEM t_SPC_DEL[]      = { KC_T,  KC_SPC,          COMBO_END };  // T+SPC       → Del
const uint16_t PROGMEM n_ENT_spc[]      = { KC_N,  KC_ENT,          COMBO_END };  // N+Enter     → Spc
const uint16_t PROGMEM app_menu_combo[] = { KC_M,  KC_N,            COMBO_END };  // M+N         → Context menu

// --- CapsLock: LSFT+Z+X ---
// Lógica: Shift + dos teclas bottom-left es intuitivo (Shift = mayúsculas → CapsLock).
// left_comma={Z,X} es subconjunto 2-key; QMK prioriza el 3-key si las tres
// se presionan dentro de COMBO_TERM (35ms). Resto de combos con Z/X usan ESC,D,R,C — sin conflicto.
const uint16_t PROGMEM caps_combo[]     = { KC_LSFT, KC_Z, KC_X,    COMBO_END };  // LSFT+Z+X   → CapsLock

// --- Puntuación: combos de dos teclas en la mano izquierda ---
// : y " se obtienen con Shift sostenido + el mismo combo (; y ')
// left_quote movido a combos_symbols.c (E+R)
const uint16_t PROGMEM left_comma[]     = { KC_S,  KC_C,            COMBO_END };  // S+C         → ,
const uint16_t PROGMEM left_dot[]       = { KC_D,  KC_V,            COMBO_END };  // D+V         → .
const uint16_t PROGMEM left_semi[]      = { KC_F,  KC_B,            COMBO_END };  // F+B         → ;

// --- macOS: navegación entre escritorios ---
const uint16_t PROGMEM mac_desk_right[] = { KC_Q,  KC_D,            COMBO_END };  // Q+D         → Cmd+→ (escritorio derecho)
const uint16_t PROGMEM mac_desk_left[]  = { KC_A,  KC_E,            COMBO_END };  // A+E         → Cmd+← (escritorio izquierdo)
const uint16_t PROGMEM mac_desk_up[]    = { KC_A,  KC_W,  KC_D,     COMBO_END };  // A+W+D       → Cmd+↑ (Mission Control)
