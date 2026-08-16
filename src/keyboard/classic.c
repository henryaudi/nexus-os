#include "keyboard.h"
#include "io/io.h"
#include "kernel.h"
#include "idt/idt.h"
#include "classic.h"
#include "task/task.h"
#include <stdint.h>
#include <stddef.h>

int  classic_keyboard_init();
void classic_keyboard_handle_interrupt();

/** Classic PS/2 keyboard scan set one */
static uint8_t keyboard_scan_set_one[] = {
    0x00, 0x1B, '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  '0',  '-',  '=',
    0x08, '\t', 'Q',  'W',  'E',  'R',  'T',  'Y',  'U',  'I',  'O',  'P',  '[',  ']',
    0x0d, 0x00, 'A',  'S',  'D',  'F',  'G',  'H',  'J',  'K',  'L',  ';',  '\'', '`',
    0x00, '\\', 'Z',  'X',  'C',  'V',  'B',  'N',  'M',  ',',  '.',  '/',  0x00, '*',
    0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, '7',
    '8',  '9',  '-',  '4',  '5',  '6',  '+',  '1',  '2',  '3',  '0',  '.'};

struct keyboard classic_keyboard = {.name = {"Classic"}, // Classic PS/2 keyboard driver
                                    .init = classic_keyboard_init};

int classic_keyboard_init()
{
    idt_register_interrupt_callback(ISR_KEYBOARD_INTERRUPT, classic_keyboard_handle_interrupt);
    outb(PS2_PORT, PS2_COMMAND_ENABLE_FIRST_PORT); // Enable the first PS/2 port
    return 0;
}

uint8_t classic_keyboard_scancode_to_char(uint8_t scancode)
{
    size_t size_keyboard_set_one = sizeof(keyboard_scan_set_one) / sizeof(uint8_t);
    if (scancode >= size_keyboard_set_one)
    {
        return 0x00; // Invalid scancode
    }

    char c = keyboard_scan_set_one[scancode];
    return c;
}

void classic_keyboard_handle_interrupt()
{
    kernel_page();
    uint8_t scancode = 0;

    /* Read scancode from keyboard */
    scancode = insb(KEYBOARD_INPUT_PORT);
    insb(KEYBOARD_INPUT_PORT);

    /* Convert scancode to character */
    if (scancode & CLASSIC_KEYBOARD_KEY_RELEASED)
    {
        return; // We don't care about key releases FOR NOW
    }

    uint8_t c = classic_keyboard_scancode_to_char(scancode);
    if (c != 0)
    {
        keyboard_push(c);
    }

    task_page();
}

struct keyboard *classic_init()
{
    return &classic_keyboard;
}
