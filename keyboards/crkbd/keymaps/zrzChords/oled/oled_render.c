#include "oled_render.h"
#include "features/layer_lock.h"
#include "oled/cat_sprites.h"

// Pantallas 128x32 en vertical (rotacion 270 -> 32x128 px).
// Master: capa, modificadores, Layer Lock. Secundaria: WPM y gato animado.

#define NUM_LAYERS 4

// ---------------------------------------------------------------------------
// Fuente 5x7 (filas de 5 bits): 0-9 y A-Z
// ---------------------------------------------------------------------------
// Fuente 5x7: solo los glifos usados. Cada glifo = 5 columnas (bit r = fila r).
static const char PROGMEM font_chars[] = "0123456789ABCEFGKLMNORSUVYZ";
static const uint8_t PROGMEM font5x7[27][5] = {
    {0x3E, 0x51, 0x49, 0x45, 0x3E}, // 0
    {0x00, 0x42, 0x7F, 0x40, 0x00}, // 1
    {0x42, 0x61, 0x51, 0x49, 0x46}, // 2
    {0x21, 0x41, 0x45, 0x4B, 0x31}, // 3
    {0x18, 0x14, 0x12, 0x7F, 0x10}, // 4
    {0x27, 0x45, 0x45, 0x45, 0x39}, // 5
    {0x3C, 0x4A, 0x49, 0x49, 0x30}, // 6
    {0x01, 0x71, 0x09, 0x05, 0x03}, // 7
    {0x36, 0x49, 0x49, 0x49, 0x36}, // 8
    {0x06, 0x49, 0x49, 0x29, 0x1E}, // 9
    {0x7E, 0x09, 0x09, 0x09, 0x7E}, // A
    {0x7F, 0x49, 0x49, 0x49, 0x36}, // B
    {0x3E, 0x41, 0x41, 0x41, 0x22}, // C
    {0x7F, 0x49, 0x49, 0x49, 0x41}, // E
    {0x7F, 0x09, 0x09, 0x09, 0x01}, // F
    {0x3E, 0x41, 0x49, 0x49, 0x7A}, // G
    {0x7F, 0x08, 0x14, 0x22, 0x41}, // K
    {0x7F, 0x40, 0x40, 0x40, 0x40}, // L
    {0x7F, 0x02, 0x0C, 0x02, 0x7F}, // M
    {0x7F, 0x04, 0x08, 0x10, 0x7F}, // N
    {0x3E, 0x41, 0x41, 0x41, 0x3E}, // O
    {0x7F, 0x09, 0x19, 0x29, 0x46}, // R
    {0x46, 0x49, 0x49, 0x49, 0x31}, // S
    {0x3F, 0x40, 0x40, 0x40, 0x3F}, // U
    {0x1F, 0x20, 0x40, 0x20, 0x1F}, // V
    {0x03, 0x04, 0x78, 0x04, 0x03}, // Y
    {0x61, 0x51, 0x49, 0x45, 0x43}, // Z
};

static const char *const layer_names[NUM_LAYERS] = {"BASE", "NAV", "FN", "MOUSE"};

// ---------------------------------------------------------------------------
// Primitivas de dibujo
// ---------------------------------------------------------------------------
static void fill_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, bool on) {
    for (uint8_t j = 0; j < h; j++) {
        for (uint8_t i = 0; i < w; i++) {
            oled_write_pixel(x + i, y + j, on);
        }
    }
}

static void frame_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, bool on) {
    for (uint8_t i = 0; i < w; i++) {
        oled_write_pixel(x + i, y, on);
        oled_write_pixel(x + i, y + h - 1, on);
    }
    for (uint8_t j = 0; j < h; j++) {
        oled_write_pixel(x, y + j, on);
        oled_write_pixel(x + w - 1, y + j, on);
    }
}

static void draw_glyph(char c, uint8_t x, uint8_t y, uint8_t sc, bool on) {
    int8_t idx = -1;
    for (uint8_t i = 0; i < sizeof(font_chars) - 1; i++) {
        if ((char)pgm_read_byte(&font_chars[i]) == c) {
            idx = i;
            break;
        }
    }
    if (idx < 0) return;
    for (uint8_t col = 0; col < 5; col++) {
        uint8_t bits = pgm_read_byte(&font5x7[idx][col]);
        for (uint8_t r = 0; r < 7; r++) {
            if ((bits >> r) & 1) {
                fill_rect(x + col * sc, y + r * sc, sc, sc, on);
            }
        }
    }
}

static uint8_t text_w(const char *s, uint8_t sc) {
    uint8_t n = 0;
    while (s[n]) n++;
    return n ? (uint8_t)(n * (5 * sc + 1) - 1) : 0;
}

static void draw_text_center(const char *s, uint8_t y, uint8_t sc, bool on) {
    uint8_t x = (32 - text_w(s, sc)) / 2;
    for (uint8_t i = 0; s[i]; i++) {
        draw_glyph(s[i], x + i * (5 * sc + 1), y, sc, on);
    }
}

static void num_to_str(uint8_t v, char *out) {
    uint8_t i = 0;
    if (v >= 100) out[i++] = '0' + v / 100;
    if (v >= 10) out[i++] = '0' + (v / 10) % 10;
    out[i++] = '0' + v % 10;
    out[i]   = 0;
}

// ---------------------------------------------------------------------------
// Master: capa + modificadores + Layer Lock
// ---------------------------------------------------------------------------
static bool master_drawn = false;
static uint8_t m_layer, m_mods;
static bool m_lock;

static bool any_layer_locked(void) {
    for (uint8_t l = 1; l < NUM_LAYERS; l++) {
        if (is_layer_locked(l)) return true;
    }
    return false;
}

static void draw_master(uint8_t layer, uint8_t mods, bool lock) {
    oled_clear();
    draw_text_center("LAYER", 1, 1, true);
    char n[2] = {'0' + layer, 0};
    draw_text_center(n, 11, 4, true);
    draw_text_center(layer_names[layer], 42, 1, true);
    for (uint8_t i = 0; i < NUM_LAYERS; i++) {
        if (i == layer) {
            fill_rect(1 + i * 8, 52, 6, 3, true);
        } else {
            frame_rect(1 + i * 8, 52, 6, 3, true);
        }
    }

    static const char mod_chars[4] = {'S', 'C', 'A', 'G'};
    static const uint8_t mx[2] = {1, 17};
    static const uint8_t my[2] = {60, 72};
    for (uint8_t i = 0; i < 4; i++) {
        uint8_t x = mx[i % 2], y = my[i / 2];
        bool act = (mods >> i) & 1;
        if (act) {
            fill_rect(x, y, 14, 10, true);
        } else {
            frame_rect(x, y, 14, 10, true);
        }
        draw_glyph(mod_chars[i], x + 4, y + 1, 1, !act);
    }

    for (uint8_t d = 2; d < 30; d += 2) oled_write_pixel(d, 86, true);

    // Recuadro LOCK: relleno con texto invertido cuando hay una capa bloqueada
    if (lock) {
        fill_rect(0, 104, 32, 22, true);
    } else {
        frame_rect(0, 104, 32, 22, true);
    }
    draw_text_center("LOCK", 111, 1, !lock);
}

static void render_master(void) {
    uint8_t layer = get_highest_layer(layer_state);
    if (layer >= NUM_LAYERS) layer = NUM_LAYERS - 1;
    uint8_t mods  = get_mods();
    uint8_t mflag = ((mods & MOD_MASK_SHIFT) ? 1 : 0) | ((mods & MOD_MASK_CTRL) ? 2 : 0) | ((mods & MOD_MASK_ALT) ? 4 : 0) | ((mods & MOD_MASK_GUI) ? 8 : 0);
    bool lock     = any_layer_locked();
    if (master_drawn && layer == m_layer && mflag == m_mods && lock == m_lock) return;
    master_drawn = true;
    m_layer      = layer;
    m_mods       = mflag;
    m_lock       = lock;
    draw_master(layer, mflag, lock);
}

// ---------------------------------------------------------------------------
// Secundaria: WPM y gato
// ---------------------------------------------------------------------------
#define CAT_Y        88
#define DASH_Y       124
#define WALK_MAX     39   // 1..39 WALK, 40..79 RUN, 80+ ZOOM
#define RUN_MAX      79
#define WAKE_MS      400
#define WAKE_MIN_S   10   // inactividad minima para estirarse al despertar
#define STAND_S      2
#define SLEEP_S      12
#define DEEP_S       25
#define WPM_BAR_MAX  140
#define WALK_FRAMES  5

static const uint16_t anim_ms[4] = {600, 200, 120, 70}; // IDLE/SLEEP, WALK, RUN, ZOOM

static bool slave_drawn = false;
static uint32_t anim_t = 0, zero_since = 0, wake_t = 0;
static uint8_t anim = 0, scroll_off = 0, prev_wpm = 0, last_wpm = 255, last_frame = 255;
static bool wake_active = false, dashes_on = false;

static void draw_wpm(uint8_t wpm) {
    fill_rect(0, 32, 32, 14, false);
    char buf[4];
    num_to_str(wpm, buf);
    draw_text_center(buf, 32, 2, true);
    fill_rect(0, 52, 32, 5, false);
    frame_rect(0, 52, 32, 5, true);
    uint8_t w = (uint8_t)(((uint16_t)(wpm > WPM_BAR_MAX ? WPM_BAR_MAX : wpm) * 28) / WPM_BAR_MAX);
    for (uint8_t i = 0; i < w; i++) oled_write_pixel(2 + i, 54, true);
}

static void draw_sprite(uint8_t f) {
    uint8_t  y0  = pgm_read_byte(&cat_meta[f].y0);
    uint8_t  h   = pgm_read_byte(&cat_meta[f].h);
    uint16_t off = pgm_read_word(&cat_meta[f].off);
    for (uint8_t y = 0; y < 32; y++) {
        uint32_t row = (y >= y0 && y < y0 + h) ? pgm_read_dword(&cat_rows[off + y - y0]) : 0;
        for (uint8_t x = 0; x < 32; x++) {
            oled_write_pixel(x, CAT_Y + y, (row >> x) & 1);
        }
    }
}

static void draw_dashes(bool on) {
    for (uint8_t x = 0; x < 32; x++) {
        oled_write_pixel(x, DASH_Y, on && (((x + scroll_off) % 8) < 5));
    }
}

static uint8_t pick_frame(uint8_t wpm, uint32_t now) {
    if (wpm > 0) {
        if (wake_active) {
            if (timer_elapsed32(wake_t) < WAKE_MS) return CAT_STRETCH;
            wake_active = false;
        }
        return CAT_WALK1 + (anim % WALK_FRAMES);
    }
    uint32_t idle = (now - zero_since) / 1000;
    if (idle < STAND_S) return CAT_IDLE_STAND;
    if (idle < SLEEP_S) return CAT_IDLE_SIT;
    if (idle < DEEP_S) return (anim & 1) ? CAT_SLEEP2 : CAT_SLEEP1;
    return CAT_SLEEP1 + (anim % 3);
}

static void render_slave(void) {
    uint32_t now = timer_read32();
    uint8_t wpm  = get_current_wpm();
    uint8_t st   = wpm == 0 ? 0 : (wpm <= WALK_MAX ? 1 : (wpm <= RUN_MAX ? 2 : 3));

    if (wpm == 0 && prev_wpm > 0) zero_since = now;
    if (wpm > 0 && prev_wpm == 0 && (now - zero_since) / 1000 >= WAKE_MIN_S) {
        wake_active = true;
        wake_t      = now;
    }
    prev_wpm = wpm;

    bool tick = false;
    if (timer_elapsed32(anim_t) >= anim_ms[st]) {
        anim_t = now;
        anim++;
        scroll_off = (scroll_off + 1 + st) % 8;
        tick       = true;
    }

    if (!slave_drawn) {
        slave_drawn = true;
        oled_clear();
        draw_text_center("ZRZ", 4, 2, true);
        for (uint8_t x = 0; x < 32; x++) oled_write_pixel(x, 24, true);
        last_wpm = last_frame = 255;
    }

    if (wpm != last_wpm) {
        last_wpm = wpm;
        draw_wpm(wpm);
    }

    uint8_t f = pick_frame(wpm, now);
    if (f != last_frame) {
        last_frame = f;
        draw_sprite(f);
    }

    if (st > 0 && (tick || !dashes_on)) {
        dashes_on = true;
        draw_dashes(true);
    } else if (st == 0 && dashes_on) {
        dashes_on = false;
        draw_dashes(false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_master();
    } else {
        render_slave();
    }
    return false;
}
