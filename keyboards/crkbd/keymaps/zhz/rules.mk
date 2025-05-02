MOUSEKEY_ENABLE     = yes    # Mouse keys
VIA_ENABLE          = no         # Enable VIA
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
CONSOLE_ENABLE = no
MIDI_ENABLE = no
TERMINAL_ENABLE = no
AUDIO_ENABLE = no
UNICODE_ENABLE = no         # Unicode
UNICODEMAP_ENABLE = no
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
HD44780_ENABLE = no
COMMAND_ENABLE = no
MUSIC_ENABLE = no
AUTO_SHIFT_ENABLE = no
WEBUSB_ENABLE = no # might just be for Oryx
EXTRAKEY_ENABLE = yes # media/volume keys
SPACE_CADET_ENABLE = no # parentheses when tapping left/right mods
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
BOOTMAGIC_ENABLE = no


LTO_ENABLE = yes
EXTRAFLAGS += -flto

SRC +=  ./lib/rgb_state_reader.c \
        ./features/layer_lock.c \
		./features/select_word.c


