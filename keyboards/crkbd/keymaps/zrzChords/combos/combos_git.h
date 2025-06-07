#pragma once

#include "quantum.h"
#include "keycodes/keycodes.h"

extern const uint16_t PROGMEM git_status_combo[];
extern const uint16_t PROGMEM git_commit_combo[];
extern const uint16_t PROGMEM git_pull_combo[];
extern const uint16_t PROGMEM git_push_combo[];
extern const uint16_t PROGMEM git_log_combo[];
extern const uint16_t PROGMEM git_add_combo[];
extern const uint16_t PROGMEM git_checkout_combo[];
extern const uint16_t PROGMEM git_restore_combo[];
extern const uint16_t PROGMEM git_revert_combo[];
extern const uint16_t PROGMEM git_stash_combo[];

#define COMBOS_GIT \
    [GIT_STATUS] = COMBO_ACTION(git_status_combo), \
    [GIT_COMMIT] = COMBO_ACTION(git_commit_combo), \
    [GIT_PULL]   = COMBO_ACTION(git_pull_combo), \
    [GIT_PUSH]   = COMBO_ACTION(git_push_combo), \
    [GIT_LOG]    = COMBO_ACTION(git_log_combo), \
    [GIT_ADD]    = COMBO_ACTION(git_add_combo), \
    [GIT_CHECKOUT] = COMBO_ACTION(git_checkout_combo), \
    [GIT_RESTORE]  = COMBO_ACTION(git_restore_combo), \
    [GIT_REVERT]   = COMBO_ACTION(git_revert_combo), \
    [GIT_STASH]    = COMBO_ACTION(git_stash_combo)
