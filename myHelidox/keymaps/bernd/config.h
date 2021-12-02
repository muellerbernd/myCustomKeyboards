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
// #define RGBLIGHT_HUE_STEP 8
// #define RGBLIGHT_SAT_STEP 8
// #define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SPLIT // sync LEDs between RIGHT and LEFT hand
// #define RGBLIGHT_MODE_STATIC_LIGHT
// #define RGBLED_SPLIT { 10, 10 }
// #define RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// time in ms to do tap dance
// #define TAPPING_TERM 100
// #define RETRO_TAPPING
// #define PERMISSIVE_HOLD

// #define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define DISABLE_LEADER
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

// #define OLED_TIMEOUT 2000
// #define OLED_BRIGHTNESS 120
// #define OLED_FADE_OUT true
#define LAYER_STATE_8BIT
