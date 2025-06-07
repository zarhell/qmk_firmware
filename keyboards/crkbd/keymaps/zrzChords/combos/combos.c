#include "combos.h"
#include "combos_git.h"
#include "combos_symbols.h"
#include "combos_spanish.h"
#include "combos_media.h"
#include "combos_misc.h"
#include "keycodes/keycodes.h"

// Define combos estáticos (COMBO o COMBO_ACTION con macros)
combo_t key_combos[] = {
    COMBOS_GIT,
    COMBOS_SYMBOLS,
    COMBOS_SPANISH,
    COMBOS_MEDIA,
    COMBOS_MISC
};

combo_t* key_combos_ptr = key_combos;

void define_key_combos(void) {
    // No-op; combos están definidos estáticamente.
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) return;

    switch (combo_index) {
        case TILDE_A:      SEND_STRING(SS_RALT("a")); break;
        case TILDE_E:      SEND_STRING(SS_RALT("e")); break;
        case TILDE_I:      SEND_STRING(SS_RALT("i")); break;
        case TILDE_O:      SEND_STRING(SS_RALT("o")); break;
        case TILDE_U:      SEND_STRING(SS_RALT("u")); break;
        case TILDE_N:      SEND_STRING(SS_RALT("n")); break;
        case ENIE:         SEND_STRING(SS_LALT("0241")); break; // Ñ
        case EXCLAM:       SEND_STRING(SS_RALT("1")); break;
        case QUESTION:     SEND_STRING(SS_RALT("/")); break;
        case EMAIL_GMAIL:  SEND_STRING("johan.zubieta@gmail.com"); break;
        case EMAIL_WORK:   SEND_STRING("johan.zubieta@globant.com"); break;
        case USERNAME:     SEND_STRING("jzubieta"); break;
        case PASSWORD:     SEND_STRING("Colombia234*"); break;
    }
}
