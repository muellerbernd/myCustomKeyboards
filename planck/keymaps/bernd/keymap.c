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
#include "muse.h"

enum planck_layers
{
    _QWERTZ,
    _COLEMAK,
    _DVORAK,
    _LOWER,
    _RAISE,
    _NAV,
    _ADJUST
};

enum planck_keycodes
{
    QWERTZ = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    BACKLIT,
    NAV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define KC_NAV MO(_NAV)

#define KC_NAGR LT(_NAV, KC_ESC)

#define KC_ADAP LT(_ADJUST, KC_APP)

#define KC_CTAB CTL_T(KC_TAB)
#define KC_ALPI ALT_T(PIPE)

// aliases for clarity in layering
#define CENT LCTL_T(KC_ENT)
/** #define BSCTL LCTL_T(KC_BSPC) // Ctrl when held, Backspace when tapped */
#define CTAB LCTL_T(KC_TAB)
#define ATPI LALT_T(DE_PIPE)
#define TABD C(KC_PGUP)
#define TABU C(KC_PGDN)

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
[_QWERTZ] = LAYOUT_planck_grid(
    KC_NAGR,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
    CTAB  ,  DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_PLUS, ATPI,
    KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT ,
    BACKLIT, KC_LCTL, KC_NAV,  KC_LGUI, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_ADAP, KC_NAV,  KC_LALT, BACKLIT
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

    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F11,  KC_F12, XXXXXXX, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   _  |   @  |   $  |   €  |   %  |   (  |   )  |   ü  |   `  |   ö  |   =  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ä  |   ß  |   ^  |   <  |  [   |   ]  |   >  |   §  |   &  |   ~  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   '  |   "  |   |  |   /  |   {  |   }  |   \  |   !  |   ?  |   #  |   *  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    DE_UNDS,   DE_AT,  DE_DLR, DE_EURO, DE_PERC, DE_LPRN, DE_RPRN,   DE_UE,  DE_GRV,   DE_OE,  DE_EQL, DE_MINS,
    _______,   DE_AE,   DE_SS, DE_CIRC, DE_LESS, DE_LBRC, DE_RBRC, DE_MORE, DE_PARA, DE_AMPR, DE_TILD, DE_PLUS,
    _______, DE_QUOT, DE_DQUO, DE_PIPE, DE_SLSH, DE_LCBR, DE_RCBR, DE_BSLS, DE_EXLM,  DE_QST, DE_HASH, DE_ASTR,
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
     XXXXXXX, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_HOME,  KC_END, KC_PGUP, KC_UP  , KC_PGDN ,XXXXXXX, KC_DEL,
     XXXXXXX, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, TABD,    TABU,    KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX,XXXXXXX,
     _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0),_______,
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
    XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KC_MPRV, KC_VOLU, KC_MNXT, XXXXXXX, KC_MUTE,
    XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, KC_BRID, KC_VOLD, KC_BRIU, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTZ , _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, KC_MPLY, _______, _______, _______, _______, _______, _______
)

};
// clang-format on
#ifdef AUDIO_ENABLE
float plover_song[][2] = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case QWERTZ:
            if (record->event.pressed)
            {
                print(
                    "mode just switched to qwertz and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTZ);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed)
            {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed)
            {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed)
            {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            else
            {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed)
            {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            else
            {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed)
            {
                /** register_code(KC_RSFT); */
#ifdef BACKLIGHT_ENABLE
                backlight_step();
#endif
#ifdef KEYBOARD_planck_rev5
                writePinLow(E6);
#endif
            }
            else
            {
                /** unregister_code(KC_RSFT); */
#ifdef KEYBOARD_planck_rev5
                writePinHigh(E6);
#endif
            }
            return false;
            break;
    }
    return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise)
{
    if (muse_mode)
    {
        if (IS_LAYER_ON(_RAISE))
        {
            if (clockwise)
            {
                muse_offset++;
            }
            else
            {
                muse_offset--;
            }
        }
        else
        {
            if (clockwise)
            {
                muse_tempo += 1;
            }
            else
            {
                muse_tempo -= 1;
            }
        }
    }
    else
    {
        if (clockwise)
        {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
#else
            tap_code(KC_PGDN);
#endif
        }
        else
        {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
#else
            tap_code(KC_PGUP);
#endif
        }
    }
}

void dip_switch_update_user(uint8_t index, bool active)
{
    switch (index)
    {
        case 0:
        {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active)
            {
#ifdef AUDIO_ENABLE
                if (play_sound)
                {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            }
            else
            {
#ifdef AUDIO_ENABLE
                if (play_sound)
                {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active)
            {
                muse_mode = true;
            }
            else
            {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void)
{
#ifdef AUDIO_ENABLE
    if (muse_mode)
    {
        if (muse_counter == 0)
        {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note)
            {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
    else
    {
        if (muse_counter)
        {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode)
{
    switch (keycode)
    {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
