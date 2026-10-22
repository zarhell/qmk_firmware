#include "init_user.h"
#include "rgb/rgb_indicators.h"

void keyboard_post_init_user(void) {
    rgb_lock_sync_init();
    rgb_matrix_enable();
    rgb_matrix_sethsv_noeeprom(0, 0, 0);
    rgb_matrix_mode_noeeprom(1);
}
