ENCODER_MAP_ENABLE = yes

VIA_ENABLE = yes
VIAL_ENABLE = yes

RGBLIGHT_ENABLE = no # enable if custom code for status LED is added (like RGB Layers)

# enable/disable features to reduce firmware size
# BOOTMAGIC_ENABLE = no
# MOUSEKEY_ENABLE = no
# SPACE_CADET_ENABLE = no
# GRAVE_ESC_ENABLE = no
# QMK_SETTINGS = no
# TAP_DANCE_ENABLE = no
# COMBO_ENABLE = no
# KEY_OVERRIDE_ENABLE = no

# disable features to reduce firmware size for rev1
ifeq ($(strip $(MCU)), atmega32u4)
	MOUSEKEY_ENABLE = no
	KEY_OVERRIDE_ENABLE = no
	GRAVE_ESC_ENABLE = no
	SPACE_CADET_ENABLE = no
endif
