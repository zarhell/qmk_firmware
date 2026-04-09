#include "combos_spanish.h"

// ---------------------------------------------------------------------------
// Acentos españoles
// Combos de columna: tecla vocal + tecla adyacente en la misma mano.
//
// Shift sostenido al activar el combo produce la versión mayúscula (Á, É…)
// gracias al handler en keycode_handler.c → send_accent().
//
// Windows: Alt(R)+numpad (no interfiere con VSCode)
// macOS  : Option+dead_key + vocal (dead_acute = Opt+e, dead_tilde = Opt+n)
// ---------------------------------------------------------------------------
const uint16_t PROGMEM bspc_a_combo[] = { KC_A,    KC_W, COMBO_END };  // A+W → á/Á
const uint16_t PROGMEM bspc_e_combo[] = { KC_E,    KC_S, COMBO_END };  // E+S → é/É
const uint16_t PROGMEM bspc_i_combo[] = { KC_I,    KC_J, COMBO_END };  // I+J → í/Í
const uint16_t PROGMEM bspc_o_combo[] = { KC_O,    KC_K, COMBO_END };  // O+K → ó/Ó
const uint16_t PROGMEM bspc_u_combo[] = { KC_U,    KC_H, COMBO_END };  // U+H → ú/Ú
const uint16_t PROGMEM bspc_n_combo[] = { KC_N,    KC_J, COMBO_END };  // N+J → ñ/Ñ
