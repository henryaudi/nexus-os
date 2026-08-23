#include "nexusos.h"
#include "string.h"

struct command_argument *nexus_parse_command(const char *command, int max)
{
    struct command_argument *root_command = 0;
    char                     scommand[1024];
    if (max >= (int)sizeof(scommand))
    {
        return 0;
    }

    /* Extract the root command */
    strncpy(scommand, command, sizeof(scommand));
    char *token = strtok(scommand, " ");
    if (!token)
    {
        goto out;
    }

    root_command = nexus_malloc(sizeof(struct command_argument));
    if (!root_command)
    {
        goto out;
    }

    strncpy(root_command->argument, token, sizeof(root_command->argument));
    root_command->next = 0;

    /* Extract the subsequent command arguments */
    struct command_argument *current = root_command;
    token =
        strtok(NULL, " "); // Pass NULL to continue tokenizing the same string pointed by scommand.
    while (token != 0)
    {
        struct command_argument *new_command = nexus_malloc(sizeof(struct command_argument));
        if (!new_command)
        {
            break;
        }

        strncpy(new_command->argument, token, sizeof(new_command->argument));
        new_command->next = 0;
        current->next     = new_command;
        current           = new_command;
        token             = strtok(NULL, " ");
    }
out:
    return root_command;
}

int nexus_getkeyblock()
{
    int val = 0;

    do
    {
        val = nexus_getkey();
    } while (val == 0);
    return val;
}

void nexus_terminal_readline(char *out, int max, bool output_while_typing)
{
    int i = 0;
    for (i = 0; i < max - 1; i++)
    {
        char key = nexus_getkeyblock();

        if (key == 13) /* Carriage return to read new line */
        {
            break;
        }

        if (output_while_typing)
        {
            nexus_putchar(key);
        }

        if (key == 0x08 && i >= 1) /* Backspace handling */
        {
            out[i - 1] = 0x00;
            i -= 2; // We plus 1 at the end of the loop
            continue;
        }

        out[i] = key;
    }

    out[i] = 0x00; /* Null terminate the string */
}
