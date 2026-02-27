#include "quantum.h"
#include "rgb_indicators.h"

extern const uint8_t PROGMEM ledmap[][42][3];

// Color de fondo por capa — se aplica a los LEDs underglow (no cubiertos por ledmap)
// Los LEDs por-tecla son sobreescritos luego por ledmap; ___off___ los apaga.
static const uint8_t PROGMEM layer_bg[][3] = {
    { 50,   0, 232},  // Layer 0 → MG_PURPLE
    {  0,   0, 153},  // Layer 1 → MG_BLUE
    {153,   0,   0},  // Layer 2 → MG_RED
};
#define LAYER_BG_COUNT 3

static void set_led_color_for_key(uint8_t ledmapIdx, uint8_t keyIndex, uint8_t ledIndex, uint8_t led_min, uint8_t led_max) {
    uint8_t r = pgm_read_byte(&ledmap[ledmapIdx][keyIndex][0]);
    uint8_t g = pgm_read_byte(&ledmap[ledmapIdx][keyIndex][1]);
    uint8_t b = pgm_read_byte(&ledmap[ledmapIdx][keyIndex][2]);
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

    // 1. Pintar TODOS los LEDs del rango con el color de fondo de la capa.
    //    Esto enciende los LEDs underglow (los que no están en la matrix de teclas)
    //    con el color de la capa activa.
    if (layerNum < LAYER_BG_COUNT) {
        uint8_t r = pgm_read_byte(&layer_bg[layerNum][0]);
        uint8_t g = pgm_read_byte(&layer_bg[layerNum][1]);
        uint8_t b = pgm_read_byte(&layer_bg[layerNum][2]);
        for (uint8_t i = led_min; i <= led_max; i++) {
            RGB_MATRIX_INDICATOR_SET_COLOR(i, r, g, b);
        }
    }

    // 2. Overrides por tecla según la capa.
    for (uint8_t keyIndex = 0; keyIndex < 42; keyIndex++) {
        uint8_t ledIndex = ledIndexForKeymapIndex(keyIndex);
        if (ledIndex < led_min || ledIndex > led_max) continue;

        if (layerNum == 0) {
            // Layer 0: solo underglow activo — apagar todos los LEDs de tecla.
            RGB_MATRIX_INDICATOR_SET_COLOR(ledIndex, 0, 0, 0);
        } else if (layerNum <= 2) {
            // Layers 1 y 2: aplicar ledmap (___off___ apaga, colores encienden).
            set_led_color_for_key(layerNum - 1, keyIndex, ledIndex, led_min, led_max);
        }
    }

    return true;
}
