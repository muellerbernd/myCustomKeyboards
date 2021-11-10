#include QMK_KEYBOARD_H

#include "keymap_german.h"
/** #include "keymap_us_international.h" */
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _SYMB 1
#define _LOWER 2
#define _NAV 3
#define _ADJUST 4

enum {
  TD_R= 0,
  TD_LY=1
};

void safe_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    // Reset the keyboard if you tap the key more than three times
    reset_keyboard();
    reset_tap_dance(state);
  } else
  {
      /** register_code(KC_LSFT); */
  }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
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
  case 1: //off all layers, just base on
    if (!state->pressed)
    {
      layer_off(_ADJUST);
      layer_off(_LOWER);
      layer_off(_SYMB);
      layer_off(_NAV);
      win_held = false;
    }
    break;
  case 2: //raise
    layer_on(_SYMB);
    layer_off(_LOWER);
    layer_off(_NAV);
    break;
  case 3: //lower
    layer_on(_LOWER);
    layer_off(_SYMB);
    layer_off(_NAV);
    break;
  case 4: //nav
    layer_off(_LOWER);
    layer_off(_SYMB);
    layer_on(_NAV);
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
  [TD_LY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layers, dance_layers_finish)

};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  SYMB,
  LOWER,
  NAV,
  ADJUST,
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)
#define SLASH   LSFT(DE_7)
#define DQUOT   LSFT(DE_2)
#define EQUAL   LSFT(DE_0)
#define QUEST   LSFT(DE_SS)
#define BSLASH  ALGR(DE_SS)
#define PIPE  ALGR(DE_PIPE)

#define KC_ALAS LALT_T(DE_BSLS)
#define KC_CTPL LCTL_T(DE_HASH)

#define KC_NAGR LT(_NAV, KC_ESC)
#define KC_NAMI LT(_NAV, DE_PLUS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)
#define KC_ADAP LT(_ADJUST, KC_APP)

#define KC_LOTA LT(_LOWER, KC_TAB)
#define KC_LAPI LT(_LOWER, DE_PIPE)

#define KC_RSPC LT(_SYMB, KC_SPC)
#define KC_RENT LT(_SYMB, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     DE_CIRC ,KC_1    ,KC_2    ,DE_3    ,DE_4    ,DE_5    ,                                            DE_6    ,DE_7    ,DE_8    ,DE_9    ,DE_0    ,DE_SS   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NAGR ,DE_Q    ,DE_W    ,DE_E    ,DE_R    ,DE_T    ,SYM_L   ,                          SYM_L   ,DE_Z    ,DE_U    ,DE_I    ,DE_O    ,DE_P    ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LOTA ,DE_A    ,DE_S    ,DE_D    ,DE_F    ,DE_G    ,DE_LCBR ,                          DE_RCBR ,DE_H    ,DE_J    ,DE_K    ,DE_L    ,DE_PLUS ,KC_LAPI ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,DE_Y    ,DE_X    ,DE_C    ,DE_V    ,DE_B    ,KC_ADEN ,KC_HOME ,        KC_PGDN ,KC_ADPU ,DE_N    ,DE_M    ,DE_COMM ,DE_DOT  ,DE_MINS ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     DE_PIPE ,DE_PLUS ,DE_HASH ,DE_TILD ,    TD(TD_LY),    KC_LCTL ,KC_RSPC  ,       KC_RENT  ,KC_LALT ,    KC_ADAP ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_AT   ,DE_DLR  ,DE_EURO ,DE_PERC ,DE_LPRN ,SLASH   ,                          BSLASH  ,DE_RPRN ,DE_UE   ,DE_GRV  ,DE_OE   ,EQUAL   ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_AE   ,DE_SS   ,DE_CIRC ,DE_LESS ,DE_LBRC ,DE_LBRC ,                          DE_RBRC ,DE_RBRC ,DE_MORE ,DE_PARA ,DE_AMPR ,DE_TILD ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_QUOT ,DE_DQOT ,PIPE    ,SLASH   ,DE_LCBR ,_______ ,_______ ,        _______ ,_______ ,DE_RCBR ,BSLASH  ,DE_EXLM ,DE_QST  ,DE_HASH ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_APP  ,     DE_LESS ,_______ ,_______ ,DE_MORE
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,_______ ,                          _______ ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,_______ ,                          _______ ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,KC_F11  ,_______ ,_______ ,        _______ ,_______ ,KC_F12  ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,KC_HOME ,_______ ,                          _______ ,KC_END  ,KC_PGUP ,KC_UP   ,KC_PGDN ,XXXXXXX ,KC_DEL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RIGHT,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BTN1 ,KC_BTN2 ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,                          XXXXXXX ,XXXXXXX ,KC_MPRV ,KC_VOLU ,KC_MNXT ,XXXXXXX ,KC_MUTE ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_BRID ,KC_VOLD ,KC_BRIU ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TD(TD_R),XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     _______ ,    _______ ,KC_MPLY ,        _______ ,_______ ,    _______ ,     KC_BRID ,KC_VOLD ,KC_VOLU ,KC_BRIU
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};
void matrix_init_user(void) {
  set_single_persistent_default_layer(_BASE);
};
