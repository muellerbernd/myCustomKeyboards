/**
 * File              : keymap.c
 * Author            : Bernd Müller <bernd@muellerbernd.de>
 * Date              : 29.11.2021
 * Last Modified Date: 01.12.2021
 * Last Modified By  : Bernd Müller <bernd@muellerbernd.de>
 */
#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include <stdio.h>

char wpm_str[8];
// Each layer gets a name for readability, which is then used in the keymap
// matrix below. The underscores don't mean anything - you can have a layer
// called STUFF or any other name. Layer names don't all need to be of the same
// length, obviously, and you can also skip them entirely and just use numbers.
enum custom_layers
{
    _QWERTZ,
    _BONE2,
    _LOWER,
    _RAISE,
    _NAV,
    _ADJUST,
    _SPECIAL,
};

enum custom_keycodes
{
    QWERTZ = SAFE_RANGE,
    BONE2,
    LOWER,
    RAISE,
    NAV,
    ADJUST,
    SPECIAL,
    TABD,
    TABU
};

enum
{
    TD_R = 0,
    TD_DEL = 1,
    /* TD_LY = 1 */
};
#define KC_NAGR LT(_NAV, KC_ESC)

#define KC_ADAP LT(_ADJUST, KC_APP)

/* #define KC_RBSPC LT(_RAISE, KC_BSPC) */
#define KC_RBSP LT(_RAISE, KC_BSPC)
#define KC_ASPC LALT_T(KC_SPC)
#define KC_CENT LCTL_T(KC_ENT)

// aliases for clarity in layering
#define CTAB LCTL_T(KC_TAB)
#define ATPI LALT_T(KC_PIPE)
#define YLALT LALT_T(DE_Y)
#define TABD C(KC_PGUP)
#define TABU C(KC_PGDN)

#define U_RDO KC_AGIN
#define U_PST KC_PSTE
#define U_CPY KC_COPY
#define U_CUT KC_CUT
#define U_UND KC_UNDO

// clang-format off
#define MY_HOMEROW_LAYOUT( \
    L00, L01, L02, L03, L04, L05,           R05, R04, R03, R02, R01, R00, \
    L10, L11, L12, L13, L14, L15,           R15, R14, R13, R12, R11, R10, \
    L20, L21, L22, L23, L24, L25,           R25, R24, R23, R22, R21, R20, \
         LT1, LT2, LT3, LT4, LT5,           RT5, RT4, RT3, RT2, RT1 \
    ) \
    LAYOUT(\
    L00, L01, L02, L03, L04, L05,           R05, R04, R03, R02, R01, R00, \
    L10, L11, LCTL_T(L12), LALT_T(L13), LGUI_T(L14), L15,           R15, LGUI_T(R14), LALT_T(R13), LCTL_T(R12), R11, R10, \
    L20, L21, L22, L23, L24, L25,           R25, R24, R23, R22, R21, R20, \
         LT1, LT2, LT3, LT4, LT5,           RT5, RT4, RT3, RT2, RT1 \
   )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwertz
 *
 * ,-----------------------------------------.         ,-----------------------------------------.
 * |ESC   |   Q  |   W  |   E  |   R  |   T  |         |   Z  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |TabCtl|   A  |   S  |   D  |   F  |   G  |         |   H  |   J  |   K  |   L  |   +  |<  alt|
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |Shift |   Y  |   X  |   C  |   V  |   B  |         |   N  |   M  |   ,  |   .  |   -  |Shift |
 * .-----------------------------------------.         .-----------------------------------------.
 *                                       .------.   .-----.
 *                                       | TABD |   |TABU |
 *                    .------------------.------.   .-----.--------------------
 *                    |NAV  |  WIN |LOWER| Space|   |Enter| RAISE|ADJUST|  NAV|
 *                    .-------------------------.   .-------------------------.
 */

  [_QWERTZ] = LAYOUT(
// ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
     KC_ESC,   DE_Q,   DE_W,   DE_E,   DE_R,   DE_T,             DE_Z,   DE_U,   DE_I,   DE_O,   DE_P,KC_BSPC,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
       CTAB,   DE_A,   DE_S,   DE_D,   DE_F,   DE_G,             DE_H,   DE_J,   DE_K,   DE_L,DE_PLUS,KC_LALT,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    KC_LSFT,   DE_Y,   DE_X,   DE_C,   DE_V,   DE_B,             DE_N,   DE_M,DE_COMM, DE_DOT,DE_MINS,KC_RSFT,
// '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
                NAV,KC_LGUI, LOWER , KC_SPC,   TABD,             TABU, KC_ENT, RAISE ,KC_ADAP,SPECIAL
                        // `-------+-------+-------`         `-------+-------+-------`
   ),

  /* [_QWERTZ_HR] = MY_HOMEROW_LAYOUT( */
/* // ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------. */
  /*   KC_NAGR,   DE_Q,   DE_W,   DE_E,   DE_R,   DE_T,             DE_Z,   DE_U,   DE_I,   DE_O,   DE_P,KC_BSPC, */
/* // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------| */
  /*      CTAB,   DE_A,   DE_S,   DE_D,   DE_F,   DE_G,             DE_H,   DE_J,   DE_K,   DE_L,DE_PLUS,KC_LALT, */
/* // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------| */
  /*   KC_LSFT,   DE_Y,   DE_X,   DE_C,   DE_V,   DE_B,             DE_N,   DE_M,DE_COMM, DE_DOT,DE_MINS,KC_RSFT, */
/* // '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------' */
  /*               NAV,KC_LGUI, LOWER , KC_SPC,   TABD,             TABU, KC_ENT, RAISE , KC_ADAP,SPECIAL */
  /*                       // `-------+-------+-------`         `-------+-------+-------` */
  /*  ), */

/* BONE2
 *
 * ,-----------------------------------------.         ,-----------------------------------------.
 * |ESC   |   X  |   V  |   L  |   C  |   W  |         |   K  |   H  |   G  |   F  |   Q  |BckSpc|
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |TabCtl|   U  |   I  |   A  |   E  |   O  |         |   S  |   N  |   R  |   T  |   D  |   alt|
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |Shift |   +  |   J  |   Y  |   P  |   Z  |         |   B  |   M  |   ,  |   .  |   -  |Shift |
 * .-----------------------------------------.         .-----------------------------------------.
 *                                       .------.   .-----.
 *                                       | TABD |   |TABU |
 *                    .------------------.------.   .-----.--------------------
 *                    |NAV  |  WIN |LOWER| Space|   |Enter| RAISE|ADJUST|  NAV|
 *                    .-------------------------.   .-------------------------.
 */
  /* [_NEO2] = LAYOUT( */
/* // ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------. */
  /*   KC_NAGR,   DE_X,   DE_V,   DE_L,   DE_C,   DE_W,             DE_K,   DE_H,   DE_G,   DE_F,   DE_Q,KC_BSPC, */
/* // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------| */
  /*      CTAB,   DE_U,   DE_I,   DE_A,   DE_E,   DE_O,             DE_S,   DE_N,   DE_R,   KC_T,   DE_D,KC_LALT, */
/* // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------| */
  /*   KC_LSFT,DE_PLUS,   DE_J,   DE_Y,   DE_P,   DE_Z,             DE_B,   DE_M,DE_COMM, DE_DOT,DE_MINS,KC_RSFT, */
/* // '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------' */
  /*               NAV,KC_LGUI, LOWER , KC_SPC,   TABD,             TABU, KC_ENT, RAISE , KC_ADAP,SPECIAL */
  /*                       // `-------+-------+-------`         `-------+-------+-------` */
  /*  ), */

/* This Layout tries to emulate the Bone2 Variant of Neo2, and is intended to be used with a German QWERTZ Softwarelayout.
It has "üäöß" as it is optimized for a mix of German & English.
My favourite features are the placement of the special characters often used for programming right on the home row
and the number & navigation block combo, so you never have to move your hands from their home position.
Bone2 wiki page: http://wiki.neo-layout.org/wiki/Bone
*/

  [_BONE2] = LAYOUT(
// ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
    KC_NAGR,   DE_J,   DE_D,   DE_U,   DE_A,   DE_X,             DE_P,   DE_H,   DE_L,   DE_M,   DE_W,KC_BSPC,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
       CTAB,   DE_C,   DE_T,   DE_I,   DE_E,   DE_O,             DE_B,   DE_N,   DE_R,   KC_S,   DE_G,KC_LALT,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    KC_LSFT,DE_PLUS,   DE_F,   DE_V,   DE_Q,   DE_K,             DE_Y,   DE_Z,DE_COMM, DE_DOT,DE_MINS,KC_RSFT,
// '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
                NAV,KC_LGUI, LOWER , KC_SPC,   TABD,             TABU, KC_ENT, RAISE , KC_ADAP,SPECIAL
                        // `-------+-------+-------`         `-------+-------+-------`
   ),

  [_LOWER] = LAYOUT(
// ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
    _______,  KC_F9, KC_F10, KC_F11, KC_F12,XXXXXXX,          XXXXXXX,   KC_7,   KC_8,   KC_9,XXXXXXX,_______,
// |-------+-------+-------+-------+-------.-------,         ,-------+-------+-------+-------+-------+-------|
    _______,  KC_F5,  KC_F6,  KC_F7,  KC_F8,XXXXXXX,          XXXXXXX,   KC_4,   KC_5,   KC_6, DE_DOT,_______,
// |-------+-------+-------+-------+-------.-------,         ,-------+-------+-------+-------+-------+-------|
    _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,XXXXXXX,             KC_0,   KC_1,   KC_2,   KC_3,DE_COMM,_______,
// '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
            _______,_______,_______,_______,_______,          _______,_______,_______,_______,_______
                          // `-------+-------+-------`     `-------+-------+-------`
  ),

/* RAISE
 *
 * ,-----------------------------------------.         ,-----------------------------------------.
 * |   °  |   @  |   _  |   [  |   ]  |   ^  |         |   !  |   <  |   >  |   =  |   &  |   ´  |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |      |   \  |   /  |   {  |   }  |   *  |         |   ?  |   (  |   )  |   -  |   :  |      |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |      |   #  |   ~  |   |  |   $  |   €  |         |   +  |   %  |   "  |   '  |   ;  |      |
 * .-----------------------------------------.         .-----------------------------------------.
 *                                       .------.   .-----.
 *                                       | TABD |   |TABU|
 *                    .------------------.------.   .-----.--------------------
 *                    |NAV  |  WIN |LOWER| Space|   |Enter| RAISE|ADJUST|  NAV|
 *                    .-------------------------.   .-------------------------.
 */

  [_RAISE] = LAYOUT(
 // ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
      DE_DEG,  DE_AT,DE_UNDS,DE_LBRC,DE_RBRC,DE_CIRC,          DE_EXLM,DE_LABK,DE_RABK, DE_EQL,DE_AMPR,DE_ACUT,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
     _______,DE_BSLS,DE_SLSH,DE_LCBR,DE_RCBR,DE_ASTR,          DE_QUES,DE_LPRN,DE_RPRN,DE_MINS,DE_COLN,_______,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
     _______,DE_HASH,DE_TILD,DE_PIPE, DE_DLR,DE_EURO,          DE_PLUS,DE_PERC,DE_DQUO,DE_QUOT,DE_SCLN,_______,
 // '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
            _______,_______,_______,_______,_______,          _______,_______,_______,_______,_______
                           // `-------+-------+-------`     `-------+-------+-------`
   ),

#ifdef MOUSEKEY_ENABLE
  [_NAV] = LAYOUT(
 // ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+------- +-------+-------.
     _______,KC_WH_U,KC_BTN1,KC_MS_U,KC_BTN2,XXXXXXX,             TABD,KC_PGUP,KC_UP  ,KC_PGDN ,   TABU, KC_DEL,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+------- +-------,-------+-------|
     _______,KC_WH_D,KC_MS_L,KC_MS_D,KC_MS_R,XXXXXXX,          KC_HOME,KC_LEFT,KC_DOWN,KC_RIGHT, KC_END, KC_INS,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+------- +-------,-------+-------|
     _______,G(KC_1),G(KC_2),G(KC_3),G(KC_4),G(KC_5),          G(KC_6),G(KC_7),G(KC_8),G(KC_9) ,G(KC_0),_______,
 // '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+------- +-------+-------'
            _______,_______,_______,_______,_______,          _______,_______,_______,_______,_______
                           // `-------+-------+-------`     `-------+-------+-------`
   ),
#else
  [_NAV] = LAYOUT(
 // ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+------- +-------+-------.
     _______,  U_UND,  U_CUT,  U_CPY,  U_PST,  U_RDO,             TABD,KC_PGUP,KC_UP  ,KC_PGDN ,   TABU, KC_DEL,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+------- +-------,-------+-------|
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,          KC_HOME,KC_LEFT,KC_DOWN,KC_RIGHT, KC_END, KC_INS,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+------- +-------,-------+-------|
     _______,G(KC_1),G(KC_2),G(KC_3),G(KC_4),G(KC_5),          G(KC_6),G(KC_7),G(KC_8),G(KC_9) ,G(KC_0),_______,
 // '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+------- +-------+-------'
            _______,_______,_______,_______,_______,          _______,_______,_______,_______,_______
                           // `-------+-------+-------`     `-------+-------+-------`
   ),
#endif

  [_ADJUST] = LAYOUT(
// ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
   TD(TD_R),RGB_TOG,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI,          XXXXXXX,KC_MPRV,KC_VOLU,KC_MNXT,KC_MPLY,KC_MUTE,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    _______,XXXXXXX,XXXXXXX,RGB_HUD,RGB_SAD,RGB_VAD,          XXXXXXX,KC_BRID,KC_VOLD,KC_BRIU,XXXXXXX,XXXXXXX,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    KC_CAPS,  U_UND,  U_CUT,  U_CPY,  U_PST,  U_RDO,          QWERTZ ,BONE2  ,XXXXXXX,XXXXXXX,XXXXXXX,KC_CAPS,
// '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
            _______,_______,_______,_______,_______,          _______,_______,_______,_______,_______
                          // `-------+-------+-------`     `-------+-------+-------`
  ),

  [_SPECIAL] = LAYOUT(
// ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,          XXXXXXX,DE_UDIA,XXXXXXX,DE_ODIA,XXXXXXX,XXXXXXX,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    XXXXXXX,DE_ADIA,  DE_SS,XXXXXXX,XXXXXXX,XXXXXXX,          XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,          XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
// '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
            _______,_______,_______,_______,_______,          _______,_______,_______,_______,_______
                          // `-------+-------+-------`     `-------+-------+-------`
  ),
};

// clang-format on

#ifdef TAP_DANCE_ENABLE
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
        /* register_code(KC_LSFT); */
    }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data)
{
    /* if (state->count != 3) { */
    /* unregister_code(KC_LSFT); */
    /* } */
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, safe_reset, dance_cln_reset),
    /* [TD_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, LALT(KC_BSPC)), */
};
#endif

#ifdef COMBO_ENABLE
enum combos
{
    AE_ADIA,
    UE_UDIA,
    OE_ODIA,
    SS_SS,
};
const uint16_t PROGMEM ae_combo[] = {DE_A, DE_E COMBO_END};
const uint16_t PROGMEM ue_combo[] = {DE_U, DE_E, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {DE_O, DE_E, COMBO_END};
const uint16_t PROGMEM ss_combo[] = {DE_S, DE_S, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    [AE_ADIA] = COMBO(ae_combo, DE_ADIA),
    [UE_UDIA] = COMBO(ue_combo, DE_UDIA),
    [OE_ODIA] = COMBO(oe_combo, DE_ODIA),
    [SS_SS] = COMBO(ss_combo, DE_SS),
};
#endif // COMBO_ENABLE

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in
// rules.mk
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    if (!is_keyboard_master())
    {
        return OLED_ROTATION_90;
    }
    else
    {
        return OLED_ROTATION_90;
    }
    return rotation;
}
char luna_keylog_str[15] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd',  'e', 'f', 'g', 'h', 'i', 'j', 'k',
    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',  't', 'u', 'v', 'w', 'x', 'z', 'y',
    '1', '2', '3', '4', '5', '6', '7', '8',  '9', '0', 'R', 'E', 'B', 'T', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ';', '\'', ' ', ',', '.', '/', ' ', ' ', ' '};

void luna_set_keylog(uint16_t keycode, keyrecord_t *record)
{
    char name = ' ';
    if (keycode < 60)
    {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(luna_keylog_str, sizeof(luna_keylog_str), "%dx%d:%c",
             record->event.key.row, record->event.key.col, name);

    // update keylogs
    if (keylogs_str_idx == sizeof(keylogs_str) - 1)
    {
        keylogs_str_idx = 0;
        for (int i = 0; i < sizeof(keylogs_str) - 1; i++)
        {
            keylogs_str[i] = ' ';
        }
    }

    keylogs_str[keylogs_str_idx] = name;
    keylogs_str_idx++;
}

/* uint32_t idle_timer = 0; */
bool last_rgb_state = false;
/* static bool display_on = true; */
#ifdef CAT_ENABLE
#include "bongo.c"
#endif // CAT_ENABLE
#include "luna.c"

static void print_status_narrow(void)
{
    /* Print current mode */
    oled_set_cursor(0, 0);

    /** oled_set_cursor(0, 3); */

    switch (get_highest_layer(default_layer_state))
    {
        case _QWERTZ:
            oled_write("QWRTZ", false);
            break;
        /* case _QWERTZ_HR: */
        /*     oled_write("QWTZH", false); */
        /*     break; */
        case _BONE2:
            oled_write("BONE2", false);
            break;
        default:
            oled_write("UNDEF", false);
    }

    oled_set_cursor(0, 3);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 4);

    switch (get_highest_layer(layer_state))
    {
        case _QWERTZ:
        /* case _QWERTZ_HR: */
        case _BONE2:
            oled_write("Base ", false);
            break;
        case _RAISE:
            oled_write("Raise", false);
            break;
        case _LOWER:
            oled_write("Lower", false);
            break;
        case _ADJUST:
            oled_write("Adj  ", false);
            break;
        case _NAV:
            oled_write("Nav  ", false);
            break;
        case _SPECIAL:
            oled_write("Spezi", false);
            break;
        default:
            oled_write("Undef", false);
    }

    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state();
    /* caps lock */
    oled_set_cursor(0, 7);
    oled_write("CPSLK", led_usb_state.caps_lock);

    oled_set_cursor(0, 10);
    oled_write(luna_keylog_str, false);

    /* KEYBOARD PET RENDER START */

    render_luna(0, 13);

    /* KEYBOARD PET RENDER END */
}
#ifndef CAT_ENABLE
static void render_qmk_logo(void)
{
    /* static const char PROGMEM qmk_logo[] = { */
    /*     0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, */
    /*     0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, */
    /*     0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, */
    /*     0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, */
    /*     0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, */
    /*     0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0}; */
    /* static const char PROGMEM qmk_logo[] = { */
    /*     0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A,
     * 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, */
    /*     0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA,
     * 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, */
    /*     0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA,
     * 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00 */
    /* }; */
    static const char PROGMEM tux_logo[] = {153, 154, 10, 185, 186, 0};

    oled_write_P(tux_logo, false);
}
#endif // CAT_ENABLE
void oled_task_user(void)
{
    /* KEYBOARD PET VARIABLES START */

    current_wpm = get_current_wpm();
    /** led_usb_state = host_keyboard_led_state(); */

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master())
    {
        if (last_input_activity_elapsed() >= OLED_TIMEOUT && current_wpm == 0)
        {
            oled_off();
        }
        else
        {
            print_status_narrow();
        }
    }
    else
    {
        if (is_oled_on())
        {
#ifdef CAT_ENABLE
            bongo_render_anim();
#else
            render_qmk_logo();
#endif // CAT_ENABLE
            oled_set_cursor(0, 12);
            sprintf(wpm_str, "WPM\n%03d", get_current_wpm());
            oled_write(wpm_str, false);
        }
    }
}

#endif // OLED_ENABLE

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    mod_state = get_mods();
    if (record->event.pressed)
    {
#ifdef OLED_ENABLE
        luna_set_keylog(keycode, record);
#endif
    }
    switch (keycode)
    {
        case QWERTZ:
            if (record->event.pressed)
            {
                layer_clear();
                set_single_persistent_default_layer(_QWERTZ);
            }
            return false;
            break;
        /* case QWRTZ_H: */
        /*     if (record->event.pressed) */
        /*     { */
        /*         layer_clear(); */
        /*         set_single_persistent_default_layer(_QWERTZ_HR); */
        /*     } */
        /*     return false; */
        /*     break; */
        case BONE2:
            if (record->event.pressed)
            {
                layer_clear();
                set_single_persistent_default_layer(_BONE2);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed)
            {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _SPECIAL);
            }
            else
            {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _SPECIAL);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed)
            {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _SPECIAL);
            }
            else
            {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _SPECIAL);
            }
            return false;
            break;
        case NAV:
            if (record->event.pressed)
            {
                layer_on(_NAV);
            }
            else
            {
                layer_off(_NAV);
            }
            return false;
            break;
        case SPECIAL:
            if (record->event.pressed)
            {
                layer_on(_SPECIAL);
            }
            else
            {
                layer_off(_SPECIAL);
            }
            return false;
            break;
                /* KEYBOARD PET STATUS START */
        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed)
            {
                isSneaking = true;
            }
            else
            {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed)
            {
                isJumping = true;
                showedJump = false;
            }
            else
            {
                isJumping = false;
            }
            break;
            /* KEYBOARD PET STATUS END */
            // Ä & ä
            /* case DE_A: */
            /*     if (mod_state & MOD_MASK_ALT) */
            /*     { */
            /*         if (record->event.pressed) */
            /*         { */
            /*             unregister_code(KC_LALT); */
            /*             unregister_code(KC_RALT); */

            /*             tap_code(DE_ADIA); */

            /*             set_mods(mod_state); */
            /*         } */
            /*         return false; */
            /*     } */
            /*     return true; */
            /*     break; */
            /* // Ö & ö */
            /* case DE_O: */
            /*     if (mod_state & MOD_MASK_ALT) */
            /*     { */
            /*         if (record->event.pressed) */
            /*         { */
            /*             unregister_code(KC_LALT); */
            /*             unregister_code(KC_RALT); */

            /*             tap_code(DE_ODIA); */

            /*             set_mods(mod_state); */
            /*         } */
            /*         return false; */
            /*     } */
            /*     return true; */
            /*     break; */
            /* // Ö & ö */
            /* case DE_U: */
            /*     if (mod_state & MOD_MASK_ALT) */
            /*     { */
            /*         if (record->event.pressed) */
            /*         { */
            /*             unregister_code(KC_LALT); */
            /*             unregister_code(KC_RALT); */

            /*             tap_code(DE_UDIA); */

            /*             set_mods(mod_state); */
            /*         } */
            /*         return false; */
            /*     } */
            /*     return true; */
            /*     break; */
            /* // ß */
            /* case DE_S: */
            /*     if (mod_state & MOD_MASK_ALT) */
            /*     { */
            /*         if (record->event.pressed) */
            /*         { */
            /*             unregister_code(KC_LALT); */
            /*             unregister_code(KC_RALT); */

            /*             tap_code(DE_SS); */

            /*             set_mods(mod_state); */
            /*         } */
            /*         return false; */
            /*     } */
            /*     return true; */
            /*     break; */
    }

    return true;
}

/* void matrix_scan_user(void) */
/* { */
/*     // idle_timer needs to be set one time */
/*     if (idle_timer == 0) */
/*         idle_timer = timer_read(); */
/* } */
