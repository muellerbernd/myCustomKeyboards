/**
 * File              : keymap.c
 * Author            : Bernd Müller <bernd@muellerbernd.de>
 * Date              : 07.01.2022
 * Last Modified Date: 21.03.2022
 * Last Modified By  : Bernd Müller <bernd@muellerbernd.de>
 */
#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include <stdio.h>

#include "users/muellerbernd/muellerbernd.h"
#ifdef TAP_DANCE_ENABLE
#include "users/muellerbernd/tapdance.c"
#endif

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTZ] =  LAYOUT_3x5_2_base_wrapper(
        QWERTZ_L1, QWERTZ_R1,
        QWERTZ_L2, QWERTZ_R2,
        QWERTZ_L3, QWERTZ_R3
),

[_COLDH] = LAYOUT_3x5_2_base_wrapper(
        COLDH_L1, COLDH_R1,
        COLDH_L2, COLDH_R2,
        COLDH_L3, COLDH_R3
),

[_LOWER] = LAYOUT_split_3x5_2_wrapper(
        LOWER_L1, LOWER_R1,
        LOWER_L2, LOWER_R2,
        LOWER_L3, LOWER_R3,
_______, _______, _______, _______
),

[_RAISE] = LAYOUT_split_3x5_2_wrapper(
        RAISE_L1, RAISE_R1,
        RAISE_L2, RAISE_R2,
        RAISE_L3, RAISE_R3,
_______, _______, _______, _______
),

[_NAV] = LAYOUT_split_3x5_2_wrapper(
        NAV_L1, NAV_R1,
        NAV_L2, NAV_R2,
        NAV_L3, NAV_R3,
_______, _______, _______, _______
),


[_ADJUST] = LAYOUT_split_3x5_2_wrapper(
        ADJUST_L1, ADJUST_R1,
        ADJUST_L2, ADJUST_R2,
        ADJUST_L3, ADJUST_R3,
_______, _______, _______, _______
  )

};

// clang-format on
#ifdef LEADER_ENABLE
#include "users/muellerbernd/leader.c"
#endif // LEADER_ENABLE

#ifdef COMBO_ENABLE
// #include "users/muellerbernd/combos.c"
#include "g/keymap_combo.h"
#endif

#include "users/muellerbernd/process_record_user.c"
