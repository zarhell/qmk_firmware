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
extern const uint16_t PROGMEM left_comma[];  // S+C → ,
extern const uint16_t PROGMEM left_dot[];    // D+V → .
extern const uint16_t PROGMEM left_semi[];   // F+B → ;
// left_quote movido a combos_symbols.h (E+R → ')

// --- macOS: navegación entre escritorios ---
extern const uint16_t PROGMEM mac_desk_right[];  // Q+D   → Cmd+→
extern const uint16_t PROGMEM mac_desk_left[];   // A+E   → Cmd+←
extern const uint16_t PROGMEM mac_desk_up[];     // A+W+D → Cmd+↑
