#include "keyboard.h"

int classic_keyboard_init();

struct keyboard classic_keyboard = {
    .name = {"Classic"},
    .init = classic_keyboard_init
};

