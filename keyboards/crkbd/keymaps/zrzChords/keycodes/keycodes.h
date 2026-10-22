#pragma once

enum custom_keycodes {
    LLOCK = SAFE_RANGE,

    WIN_SWAP,

    // Doble toque: Super izq. -> Ctrl izq. (rapido = OSM); MO(1) izq. -> capa 3; toque = OSM AltGr; Shift izq. toque = OSM Alt; MO(1) der. solo capa 1
    GUI_CTL,
    MO1_ALT,
    MO1_MS,

    // Mouse virtual: 8 direcciones (un toque = lento, doble toque = rapido)
    MV_NW, MV_N, MV_NE, MV_W, MV_E, MV_SW, MV_S, MV_SE,
};
