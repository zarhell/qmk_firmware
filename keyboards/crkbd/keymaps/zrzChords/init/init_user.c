#include "init_user.h"
#include "combos/combos.h"

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_sethsv_noeeprom(0, 0, 0); // Color: negro apagado (puede ser modificado)
    rgb_matrix_mode_noeeprom(1);         // Modo estático o personalizado
    define_key_combos();
}
