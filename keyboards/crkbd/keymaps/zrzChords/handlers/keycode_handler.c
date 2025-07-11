#include "keycode_handler.h"
#include "features/layer_lock.h"
#include "features/select_word.h"
#include "utils/keylog.h"
#include "keycodes/keycodes.h"

static uint8_t mod_state;

bool handle_keycode(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    // lock layer when pressed
    if (!process_layer_lock(keycode, record, LLOCK)) {
        return false;
    }

     if (!process_select_word(keycode, record, SELWORD)) {
        return false;
    }

     // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
            case KC_BSPC: {
               // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                   // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                       // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else {  // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                       unregister_code(KC_DEL);
                       delkey_registered = false;
                       return false;
                }
            }
               // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        }
    }

       return true;
}

