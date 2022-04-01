/**
 * File              : keymap.c
 * Author            : Bernd Müller <bernd@muellerbernd.de>
 * Date              : 07.01.2022
 * Last Modified Date: 22.03.2022
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

#define MY_HOMEROW_LAYOUT( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, L40, R40, R30, R31, R32, R33, R34, R35, \
              L41, L42, L43, L44, L45, R41, R42, R43, R44, R45  \
    ) \
    LAYOUT(\
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13,R14, R15, \
    L20, LGUI_T(L21), LALT_T(L22), LCTL_T(L23), LSFT_T(L24), L25,           R20, LSFT_T(R21), LCTL_T(R22), LALT_T(R23),LGUI_T(R24), R25, \
    L30, L31, L32, L33, L34, L35, L40, R40, R30, R31, R32, R33, R34, R35, \
              L41, L42, L43, L44, L45, R41, R42, R43, R44, R45  \
   )
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,--------------------------------------------.                    ,----------------------------------------------.
 * |   ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `        |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -        |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |  LShift |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '        |
 * |---------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+-----------|
 * |  LCTRL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift/Enter|
 * `-------------------------------------------|       /     \      \-----------------------------------------------'
 *                 | LCTRL| LGUI | LALT |LOWER| Space /       \Enter \  |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'
 */

[_QWERTZ] =  LAYOUT_kimiko_base_wrapper(
        QWERTZ_L1, QWERTZ_R1,
        QWERTZ_L2, QWERTZ_R2,
        QWERTZ_L3, QWERTZ_R3
),

[_COLDH] = LAYOUT_kimiko_base_wrapper(
        COLDH_L1, COLDH_R1,
        COLDH_L2, COLDH_R2,
        COLDH_L3, COLDH_R3
),
/* LOWER
 * ,-------------------------------------------.                    ,-----------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |   0  | F12  |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `    |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |--------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |        |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   \  |
 * `-------------------------------------------|       /     \      \-----------------------------------------------'
 *                 | LCTRL| LGUI | LALT |LOWER| Space /       \Enter \  |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'
 */

[_LOWER] = LAYOUT_kimiko_wrapper(
KC_F1 ,   KC_F2,    KC_F3,    KC_F4,    KC_F5, KC_F6, KC_F7,        KC_F8,       KC_F9,       KC_F10,       KC_F11, KC_F12,\
                          _______, LOWER_L1, LOWER_R1, _______,
                          _______, LOWER_L2, LOWER_R2, _______,
                 _______, LOWER_L3, _______, _______, LOWER_R3, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 | LCTRL| LGUI | LALT |LOWER| Space /       \Enter \  |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'
 */

[_RAISE] = LAYOUT_kimiko_wrapper(
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, RAISE_L1, RAISE_R1, _______,
                          _______, RAISE_L2, RAISE_R2, _______,
                 _______, RAISE_L3, _______, _______, RAISE_R3, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_NAV] = LAYOUT_kimiko_wrapper(
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, NAV_L1, NAV_R1, _______,
                          _______, NAV_L2, NAV_R2, _______,
                 _______, NAV_L3, _______, _______, NAV_R3, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* ADJUST (Press LOWER and RAISE together)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |RESET |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB ON| HUE+ | SAT+ | VAL+ |      |      |                    | PREV | PLAY | NEXT |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | MODE | HUE- | SAT- | VAL- |      |      |-------.    ,-------| VOL+ | MUTE | VOL- |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 |LCTRL| LGUI | LALT |LOWER| Space /       \Enter \  |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'
 */

[_ADJUST] = LAYOUT_kimiko_wrapper(
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, ADJUST_L1, ADJUST_R1, _______,
                          _______, ADJUST_L2, ADJUST_R2, _______,
                 _______, ADJUST_L3, _______, _______, ADJUST_R3, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in
// rules.mk
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    return OLED_ROTATION_270;
}
#include "users/muellerbernd/keylogger.c"
/* static bool display_on = true; */
#ifdef CAT_ENABLE
#include "users/muellerbernd/bongo.c"
#endif // CAT_ENABLE
#ifdef LUNA_ENABLE
#include "users/muellerbernd/luna.c"
#endif
#include "users/muellerbernd/oled.c"
#endif // OLED_ENABLE

#include "users/muellerbernd/process_record_user.c"

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise)
{
    if (index == 0)
    {
        // Volume control
        if (clockwise)
        {
            tap_code(KC_VOLD);
        }
        else
        {
            tap_code(KC_VOLU);
        }
    }
    else if (index == 1)
    {
        // Page up/Page down
        if (clockwise)
        {
            tap_code16(TABU);
        }
        else
        {
            tap_code16(TABD);
        }
    }
    return false;
}
#endif // ENCODER_ENABLE
