#include "keylog.h"

static char keylog_str[24] = {};

static const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ':', ' ', ' '
};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode &= 0xFF;
    }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
             record->event.key.row, record->event.key.col, keycode, name);
}

const char *get_keylog_str(void) {
    return keylog_str;
}
