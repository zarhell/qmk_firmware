#include "combos_spanish.h"

// ---------------------------------------------------------------------------
// Acentos españoles — trigger: vocal + tecla de la misma columna (fila home/bot)
// Combos de columna: A+Z, E+D, I+K, O+L, U+J, N+J
// Ergonómico: tecla superior + inferior de la misma columna.
//
// Shift sostenido al activar el combo produce la versión mayúscula (Á, É…)
// gracias al handler en keycode_handler.c → send_accent().
//
// Windows: Alt(R)+numpad (no interfiere con VSCode)
// macOS  : Option+dead_key + vocal (dead_acute = Opt+e, dead_tilde = Opt+n)
// ---------------------------------------------------------------------------
const uint16_t PROGMEM bspc_a_combo[] = { KC_A,    KC_Z, COMBO_END };  // A+Z → á/Á
const uint16_t PROGMEM bspc_e_combo[] = { KC_E,    KC_D, COMBO_END };  // E+D → é/É
const uint16_t PROGMEM bspc_i_combo[] = { KC_I,    KC_K, COMBO_END };  // I+K → í/Í
const uint16_t PROGMEM bspc_o_combo[] = { KC_O,    KC_L, COMBO_END };  // O+L → ó/Ó
const uint16_t PROGMEM bspc_u_combo[] = { KC_U,    KC_J, COMBO_END };  // U+J → ú/Ú
const uint16_t PROGMEM bspc_n_combo[] = { KC_N,    KC_J, COMBO_END };  // N+J → ñ/Ñ
