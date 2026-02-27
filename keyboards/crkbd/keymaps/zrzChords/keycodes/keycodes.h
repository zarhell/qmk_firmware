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

    // --- Misc Combos ---
    EMAIL_GMAIL,
    EMAIL_WORK,
    USERNAME,
    PASSWORD,

};