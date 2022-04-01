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

#include "users/muellerbernd/aliases.c"
#ifdef TAP_DANCE_ENABLE
#include "users/muellerbernd/tapdance.c"
#endif

// clang-format off
#define LAYOUT_planck_grid_hr( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b }, \
    { k10, LGUI_T(k11), LALT_T(k12), LCTL_T(k13), LSFT_T(k14), k15, k16, LSFT_T(k17), LCTL_T(k18), LALT_T(k19), LGUI_T(k1a), k1b }, \
    { k20, k21, ALGR_T(k22), k23, k24, k25, k26, k27, k28, ALGR_T(k29), k2a, k2b }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b } \
}
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
[_QWERTZ] = LAYOUT_planck_grid(
    KC_ESC ,   DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,  DE_I,      DE_O,    DE_P, DE_UDIA,
    CTAB   ,   DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,  DE_K,      DE_L, DE_ODIA, ATPI,
    L_SFT  ,   DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,  DE_COMM, DE_DOT, DE_MINS, R_SFT,
    BACKLIT,   TABD,   T_NAV, KC_LGUI,   T_DEL,   T_SPC, KC_BSPC,   T_ENT,  T_ADAP,   T_NAV,    TABU, BACKLIT
),
[_QWERTZ_HR] = LAYOUT_planck_grid_hr(
    KC_ESC ,   DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,  DE_I,      DE_O,    DE_P, DE_UDIA,
    CTAB   ,   DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,  DE_K,      DE_L, DE_ODIA, ATPI,
    L_SFT  ,   DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,  DE_COMM, DE_DOT, DE_MINS, R_SFT,
    BACKLIT,   TABD,   T_NAV, KC_LGUI,   T_DEL,   T_SPC, KC_BSPC,   T_ENT,  T_ADAP,   T_NAV,    TABU, BACKLIT
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
[_BONE2] = LAYOUT_planck_grid(
    KC_ESC ,   DE_J,    DE_D,    DE_U,    DE_A,    DE_X,    DE_P,   DE_H,  DE_L,       DE_M,    DE_W, DE_Q,
    CTAB   ,   DE_C,    DE_T,    DE_I,    DE_E,    DE_O,    DE_B,   DE_N,  DE_R,       DE_S,    DE_G, KC_LALT,
    L_SFT  ,   DE_F,    DE_V, DE_UDIA, DE_ADIA, DE_ODIA,    DE_Y,   DE_Z,  DE_COMM,  DE_DOT,    DE_K, R_SFT,
    BACKLIT,   TABD,   T_NAV, KC_LGUI,   T_DEL,   T_SPC, KC_BSPC,   T_ENT,  T_ADAP,   T_NAV,    TABU, BACKLIT
),
[_BONE2_HR] = LAYOUT_planck_grid_hr(
    KC_ESC ,   DE_J,    DE_D,    DE_U,    DE_A,    DE_X,    DE_P,   DE_H,  DE_L,       DE_M,    DE_W, DE_Q,
    CTAB   ,   DE_C,    DE_T,    DE_I,    DE_E,    DE_O,    DE_B,   DE_N,  DE_R,       DE_S,    DE_G, KC_LALT,
    L_SFT  ,   DE_F,    DE_V, DE_UDIA, DE_ADIA, DE_ODIA,    DE_Y,   DE_Z,  DE_COMM,  DE_DOT,    DE_K, R_SFT,
    BACKLIT,   TABD,   T_NAV, KC_LGUI,   T_DEL,   T_SPC, KC_BSPC,   T_ENT,  T_ADAP,   T_NAV,    TABU, BACKLIT
),

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
[_LOWER] = LAYOUT_planck_grid(

    _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, _______,
    _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, DE_DOT , _______,
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,    KC_0,    KC_1,    KC_2,    KC_3, DE_COMM, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
[_RAISE] = LAYOUT_planck_grid(
     DE_DEG,   DE_AT, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, DE_EXLM, DE_LABK, DE_RABK,  DE_EQL, DE_AMPR, DE_ACUT,
    _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_DOT,
    _______, DE_HASH, DE_TILD, DE_PIPE,  DE_DLR, DE_EURO, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, DE_COMM,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_NAV] = LAYOUT_planck_grid(
     XXXXXXX,  KC_ESC, _______, _______, _______, _______,    TABD,  KC_PGUP, KC_UP  , KC_PGDN,   TABU, KC_DEL,
     XXXXXXX,  KC_TAB,    STAB,    I3_L,    I3_R, _______, KC_HOME,  KC_LEFT, KC_DOWN,KC_RIGHT, KC_END, KC_INS,
     _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,_______,_______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______
),


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KC_MPRV, KC_VOLU, KC_MNXT, KC_MPLY, KC_MUTE,
    XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, KC_BRID, KC_VOLD, KC_BRIU, XXXXXXX, XXXXXXX,
    KC_CAPS, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTZ ,   BONE2, QWRTZ_H, BONE2_H, XXXXXXX, KC_CAPS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

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
