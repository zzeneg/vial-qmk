QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
QUANTUM_PAINTER_DRIVERS = gc9a01_spi

SRC += lvgl_helpers.c \
	   display.c \
	   fonts/montserrat_20_en.c
