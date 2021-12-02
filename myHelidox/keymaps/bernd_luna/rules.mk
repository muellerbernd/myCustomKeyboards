# File              : rules.mk
# Author            : Bernd Müller <bernd@muellerbernd.de>
# Date              : 29.11.2021
# Last Modified Date: 30.11.2021
# Last Modified By  : Bernd Müller <bernd@muellerbernd.de>
TAP_DANCE_ENABLE = yes
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control

LTO_ENABLE = yes            # significantly reduce the compiled size, but disable the legacy TMK Macros and Functions features
EXTRAFLAGS+=-flto
# EXTRAFLAGS += -ffat-lto-objects
COMBO_ENABLE = no
# CONSOLE_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
