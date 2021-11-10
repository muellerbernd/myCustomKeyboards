/* Copyright 2021 Bernd Müller
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

enum {
  TD_RESET = 0
};
void safe_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 10) {
    // Reset the keyboard if you tap the key more than three times
    reset_keyboard();
    reset_tap_dance(state);
  }
  /** else */
  /** { */
  /**     register_code(KC_LSFT); */
  /** } */
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count != 10) {
        unregister_code(KC_LSFT);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  /** [TD_RESET] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, safe_reset, dance_cln_reset) */
  [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset)
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTZ,
    _FN,
    _NAV
};

#define KC_NAESC LT(_NAV, KC_ESC)
#define KC_FNAPP LT(_FN, KC_APP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
    {
        /* Base */
        [_QWERTZ] = LAYOUT(KC_NAESC,    DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   KC_DEL,  KC_BSPC, KC_PGUP,
                           KC_TAB,      DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UE,   DE_PLUS, DE_HASH, KC_PGDOWN,
                           KC_CAPS,     DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_OE,   DE_AE,            KC_ENT,  KC_UP,
                           KC_LSFT,     DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS,          KC_RSFT, KC_DOWN,
                           KC_LCTL,     KC_LCMD,          KC_LALT,                   KC_SPC,                             KC_ALGR, KC_FNAPP,KC_RCTL, KC_LEFT, KC_RGHT),

        [_FN]     = LAYOUT(KC_END ,       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_HOME, KC_VOLU,
                           _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DE_PIPE, KC_GRV,  KC_VOLD,
                           _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_BRIU,
                           DE_LESS,              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          DE_MORE, KC_BRID,
                           _______,     _______,          _______,                   KC_MUTE,                            _______, _______, _______, KC_MPRV, KC_MNXT),

        [_NAV]    = LAYOUT(_______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______,
                           _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                           _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_MS_U,
                           TD(TD_RESET),         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_MS_D,
                           _______,     _______,          _______,                   _______,                            _______, _______, _______, KC_MS_L, KC_MS_R),

    };

// für weitere layer dann tap toggle in fn layer
/** ACTION_TAP_DANCE_LAYER_MOVE(kc, layer):
 * Sends the kc keycode when tapped once, or moves to layer. (this functions like the TO layer keycode). */

/** [_FN]     = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/**                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/**                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, */
/**                            _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, */
/**                            _______, _______,          _______,                   _______,                            _______, _______, _______, _______, _______), */
/**  */


