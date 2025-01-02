// Copyright 2024 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "hid_display.h"
#include "display.h"
#include "lvgl_helpers.h"

uint16_t connection_timer  = 0;
uint16_t home_screen_timer = 0;
uint16_t volume_timer      = 0;
uint8_t  volume            = 0;

/* screens */
static lv_obj_t *screen_home;
static lv_obj_t *screen_media;

/* home screen content */
static lv_obj_t *label_time;
static lv_obj_t *label_volume;
static lv_obj_t *label_layer;
static lv_obj_t *label_caps;
static lv_obj_t *label_layout;

/* media screen content */
static lv_obj_t *label_media_artist;
static lv_obj_t *label_media_title;

static void set_layout_label(uint8_t layout) {
    char layouts[sizeof(MOLEKULA_HID_LAYOUTS)];
    strcpy(layouts, MOLEKULA_HID_LAYOUTS);
    char *layout_str = strtok(layouts, ",");

    size_t i = 0;
    while (layout_str != NULL && i < layout) {
        i++;
        layout_str = strtok(NULL, ",");
    }

    if (layout_str != NULL) {
        lv_label_set_text(label_layout, layout_str);
    } else {
        lv_label_set_text_fmt(label_layout, "%i", layout);
    }
}

static void read_string(uint8_t *data, char *string_data) {
    uint8_t data_length = data[1];
    memcpy(string_data, data + 2, data_length);
    string_data[data_length] = '\0';
}

static void start_home_screen_timer(void) {
    dprint("start_home_screen_timer\n");
    home_screen_timer = timer_read();
}

static void init_screen_home_custom(void) {
    screen_home = lv_scr_act();
    lv_obj_add_style(screen_home, &style_screen, 0);
    use_flex_column(screen_home);
    lv_obj_align(screen_home, LV_ALIGN_TOP_MID, 0, 10);

    label_volume = lv_label_create(screen_home);
    lv_label_set_text(label_volume, "Vol: N/A");
    lv_obj_add_style(label_volume, &style_text, LV_PART_MAIN);

    label_layer = lv_label_create(screen_home);
    lv_label_set_text(label_layer, "");
    lv_obj_add_style(label_layer, &style_text, LV_PART_MAIN);

    label_time = lv_label_create(screen_home);
    lv_label_set_text(label_time, "molekula");
    lv_obj_add_style(label_time, &style_text, LV_PART_MAIN);
    lv_obj_set_style_text_font(label_time, &lv_font_montserrat_48, LV_PART_MAIN);

    label_caps = create_button(screen_home, "CAPS", &style_button, &style_button_active);

    label_layout = lv_label_create(screen_home);
    lv_label_set_text(label_layout, "");
    lv_obj_add_style(label_layout, &style_text, LV_PART_MAIN);
}

static void init_screen_media(void) {
    screen_media = lv_obj_create(NULL);
    lv_obj_add_style(screen_media, &style_screen, 0);
    use_flex_column(screen_media);
    lv_obj_set_flex_align(screen_media, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    label_media_artist = lv_label_create(screen_media);
    lv_label_set_text(label_media_artist, "N/A");
    lv_label_set_long_mode(label_media_artist, LV_LABEL_LONG_WRAP);
    lv_obj_add_style(label_media_artist, &style_text, LV_PART_MAIN);
    lv_obj_set_width(label_media_artist, lv_pct(90));
    lv_obj_set_style_text_align(label_media_artist, LV_TEXT_ALIGN_CENTER, 0);

    label_media_title = lv_label_create(screen_media);
    lv_label_set_text(label_media_title, "N/A");
    lv_label_set_long_mode(label_media_title, LV_LABEL_LONG_WRAP);
    lv_obj_add_style(label_media_title, &style_text, LV_PART_MAIN);
    lv_obj_set_width(label_media_title, lv_pct(90));
    lv_obj_set_style_text_align(label_media_title, LV_TEXT_ALIGN_CENTER, 0);
}

bool display_init_user(void) {
    init_screen_home_custom();
    init_screen_media();

    return false;
}

void display_process_raw_hid_data(uint8_t *data, uint8_t length) {
    connection_timer  = timer_read();
    uint8_t data_type = data[0];
    char    string_data[length - 2];
    dprintf("display_process_raw_hid_data - received data_type %u \n", data_type);
    switch (data_type) {
        case _TIME:
            dprintf("time %02d:%02d\n", data[1], data[2]);
            lv_label_set_text_fmt(label_time, "%02d:%02d", data[1], data[2]);
            break;

        case _VOLUME:
            dprintf("volume %d\n", data[1]);
            volume = data[1];
            // add delay to overcome issues with fast changing volume
            volume_timer = timer_read();
            break;

        case _LAYOUT:
            dprintf("layout %d\n", data[1]);
            set_layout_label(data[1]);
            break;

        case _MEDIA_ARTIST:
            read_string(data, string_data);
            dprintf("media artist %s\n", string_data);
            lv_label_set_text(label_media_artist, string_data);
            if (lv_scr_act() != screen_media) {
                lv_scr_load(screen_media);
            }
            start_home_screen_timer();
            break;

        case _MEDIA_TITLE:
            read_string(data, string_data);
            dprintf("media title %s\n", string_data);
            lv_label_set_text(label_media_title, string_data);
            if (lv_scr_act() != screen_media) {
                lv_scr_load(screen_media);
            }
            start_home_screen_timer();
            break;
    }
}

void display_set_layer(const char *layer_name) {
    lv_label_set_text(label_layer, layer_name);
}

void display_housekeeping_task(void) {
    if (volume_timer && timer_elapsed(volume_timer) > 50) {
        printf("set label_volume to %i \n", volume);
        volume_timer = 0;
        lv_label_set_text_fmt(label_volume, "Vol: %i%%", volume);
    }

    if (home_screen_timer && timer_elapsed(home_screen_timer) > 5000) {
        printf("lv_scr_load screen_home \n");
        home_screen_timer = 0;
        lv_scr_load(screen_home);
    }

    if (connection_timer && timer_elapsed(connection_timer) > 65000) {
        connection_timer = 0;
        lv_label_set_text(label_time, "molekula");
        lv_label_set_text(label_volume, "");
        lv_label_set_text(label_layout, "");
    }
}

void display_process_caps(bool active) {
    toggle_state(label_caps, LV_STATE_PRESSED, active);
}
