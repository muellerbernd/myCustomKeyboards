#pragma once
#ifdef AUDIO_ENABLE
#define AUDIO_INIT_DELAY
#define STARTUP_SONG SONG(STARTUP_SOUND)
#define GOODBYE_SONG SONG(GOODBYE_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#define DEFAULT_LAYER_SONGS                                                    \
    {                                                                          \
        SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND),           \
            SONG(COLEMAK_SOUND)                                                \
    }
#endif
/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

// #define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and
 * allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
// #define ENCODER_RESOLUTION 4
//
#define MUSIC_MASK (keycode != KC_NO)
//  If your board is too loud for you or your coworkers, you can set the max
//  using
#define AUDIO_DAC_SAMPLE_MAX 4095U

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 200
// #define TAPPING_TERM_PER_KEY
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD
// This makes tap and hold keys (like Layer Tap) work better for fast typists,
// or for high TAPPING_TERM settings.
#define PERMISSIVE_HOLD
// For instance, holding and releasing LT(2, KC_SPACE) without hitting another
// key will result in nothing happening. With this enabled, it will send
// KC_SPACE instead. #define RETRO_TAPPING

// Auto Shift
// #define NO_AUTO_SHIFT_ALPHA
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define AUTO_SHIFT_NO_SETUP

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 64

// shave off some byte from firmware
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION
// allow only 8 layers
// #define LAYER_STATE_16BIT
#define LAYER_STATE_8BIT
// #undef LOCKING_SUPPORT_ENABLE
// #undef LOCKING_RESYNC_ENABLE

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

#ifdef LEADER_ENABLE
#define LEADER_TIMEOUT 300
#else
#define DISABLE_LEADER
#endif // LEADER_ENABLE

