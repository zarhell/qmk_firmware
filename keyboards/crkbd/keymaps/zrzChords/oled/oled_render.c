#include "oled_render.h"
#include "utils/keylog.h"

void oled_render_keylog(void) {
    oled_write(get_keylog_str(), false);
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("FN"), false);
            break;
        default:
            oled_write_ln_P(PSTR("???"), false);
            break;
    }
}

void oled_render_logo(void) {
    oled_write_P(PSTR("zrzChords"), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}


