#include "nexusos.h"

int nexus_getkeyblock()
{
    int val = 0;

    do
    {
        val = nexus_getkey();
    } 
    while (val == 0);
    return val;
}

void nexus_terminal_readline(char *out, int max, bool output_while_typing)
{
    int i = 0;
    for (i = 0; i < max - 1; i++)
    {
        char key = nexus_getkeyblock();

        if (key == 13)  /* Carriage return to read new line */
        {
            break;
        }

        if (output_while_typing)  
        {
            nexus_putchar(key);
        }

        if (key == 0x08 && i >= 1)  /* Backspace handling */
        {
            out[i - 1] = 0x00;
            i -= 2;  // We plus 1 at the end of the loop
            continue;
        }

        out[i] = key;
    }    
    
    out[i] = 0x00;  /* Null terminate the string */
}