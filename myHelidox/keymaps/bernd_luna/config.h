/**
 * File              : config.h
 * Author            : Bernd Müller <bernd@muellerbernd.de>
 * Date              : 29.11.2021
 * Last Modified Date: 29.11.2021
 * Last Modified By  : Bernd Müller <bernd@muellerbernd.de>
 */
#include "config_common.h"
/*

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#undef USE_I2C
// #define USE_SERIAL
/* Use I2C or Serial, not both */
// #define USE_SERIAL_PD2
// #define USE_SERIAL
#define SOFT_SERIAL_PIN D2

// #define USE_I2C
/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS
#define SPLIT_WPM_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
// #define SPLIT_USB_DETECT
#define SPLIT_OLED_ENABLE

#undef RGBLED_NUM
/* ws2812 RGB LED */
#define RGB_DI_PIN D4
#define RGBLED_NUM 10
#define RGBLIGHT_SPLIT // sync LEDs between RIGHT and LEFT hand

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

// shave off some byte from firmware
// #define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define DISABLE_LEADER
// allow only 8 layers
#define LAYER_STATE_8BIT

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

#define OLED_TIMEOUT 60000
// #define OLED_BRIGHTNESS 120
// #define OLED_FADE_OUT true

#define COMBO_COUNT 4
#define CAT_ENABLE
