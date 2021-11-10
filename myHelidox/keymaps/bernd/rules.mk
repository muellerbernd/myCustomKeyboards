TAP_DANCE_ENABLE = yes
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
OLED_DRIVER_ENABLE = yes
WPM_ENABLE = yes
LTO_ENABLE = yes            # significantly reduce the compiled size, but disable the legacy TMK Macros and Functions features
EXTRAFLAGS += -flto
COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes
