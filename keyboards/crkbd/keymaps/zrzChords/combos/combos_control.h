#pragma once

#include "quantum.h"
#include "keycodes/keycodes.h"

extern const uint16_t PROGMEM left_enter[];
extern const uint16_t PROGMEM left_bspc[];
extern const uint16_t PROGMEM t_SPC_DEL[];
extern const uint16_t PROGMEM n_ENT_spc[];
extern const uint16_t PROGMEM caps_combo[];       // Z+X+C → CapsLock (reemplaza z_x_lsft_caps)
extern const uint16_t PROGMEM app_menu_combo[];
extern const uint16_t PROGMEM alt_tab_combo[];

// --- Puntuación mano izquierda ---
extern const uint16_t PROGMEM left_comma[];  // Z+X → ,
extern const uint16_t PROGMEM left_dot[];    // X+C → .
extern const uint16_t PROGMEM left_semi[];   // C+V → ;
extern const uint16_t PROGMEM left_quote[];  // Q+W → '
