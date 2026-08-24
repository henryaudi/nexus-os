#ifndef NEXUSOS_H
#define NEXUSOS_H

#include <stddef.h>
#include <stdbool.h>

struct command_argument
{
    char                     argument[512];
    struct command_argument *next;
};

struct process_arguments
{
    int    argc;
    char **argv;
};

void                     print(const char *filename);
int                      nexus_getkey();
int                      nexus_getkeyblock();
void                    *nexus_malloc(size_t size);
void                     nexus_free(void *ptr);
void                     nexus_putchar(int c);
void                     nexus_terminal_readline(char *out, int max, bool output_while_typing);
void                     nexus_process_load_start(const char *filename);
struct command_argument *nexus_parse_command(const char *command, int max);
void                     nexus_process_get_arguments(struct process_arguments *args);
int                      nexus_system(struct command_argument *argument);
int                      nexus_system_run(const char *command);
void                     nexus_exit();
#endif
