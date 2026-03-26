#pragma once

#include "quantum.h"
#include "keycodes/keycodes.h"

extern const uint16_t PROGMEM sel_word_combo[];   // E+T → SELWORD

extern const uint16_t PROGMEM left_enter[];
extern const uint16_t PROGMEM left_bspc[];
extern const uint16_t PROGMEM t_SPC_DEL[];
extern const uint16_t PROGMEM n_ENT_spc[];
extern const uint16_t PROGMEM caps_combo[];       // LSFT+Z+X → CapsLock
extern const uint16_t PROGMEM app_menu_combo[];

// --- Puntuación mano izquierda ---
extern const uint16_t PROGMEM left_comma[];  // S+X → ,
extern const uint16_t PROGMEM left_dot[];    // C+D → .
extern const uint16_t PROGMEM left_semi[];   // F+V → ;
// left_quote movido a combos_symbols.h (E+R → ')
