#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include <stdio.h>
char wpm_str[10];
// Each layer gets a name for readability, which is then used in the keymap
// matrix below. The underscores don't mean anything - you can have a layer
// called STUFF or any other name. Layer names don't all need to be of the same
// length, obviously, and you can also skip them entirely and just use numbers.

enum custom_layers
{
    _QWERTZ,
    _DVORAK,
    _LOWER,
    _RAISE,
    _NAV,
    _ADJUST,
};

enum custom_keycodes
{
    QWERTZ = SAFE_RANGE,
    DVORAK,
    LOWER,
    RAISE,
    NAV,
    ADJUST,
};

enum
{
    TD_R = 0
    /** TD_LY = 1 */
};

// combos
/** const uint16_t PROGMEM ae_combo[] = {DE_A, DE_E, COMBO_END}; */
/** const uint16_t PROGMEM ue_combo[] = {DE_U, DE_E, COMBO_END}; */
/** const uint16_t PROGMEM oe_combo[] = {DE_O, DE_E, COMBO_END}; */
/** combo_t key_combos[COMBO_COUNT] = { */
/**     COMBO(ae_combo, DE_AE), */
/**     COMBO(oe_combo, DE_OE), */
/**     COMBO(ue_combo, DE_UE), */
/** }; */

#define KC_NAGR LT(_NAV, KC_ESC)

#define KC_ADAP LT(_ADJUST, KC_APP)

#define KC_CTAB CTL_T(KC_TAB)
#define KC_ALPI ALT_T(PIPE)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define KC_NAV MO(_NAV)

#define KC_DV TG(_DVORAK)

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
 *
 * ,-----------------------------------------.         ,-----------------------------------------.
 * |ESC   |   Q  |   W  |   E  |   R  |   T  |         |   Z  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |TabCtl|   A  |   S  |   D  |   F  |   G  |         |   H  |   J  |   K  |   L  |   +  |<  alt|
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |Shift |   Y  |   X  |   C  |   V  |   B  |         |   N  |   M  |   ,  |   .  |   -  |Shift |
 * .-----------------------------------------.         .-----------------------------------------.
 *                                       .------.   .-----.
 *                                       | CTL  |   | ALT |
 *                    .------------------.------.   .-----.--------------------
 *                    |NAV  |  WIN |LOWER| Space|   |Enter| RAISE|ADJUST|  NAV|
 *                    .-------------------------.   .-------------------------.
 */
  [_QWERTZ] = LAYOUT(
// ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
    KC_NAGR,   DE_Q,   DE_W,   DE_E,   DE_R,   DE_T,             DE_Z,   DE_U,   DE_I,   DE_O,   DE_P,KC_BSPC,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
       CTAB,   DE_A,   DE_S,   DE_D,   DE_F,   DE_G,             DE_H,   DE_J,   DE_K,   KC_L,DE_PLUS,   ATPI,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    KC_LSFT,   DE_Y,   DE_X,   DE_C,   DE_V,   DE_B,             DE_N,   DE_M,DE_COMM, DE_DOT,DE_MINS,KC_RSFT,
// '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
            KC_NAV ,KC_LGUI, LOWER , KC_SPC,KC_LCTL,          KC_LALT,KC_ENT , RAISE ,KC_ADAP,KC_NAV
                        // `-------+-------+-------`         `-------+-------+-------`
   ),

/**   [_DVORAK] = LAYOUT( */
/** // ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------. */
/**     KC_NAGR,DE_SCLN,DE_COMM, DE_DOT,   DE_P,   DE_Y,             DE_F,   DE_G,   DE_C,   DE_R,   DE_L,KC_BSPC, */
/** // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------| */
/**        CTAB,   DE_A,   DE_O,   DE_E,   DE_U,   DE_I,             DE_D,   DE_H,   DE_T,   KC_N,   DE_S,   ATPI, */
/** // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------| */
/**     KC_LSFT,DE_QUOT,   DE_Q,   DE_J,   DE_K,   DE_X,             DE_B,   DE_M,   DE_W,   DE_V,   DE_Z,KC_RSFT, */
/** // '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------' */
/**             KC_RASE,KC_LGUI,KC_LOWR, KC_SPC,KC_LCTL,          KC_LALT,KC_ENT ,KC_RASE,KC_ADAP,KC_LOWR */
/**                         // `-------+-------+-------`         `-------+-------+-------` */
/**    ), */


  [_LOWER] = LAYOUT(
// ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
    _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,             KC_6,   KC_7,   KC_8,   KC_9,   KC_0,_______,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,            KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,_______,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, KC_F11,           KC_F12,XXXXXXX,_______,_______,_______,_______,
// '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
            _______,_______,_______,_______,_______,          _______,_______,_______,_______,_______
                          // `-------+-------+-------`     `-------+-------+-------`
  ),

/* RAISE
 *
 * ,-----------------------------------------.         ,-----------------------------------------.
 * |   _  |   @  |   $  |   €  |   %  |   (  |         |   )  |   ü  |   `  |   ö  |   =  |   -  |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |      |   ä  |   ß  |   ^  |   <  |   [  |         |   ]  |   >  |   §  |   &  |   ~  |   +  |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |      |   '  |   "  |   |  |   /  |   {  |         |   }  |   \  |   !  |   ?  |   #  |   *  |
 * .-----------------------------------------.         .-----------------------------------------.
 *                                       .------.   .-----.
 *                                       | CTL  |   | ALT |
 *                    .------------------.------.   .-----.--------------------
 *                    |NAV  |  WIN |LOWER| Space|   |Enter| RAISE|ADJUST|  NAV|
 *                    .-------------------------.   .-------------------------.
 */

  [_RAISE] = LAYOUT(
 // ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
     DE_UNDS,  DE_AT, DE_DLR,DE_EURO,DE_PERC,DE_LPRN,          DE_RPRN,  DE_UE, DE_GRV,  DE_OE, DE_EQL,DE_MINS,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
     _______,  DE_AE,  DE_SS,DE_CIRC,DE_LESS,DE_LBRC,          DE_RBRC,DE_MORE,DE_PARA,DE_AMPR,DE_TILD,DE_PLUS,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
     _______,DE_QUOT,DE_DQUO,DE_PIPE,DE_SLSH,DE_LCBR,          DE_RCBR,DE_BSLS,DE_EXLM, DE_QST,DE_HASH,DE_ASTR,
 // '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
            _______,_______,_______,_______,_______,          _______,_______,_______,_______,_______
                           // `-------+-------+-------`     `-------+-------+-------`
   ),

  [_NAV] = LAYOUT(
 // ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+------- +-------+-------.
     XXXXXXX,KC_WH_U,KC_BTN1,KC_MS_U,KC_BTN2,KC_HOME,          KC_END ,KC_PGUP,KC_UP  ,KC_PGDN ,XXXXXXX, KC_DEL,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+------- +-------,-------+-------|
     XXXXXXX,KC_WH_D,KC_MS_L,KC_MS_D,KC_MS_R,TABD   ,          TABU   ,KC_LEFT,KC_DOWN,KC_RIGHT,XXXXXXX,XXXXXXX,
 // |-------+-------+-------+-------+-------+-------.         ,-------+-------+------- +-------,-------+-------|
     _______,G(KC_1),G(KC_2),G(KC_3),G(KC_4),G(KC_5),          G(KC_6),G(KC_7),G(KC_8),G(KC_9) ,G(KC_0),_______,
 // '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+------- +-------+-------'
            _______,_______,_______,_______,_______,          _______,_______,_______,_______,_______
                           // `-------+-------+-------`     `-------+-------+-------`
   ),

  [_ADJUST] = LAYOUT(
// ,-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------.
   TD(TD_R),RGB_TOG,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI,          XXXXXXX,KC_MPRV,KC_VOLU,KC_MNXT,XXXXXXX,KC_MUTE,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    XXXXXXX,XXXXXXX,XXXXXXX,RGB_HUD,RGB_SAD,RGB_VAD,          XXXXXXX,KC_BRID,KC_VOLD,KC_BRIU,XXXXXXX,XXXXXXX,
// |-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------|
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,          QWERTZ ,KC_DV  ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
// '-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------'
            _______,_______,_______,KC_MPLY,_______,          _______,_______,_______,_______,_______
                          // `-------+-------+-------`     `-------+-------+-------`
  )
};

// clang-format on
/** void matrix_init_user(void) { set_single_persistent_default_layer(_QWERTZ);
 * }; */

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

/** bool win_held; */
/** void dance_layers(qk_tap_dance_state_t *state, void *user_data) */
/** { */
/**     if (state->pressed) */
/**     { */
/**         [> layer_on(_ADJUST); <] */
/**         register_code(KC_LGUI); */
/**         win_held = true; */
/**     } */
/**     switch (state->count) */
/**     { */
/**         case 1: // off all layers, just base on */
/**             if (!state->pressed) */
/**             { */
/**                 layer_off(_ADJUST); */
/**                 layer_off(_LOWER); */
/**                 layer_off(_RAISE); */
/**                 layer_off(_NAV); */
/**                 win_held = false; */
/**             } */
/**             break; */
/**         case 2: // raise */
/**             layer_on(_RAISE); */
/**             layer_off(_LOWER); */
/**             layer_off(_NAV); */
/**             layer_off(_ADJUST); */
/**             break; */
/**         case 3: // lower */
/**             layer_on(_LOWER); */
/**             layer_off(_RAISE); */
/**             layer_off(_NAV); */
/**             layer_off(_ADJUST); */
/**             break; */
/**         case 4: // nav */
/**             layer_off(_LOWER); */
/**             layer_off(_RAISE); */
/**             layer_on(_NAV); */
/**             layer_off(_ADJUST); */
/**             break; */
/**         case 5: // adjust */
/**             layer_off(_LOWER); */
/**             layer_off(_RAISE); */
/**             layer_off(_NAV); */
/**             layer_on(_ADJUST); */
/**             break; */
/**     } */
/** } */
/** void dance_layers_finish(qk_tap_dance_state_t *state, void *user_data) */
/** { */
/**     if (win_held) */
/**     { */
/**         [> layer_off(_ADJUST); <] */
/**         win_held = false; */
/**     } */
/**     unregister_code(KC_LGUI); */
/** } */

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, safe_reset, dance_cln_reset),
    /** [TD_LY] = */
    /** ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layers, dance_layers_finish) */
};

// SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in
// rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    if (!is_keyboard_master())
        return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);

const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

#ifdef WPM_ENABLE
// WPM-responsive animation stuff here
#define IDLE_FRAMES 1
#define IDLE_SPEED 20 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 30 // above this wpm value typing animation to trigger

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs
// fixing
#define ANIM_SIZE                                                              \
    513 // number of bytes in array, minimize for adequate firmware size, max is
        // 1024

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

// Code containing pixel art, contains:
// 2 idle frames, 1 prep frame, and 2 tap frames

// To make your own pixel art:
// save a png/jpeg of an 128x32 image (resource: https://www.pixilart.com/draw )
// follow this guide up to and including "CONVERT YOUR IMAGE"
// https://docs.splitkb.com/hc/en-us/articles/360013811280-How-do-I-convert-an-image-for-use-on-an-OLED-display-
// replace numbers in brackets with your own
// if you start getting errors when compiling make sure you didn't accedentally
// delete a bracket
static void render_anim(void)
{

    // assumes 1 frame prep stage
    void animation_phase(void)
    {
        /** if (get_current_wpm() <= IDLE_SPEED) */
        /** { */
        /**     current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES; */
        /**     oled_write_raw_P(idle[abs((IDLE_FRAMES - 1) -
         * current_idle_frame)], */
        /**                      ANIM_SIZE); */
        /** } */
        /** if (get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED)
         */
        /** { */
        /**     //
         * oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], */
        /**     // ANIM_SIZE); // uncomment if IDLE_FRAMES >1 */
        /**     oled_write_raw_P(prep[0], ANIM_SIZE); // remove if IDLE_FRAMES
         * >1 */
        /** } */
        /** if (get_current_wpm() >= TAP_SPEED) */
        /** { */
        /**     current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES; */
        /**     oled_write_raw_P(tap[abs((TAP_FRAMES - 1) - current_tap_frame)],
         */
        /**                      ANIM_SIZE); */
        /** } */
    }
    if (get_current_wpm() != 000)
    {
        oled_on(); // not essential but turns on animation OLED with any alpha
                   // keypress
        if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION)
        {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    }
    else
    {
        if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT)
        {
            oled_off();
        }
        else
        {
            if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION)
            {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}
#endif // WPM_ENABLE

void oled_task_user(void)
{
    if (is_keyboard_master())
    {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        /** oled_write_ln(read_keylogs(), false); */
    }
    else
    {
#ifdef WPM_ENABLE
        /** oled_write(read_logo(), false); */
        render_anim(); // renders pixelart

        oled_set_cursor(0, 0); // sets cursor to (row, column) using charactar
                               // spacing (5 rows on 128x32 screen, anything
                               // more will overflow back to the top)
        sprintf(
            wpm_str, "WPM:%03d",
            get_current_wpm()); // edit the string to change wwhat shows up,
                                // edit %03d to change how many digits show up
        oled_write(wpm_str, false); // writes wpm on top left corner of string

#endif // WPM_ENABLE
    }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (record->event.pressed)
    {
#ifdef OLED_DRIVER_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
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
    }
    return true;
}
