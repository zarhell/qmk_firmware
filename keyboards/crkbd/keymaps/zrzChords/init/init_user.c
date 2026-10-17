#include "init_user.h"

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_sethsv_noeeprom(0, 0, 0);
    rgb_matrix_mode_noeeprom(1);
}
