/**
 * File              : config.h
 * Author            : Bernd Müller <bernd@muellerbernd.de>
 * Date              : 29.11.2021
 * Last Modified Date: 07.01.2022
 * Last Modified By  : Bernd Müller <bernd@muellerbernd.de>
 */
#include "config_common.h"
#include "users/muellerbernd/common_conf.h"
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

#undef RGBLED_NUM
/* ws2812 RGB LED */
#define RGB_DI_PIN D4
#define RGBLED_NUM 10

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODERS_PAD_A_RIGHT { F5 }
#define ENCODERS_PAD_B_RIGHT { F4 }
#define ENCODER_RESOLUTION 4
#endif // ENCODER_ENABLE

