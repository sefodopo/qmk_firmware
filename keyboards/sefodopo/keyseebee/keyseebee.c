#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    oled_rotation_t user = oled_init_user(rotation);
    if (user != rotation) return user;
    return OLED_ROTATION_270;
}

void oled_render_boot(bool bootloader) {
    oled_clear();
    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        if (bootloader) {
            oled_write_P(PSTR("DFU"), false);
        } else {
            oled_write_P(PSTR("BOOT"), false);
        }
    }

    oled_render_dirty(true);
}

bool shutdown_kb(bool jump_to_bootloader) {
    if (!shutdown_user(jump_to_bootloader)) {
        return false;
    }
    oled_render_boot(jump_to_bootloader);
    return true;
}
#endif
