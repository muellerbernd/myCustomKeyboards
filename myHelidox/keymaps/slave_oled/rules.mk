RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
OLED_ENABLE = yes
WPM_ENABLE = yes
LTO_ENABLE = yes            # significantly reduce the compiled size, but disable the legacy TMK Macros and Functions features
EXTRAFLAGS += -flto
# CONSOLE_ENABLE = yes
