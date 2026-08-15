#include "keyboard.h"
#include "io/io.h"
#include <stdint.h>

int classic_keyboard_init();

/** Classic PS/2 keyboard scan set one */
static uint8_t keyboard_scan_set_one[] = {
    0x00, 0x1B, '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  '0',  '-',  '=',
    0x08, '\t', 'Q',  'W',  'E',  'R',  'T',  'Y',  'U',  'I',  'O',  'P',  '[',  ']',
    0x0d, 0x00, 'A',  'S',  'D',  'F',  'G',  'H',  'J',  'K',  'L',  ';',  '\'', '`',
    0x00, '\\', 'Z',  'X',  'C',  'V',  'B',  'N',  'M',  ',',  '.',  '/',  0x00, '*',
    0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, '7',
    '8',  '9',  '-',  '4',  '5',  '6',  '+',  '1',  '2',  '3',  '0',  '.'
};

struct keyboard classic_keyboard = {.name = {"Classic"}, // Classic PS/2 keyboard driver
                                    .init = classic_keyboard_init};

int classic_keyboard_init()
{
    outb(0x64, 0xAE);
    return 0;
}

struct keyboard *classic_init()
{
    return &classic_keyboard;
}
