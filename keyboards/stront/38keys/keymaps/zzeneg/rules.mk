VIA_ENABLE = yes
VIAL_ENABLE = yes
VIALRGB_ENABLE = yes

QMK_SETTINGS = no
TAP_DANCE_ENABLE = no

EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
ENCODER_MAP_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes

RAW_ENABLE = yes

SRC +=  zzeneg_display.c \
		fonts/montserrat_20_en_ru.c \
		fonts/montserrat_48_digits.c \
		icons/flag_uk.c \
		icons/flag_ru.c
