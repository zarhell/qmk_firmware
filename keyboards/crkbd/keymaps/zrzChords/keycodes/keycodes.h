#pragma once

enum custom_keycodes {
    // Funciones personalizadas
    LLOCK = SAFE_RANGE,
    SELWORD,

    // --- OS Toggle ---
    TOG_OS,     // Alterna entre macOS y Windows en tiempo de ejecución

    // --- Dev shortcuts (OS-aware: GUI en macOS, CTRL en Windows) ---
    DEV_COMMENT,      // Ctrl+/ o Cmd+/
    DEV_HOME,         // GUI+← (macOS) / Home (Windows)
    DEV_END,          // GUI+→ (macOS) / End (Windows)
    DEV_WORD_LEFT,    // Alt+← (macOS) / Ctrl+← (Windows)
    DEV_WORD_RIGHT,   // Alt+→ (macOS) / Ctrl+→ (Windows)
    APP_MENU,         // Shift+F10 (macOS) / KC_APP (Windows)

    // --- Navegación con Alt sostenido ---
    ALT_TAB_HOLD,     // Alt+Tab: mantiene Alt hasta soltar el combo

    // --- Acentos españoles (combos dos teclas, mano derecha) ---
    TILDE_A,    // A+S  → á / Á
    TILDE_E,    // E+D  → é / É
    TILDE_I,    // I+K  → í / Í
    TILDE_O,    // O+L  → ó / Ó
    TILDE_U,    // U+J  → ú / Ú
    ENIE,       // N+J  → ñ / Ñ

    // --- Misc Combos ---
    EMAIL_GMAIL,
    EMAIL_WORK,
    USERNAME,
    PASSWORD,

};
