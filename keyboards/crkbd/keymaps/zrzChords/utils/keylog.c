#include "keylog.h"

static char keylog_str[12] = {};

static const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ':', ' ', ' '
};

static const char nibble[] = "0123456789ABCDEF";

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    uint16_t kc = keycode;
    if ((kc >= QK_MOD_TAP && kc <= QK_MOD_TAP_MAX) ||
        (kc >= QK_LAYER_TAP && kc <= QK_LAYER_TAP_MAX)) {
        kc &= 0xFF;
    }
    if (kc < 60) {
        name = code_to_name[kc];
    }

    uint8_t i = 0;
    keylog_str[i++] = nibble[record->event.key.row & 0xF];
    keylog_str[i++] = 'x';
    keylog_str[i++] = nibble[record->event.key.col & 0xF];
    keylog_str[i++] = ' ';
    keylog_str[i++] = 'k';
    keylog_str[i++] = nibble[(kc >> 4) & 0xF];
    keylog_str[i++] = nibble[kc & 0xF];
    keylog_str[i++] = ' ';
    keylog_str[i++] = name;
    keylog_str[i++] = '\0';
}

const char *get_keylog_str(void) {
    return keylog_str;
}
