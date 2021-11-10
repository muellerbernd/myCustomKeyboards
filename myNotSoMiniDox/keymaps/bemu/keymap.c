#include QMK_KEYBOARD_H
#include "keymap_german.h"

// Each layer gets a name for readability, which is then used in the keymap
// matrix below. The underscores don't mean anything - you can have a layer
// called STUFF or any other name. Layer names don't all need to be of the same
// length, obviously, and you can also skip them entirely and just use numbers.
#define _QWERTZ 0
#define _LOWER 1
#define _RAISE 2
#define _NAV 3
#define _ADJUST 4

enum custom_keycodes
{
    QWERTZ = SAFE_RANGE,
    LOWER,
    RAISE,
    NAV,
    ADJUST,
};

enum
{
    TD_R = 0,
    TD_LY = 1
};

#define KC_NAGR LT(_NAV, KC_ESC)
#define KC_NAMI LT(_NAV, KC_BSPC)

#define KC_LOTA LT(_LOWER, KC_TAB)
#define KC_LAPI LT(_LOWER, DE_PIPE)

#define KC_RSPC LT(_RAISE, KC_SPC)
#define KC_RENT LT(_RAISE, KC_ENT)
#define KC_ALTR LT(_RAISE, KC_LALT)

#define KC_ADAP LT(_ADJUST, KC_APP)

#define KC_CTAB CTL_T(KC_TAB)
#define KC_ALPI ALT_T(PIPE)
#define KC_MOLO MO(_LOWER)
#define KC_MORA MO(_RAISE)

// aliases for clarity in layering
#define SftEnt SFT_T(KC_ENT)  // Shift when held, Enter when tapped
#define BSCTL LCTL_T(KC_BSPC) // Ctrl when held, Backspace when tapped
#define CTAB LCTL_T(KC_TAB)
#define ATPI LALT_T(DE_PIPE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTZ] = LAYOUT(
// ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
    KC_NAGR,   DE_Q,   DE_W,   DE_E,   DE_R,   DE_T,             DE_Z,   DE_U,   DE_I,   DE_O,   DE_P,KC_BSPC,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
       CTAB,   DE_A,   DE_S,   DE_D,   DE_F,   DE_G,             DE_H,   DE_J,   DE_K,   KC_L,DE_PLUS,   ATPI,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    KC_LSFT,   DE_Y,   DE_X,   DE_C,   DE_V,   DE_B,             DE_N,   DE_M,DE_COMM, DE_DOT,DE_MINS,KC_RSFT,
// '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
                            TD(TD_LY),KC_MOLO, KC_SPC,     KC_ENT,KC_MORA,KC_ADAP
                        // `-------+-------+-------`       `-------+-------+-------`
   ),

  [_LOWER] = LAYOUT(
// ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
    _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,             KC_6,   KC_7,   KC_8,   KC_9,   KC_0,_______,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,            KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,_______,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    _______,_______,_______,_______,_______, KC_F11,           KC_F12,_______,_______,_______,_______,_______,
// '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
                              _______,_______,_______,      _______,_______,_______
                          // `-------+-------+-------`     `-------+-------+-------`
  ),

  [_RAISE] = LAYOUT(
// ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
     DE_UNDS,  DE_AT, DE_DLR,DE_EURO,DE_PERC,DE_LPRN,          DE_RPRN,  DE_UE, DE_GRV,  DE_OE, DE_EQL,DE_MINS,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
     _______,  DE_AE,  DE_SS,DE_CIRC,DE_LESS,DE_LBRC,          DE_RBRC,DE_MORE,DE_PARA,DE_AMPR,DE_TILD,DE_PLUS,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
     _______,DE_QUOT,DE_DQUO,DE_PIPE,DE_SLSH,DE_LCBR,          DE_RCBR,DE_BSLS,DE_EXLM, DE_QST,DE_HASH,DE_ASTR,
 // '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
                               _______,_______,_______,      _______,_______,_______
                           // `-------+-------+-------`     `-------+-------+-------`
   ),

  [_NAV] = LAYOUT(
 // ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+------- +-------+-------.
     _______,KC_WH_U,KC_BTN1,KC_MS_U,KC_BTN2,KC_HOME,          KC_END ,KC_PGUP,KC_UP  ,KC_PGDN ,XXXXXXX, KC_DEL,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+------- +-------,-------+-------|
     _______,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D,C(KC_PGUP),    C(KC_PGDN),KC_LEFT,KC_DOWN,KC_RIGHT,XXXXXXX,XXXXXXX,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+------- +-------,-------+-------|
     _______,G(KC_1),G(KC_2),G(KC_3),G(KC_4),G(KC_5),          G(KC_6),G(KC_7),G(KC_8),G(KC_9) ,G(KC_0),XXXXXXX,
 // '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+------- +-------+-------'
                               _______,_______,_______,     _______,_______,_______
                           // `-------+-------+-------`     `-------+-------+-------`
   ),

  [_ADJUST] = LAYOUT(
// ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
   TD(TD_R),RGB_TOG,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI,          XXXXXXX,KC_MPRV,KC_VOLU,KC_MNXT,XXXXXXX,KC_MUTE,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    XXXXXXX,XXXXXXX,XXXXXXX,RGB_HUD,RGB_SAD,RGB_VAD,          XXXXXXX,KC_BRID,KC_VOLD,KC_BRIU,XXXXXXX,XXXXXXX,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
// '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
                              _______,_______,KC_MPLY,      _______,_______,XXXXXXX
                          // `-------+-------+-------`     `-------+-------+-------`
  )
};

 /**  [_NAV] = LAYOUT( */
 /** // ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------. */
 /**     _______,_______,_______,_______,_______,_______,          _______,_______,_______,_______,_______,_______, */
 /** // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------| */
 /**     _______,_______,_______,_______,_______,_______,          _______,_______,_______,_______,_______,_______, */
 /** // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------| */
 /**     _______,_______,_______,_______,_______,_______,          _______,_______,_______,_______,_______,_______, */
 /** // '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------' */
 /**                               _______,_______,_______,      _______,_______,_______ */
 /**                           // `-------+-------+-------`     `-------+-------+-------` */
 /**   ), */
 /**  */
// clang-format on
void matrix_init_user(void) { set_single_persistent_default_layer(_QWERTZ); };

void safe_reset(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count >= 3)
    {
        // Reset the keyboard if you tap the key more than three times
        reset_keyboard();
        reset_tap_dance(state);
    }
    else
    {
        /** register_code(KC_LSFT); */
    }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data)
{
    /** if (state->count != 3) { */
    /** unregister_code(KC_LSFT); */
    /** } */
}

bool win_held;
void dance_layers(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->pressed)
    {
        /** layer_on(_ADJUST); */
        register_code(KC_LGUI);
        win_held = true;
    }
    switch (state->count)
    {
    case 1: // off all layers, just base on
        if (!state->pressed)
        {
            layer_off(_ADJUST);
            layer_off(_LOWER);
            layer_off(_RAISE);
            layer_off(_NAV);
            win_held = false;
        }
        break;
    case 2: // raise
        layer_on(_RAISE);
        layer_off(_LOWER);
        layer_off(_NAV);
        layer_off(_ADJUST);
        break;
    case 3: // lower
        layer_off(_RAISE);
        layer_on(_LOWER);
        layer_off(_NAV);
        layer_off(_ADJUST);
        break;
    case 4: // nav
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_on(_NAV);
        layer_off(_ADJUST);
        break;
    case 5: // adjust
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_NAV);
        layer_on(_ADJUST);
        break;
    }
}
void dance_layers_finish(qk_tap_dance_state_t *state, void *user_data)
{
    if (win_held)
    {
        /** layer_off(_ADJUST); */
        win_held = false;
    }
    unregister_code(KC_LGUI);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, safe_reset, dance_cln_reset),
    [TD_LY] =
        ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layers, dance_layers_finish)};
