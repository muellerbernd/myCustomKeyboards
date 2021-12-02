LTO_ENABLE = yes            # significantly reduce the compiled size, but disable the legacy TMK Macros and Functions features
TAP_DANCE_ENABLE = yes
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes
EXTRAFLAGS+=-flto
# EXTRAFLAGS += -ffat-lto-objects
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control

COMBO_ENABLE = no
# CONSOLE_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no# If you want to change the display of OLED, you need to change here
SRC += ./lib/keylogger.c \
	./lib/layer_state_reader.c \
	# ./lib/logo_reader.c \
	# ./lib/rgb_state_reader.c \
	# ./lib/mode_icon_reader.c \
	# ./lib/host_led_state_reader.c \
	# ./lib/timelogger.c \
