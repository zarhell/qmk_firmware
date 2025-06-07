#include "quantum.h"
#include "rgb_indicators.h"

extern const uint8_t PROGMEM ledmap[][42][3];

static void set_led_color_for_key(uint8_t layer, uint8_t keyIndex, uint8_t ledIndex, uint8_t led_min, uint8_t led_max){
    uint8_t r = pgm_read_byte(&ledmap[layer][keyIndex][0]);
    uint8_t g = pgm_read_byte(&ledmap[layer][keyIndex][1]);
    uint8_t b = pgm_read_byte(&ledmap[layer][keyIndex][2]);

    RGB_MATRIX_INDICATOR_SET_COLOR(ledIndex, r, g, b);
}

uint8_t ledIndexForKeymapIndex(uint8_t keyIndex) {
    uint8_t row = keyIndex / 12;
    uint8_t col = keyIndex % 12;
    if (row == 3) col += 3;

    bool mirror = (col >= 6);
    if (mirror) {
        row += 4;
        col = 5 - (col - 6);
    }

    return g_led_config.matrix_co[row][col];
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layerNum = get_highest_layer(layer_state);
    if (layerNum == 0) return false;

    for (uint8_t keyIndex = 0; keyIndex < 42; keyIndex++) {
        uint8_t ledIndex = ledIndexForKeymapIndex(keyIndex);
        if (ledIndex >= led_min && ledIndex <= led_max) {
            set_led_color_for_key(layerNum, keyIndex, ledIndex, led_min, led_max);
        }
    }

    return true;
}
