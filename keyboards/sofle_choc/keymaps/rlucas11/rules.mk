ENCODER_ENABLE = yes

OLED_ENABLE = no

CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID


# Enable per-key lighting
RGB_MATRIX_ENABLE = yes

# Enable audio keys and system control
EXTRAKEY_ENABLE = yes

# Enable link time optimization
# Trade longer compile time for smaller firmware size
LTO_ENABLE = yes

# My changes
MOUSEKEY_ENABLE = yes        # Mouse keys

TAP_DANCE_ENABLE = yes

MOUSEKEY_DELAY = 25
MOUSEKEY_MAX_SPEED = 12

