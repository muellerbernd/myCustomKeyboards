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
    _NEO2,
    _LOWER,
    _RAISE,
    _NAV,
    _ADJUST
};

enum planck_keycodes
{
    QWERTZ = SAFE_RANGE,
    NEO2,
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
    KC_NAGR,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,   KC_BSPC,
    CTAB  ,  DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_PLUS, KC_LALT,
    KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT ,
    BACKLIT, KC_LCTL, KC_NAV,  KC_LGUI, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_ADAP, KC_NAV,  KC_LALT, BACKLIT
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
[_NEO2] = LAYOUT_planck_grid(
    KC_NAGR,    DE_X,    DE_V,   DE_L,  DE_C,   DE_W,   DE_K,  DE_H, DE_G,      DE_F, DE_Q   , KC_BSPC,
    CTAB   ,    DE_U,    DE_I,   DE_A,  DE_E,   DE_O,   DE_S,  DE_N, DE_R,      DE_T,    DE_D, KC_LALT,
    KC_LSFT,  DE_EQL, DE_MINS,DE_SLSH,  DE_P,   DE_Z,   DE_B,  DE_M, DE_COMM, DE_DOT,    DE_J, KC_RSFT ,
    BACKLIT, KC_LCTL,  KC_NAV,KC_LGUI, LOWER, KC_SPC, KC_ENT, RAISE, KC_ADAP, KC_NAV, KC_LALT, BACKLIT
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
    _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, DE_DOT, _______,
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
    _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, _______,
    _______, DE_HASH, DE_TILD, DE_PIPE,  DE_DLR, DE_EURO, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, _______,
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
     XXXXXXX, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX,    TABD,  KC_PGUP, KC_UP  , KC_PGDN,   TABU, KC_DEL,
     XXXXXXX, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_HOME,  KC_LEFT, KC_DOWN,KC_RIGHT, KC_END, KC_INS,
     _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6),  G(KC_7), G(KC_8), G(KC_9),G(KC_0),_______,
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
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTZ ,    NEO2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, KC_MPLY, _______, _______, _______, _______, _______, _______
)

};
// clang-format on
#ifdef AUDIO_ENABLE
float plover_song[][2] = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    mod_state = get_mods();

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
        case NEO2:
            if (record->event.pressed)
            {
                set_single_persistent_default_layer(_NEO2);
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
            // Ä & ä
    case KC_A:
        if (mod_state & MOD_MASK_ALT)
        {
            if (record->event.pressed)
            {
                unregister_code(KC_LALT);
                unregister_code(KC_RALT);

                tap_code(DE_ADIA);

                set_mods(mod_state);
            }
            return false;
        }
        return true;
        break;
    // Ö & ö
    case KC_O:
        if (mod_state & MOD_MASK_ALT)
        {
            if (record->event.pressed)
            {
                unregister_code(KC_LALT);
                unregister_code(KC_RALT);

                tap_code(DE_ODIA);

                set_mods(mod_state);
            }
            return false;
        }
        return true;
        break;
    // Ö & ö
    case KC_U:
        if (mod_state & MOD_MASK_ALT)
        {
            if (record->event.pressed)
            {
                unregister_code(KC_LALT);
                unregister_code(KC_RALT);

                tap_code(DE_UDIA);

                set_mods(mod_state);
            }
            return false;
        }
        return true;
        break;
    // ß
    case KC_S:
        if (mod_state & MOD_MASK_ALT)
        {
            if (record->event.pressed)
            {
                unregister_code(KC_LALT);
                unregister_code(KC_RALT);

                tap_code(DE_SS);

                set_mods(mod_state);
            }
            return false;
        }
        return true;
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
