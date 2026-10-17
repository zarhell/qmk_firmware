#pragma once

enum custom_keycodes {
    LLOCK = SAFE_RANGE,

    WIN_SWAP,

    // Doble toque: Super izq. -> Ctrl izq.; MO(1) izq. -> Alt izq.; MO(1) der. -> capa 3
    GUI_CTL,
    MO1_ALT,
    MO1_MS,

    // Mouse virtual: 8 direcciones (un toque = lento, doble toque = rapido)
    MV_NW, MV_N, MV_NE, MV_W, MV_E, MV_SW, MV_S, MV_SE,
};
