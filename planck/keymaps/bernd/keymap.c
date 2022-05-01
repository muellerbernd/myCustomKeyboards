/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_german.h"

#include "users/muellerbernd/muellerbernd.h"
#ifdef TAP_DANCE_ENABLE
#include "users/muellerbernd/tapdance.c"
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwertz
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TabCtl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   +  |  <   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | NAV  | GUI  |Lower | SPC  | Enter|Raise | ADJ  | NAV  |  ALT |Brite |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTZ] = LAYOUT_PLANCK_grid_hr_base_wrapper(
        QWERTZ_L1, QWERTZ_R1,
        QWERTZ_L2, QWERTZ_R2,
        QWERTZ_L3, QWERTZ_R3
),

[_COLDH] = LAYOUT_PLANCK_grid_hr_base_wrapper(
        COLDH_L1, COLDH_R1,
        COLDH_L2, COLDH_R2,
        COLDH_L3, COLDH_R3
),
/* Neo
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TabCtl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   +  |  <   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | NAV  | GUI  |Lower | SPC  | Enter|Raise | ADJ  | NAV  |  ALT |Brite |
 * `-----------------------------------------------------------------------------------'
 */

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|  F11 |  F12 |XXXXXX|   ,  |   .  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_PLANCK_grid_wrapper(
_______,LOWER_L1, LOWER_R1,_______,
_______,LOWER_L2, LOWER_R2,_______,
_______,LOWER_L3, LOWER_R3,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   °  |   @  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |   ´  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   /  |   {  |   }  |  *   |   ?  |   (  |   )  |   -  |   :  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   ~  |   |  |   $  |   €  |   +  |   %  |   "  |   '  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = LAYOUT_PLANCK_grid_wrapper(

_______,RAISE_L1, RAISE_R1,_______,
_______,RAISE_L2, RAISE_R2,_______,
_______,RAISE_L3, RAISE_R3,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),

[_NAV] = LAYOUT_PLANCK_grid_wrapper(
_______,NAV_L1, NAV_R1,_______,
_______,NAV_L2, NAV_R2,_______,
_______,NAV_L3, NAV_R3,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),


[_ADJUST] = LAYOUT_PLANCK_grid_wrapper(
_______,ADJUST_L1, ADJUST_R1,_______,
_______,ADJUST_L2, ADJUST_R2,_______,
_______,ADJUST_L3, ADJUST_R3,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
  )
};
// clang-format on
#ifdef AUDIO_ENABLE
float plover_song[][2] = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
float my_song[][2] = SONG(RICK_ROLL);
#endif

#ifdef LEADER_ENABLE
#include "users/muellerbernd/leader.c"
#endif // LEADER_ENABLE

#ifdef COMBO_ENABLE
// #include "users/muellerbernd/combos.c"
#include "g/keymap_combo.h"
#endif

#include "users/muellerbernd/process_record_user.c"
