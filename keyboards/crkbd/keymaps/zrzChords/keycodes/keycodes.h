#pragma once

enum custom_keycodes {
    // Funciones personalizadas
    LLOCK = SAFE_RANGE,

    // --- OS Toggle ---
    TOG_OS,     // Alterna entre macOS y Windows en tiempo de ejecución

    // --- Dev shortcuts (OS-aware: GUI en macOS, CTRL en Windows) ---
    DEV_COMMENT,      // Ctrl+/ o Cmd+/
    DEV_HOME,         // GUI+← (macOS) / Home (Windows)
    DEV_END,          // GUI+→ (macOS) / End (Windows)
    DEV_WORD_LEFT,    // Alt+← (macOS) / Ctrl+← (Windows)
    DEV_WORD_RIGHT,   // Alt+→ (macOS) / Ctrl+→ (Windows)
    APP_MENU,         // Shift+F10 (macOS) / KC_APP (Windows)

    // --- Acentos españoles (combos dos teclas, mano derecha) ---
    TILDE_A,    // A+Z  → á / Á
    TILDE_E,    // E+D  → é / É
    TILDE_I,    // I+K  → í / Í
    TILDE_O,    // O+L  → ó / Ó
    TILDE_U,    // U+J  → ú / Ú
    ENIE,       // N+J  → ñ / Ñ

    // --- Navegación entre ventanas (Alt+Tab Win / Cmd+Tab Mac) ---
    WIN_SWAP,     // hold = mantiene modificador vivo; tap Tab para ciclar

    // --- Símbolo: acento agudo suelto ´ ---
    ACUTE_ACC,    // D+R → ´  (Win: Alt+0180 / Mac: Opt+e, Space)

    // --- Misc Combos ---
    EMAIL_GMAIL,
    EMAIL_WORK,
    USERNAME,
    PASSWORD,

};
