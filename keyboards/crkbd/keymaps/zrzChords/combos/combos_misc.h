#pragma once

#include "quantum.h"
#include "keycodes/keycodes.h"

// --- Declaración de combos usados en COMBO_ACTION ---
extern const uint16_t PROGMEM email_gmail_combo[];
extern const uint16_t PROGMEM email_work_combo[];
extern const uint16_t PROGMEM username_combo[];
extern const uint16_t PROGMEM password_combo[];

// --- Definición del macro de combos misceláneos ---
#define COMBOS_MISC \
    [EMAIL_GMAIL] = COMBO_ACTION(email_gmail_combo), \
    [EMAIL_WORK]  = COMBO_ACTION(email_work_combo),  \
    [USERNAME]    = COMBO_ACTION(username_combo),    \
    [PASSWORD]    = COMBO_ACTION(password_combo)
