MOUSEKEY_ENABLE     = yes
RGBLIGHT_ENABLE     = no
OLED_ENABLE         = yes
LTO_ENABLE          = yes
COMBO_ENABLE        = yes
BOOTLOADER          = atmel-dfu
VIA_ENABLE          = no
RGB_MATRIX_ENABLE   = yes
CONSOLE_ENABLE      = no
MIDI_ENABLE         = no
TERMINAL_ENABLE     = no
AUDIO_ENABLE        = no
UNICODE_ENABLE      = no
UNICODEMAP_ENABLE   = no
BLUETOOTH_ENABLE    = no
FAUXCLICKY_ENABLE   = no
HD44780_ENABLE      = no
COMMAND_ENABLE      = no
MUSIC_ENABLE        = no
AUTO_SHIFT_ENABLE   = no
WEBUSB_ENABLE       = no
EXTRAKEY_ENABLE     = yes
SPACE_CADET_ENABLE  = no
GRAVE_ESC_ENABLE    = no
MAGIC_ENABLE        = no
BOOTMAGIC_ENABLE    = no
RAW_ENABLE          = yes

EXTRAFLAGS += -flto

SRC += \
    ./lib/rgb_state_reader.c \
    ./features/layer_lock.c \
    ./features/select_word.c \
    ./rgb/rgb_indicators.c \
    ./utils/keylog.c \
    ./init/init_user.c \
    ./handlers/keycode_handler.c \
    ./combos/combos.c \
    ./combos/combos_git.c \
    ./combos/combos_media.c \
    ./combos/combos_misc.c \
    ./combos/combos_spanish.c \
    ./combos/combos_symbols.c \
    ./combos/combos_control.c \
    ./combos/combos_function.c
