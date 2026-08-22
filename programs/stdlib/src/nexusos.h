#ifndef NEXUSOS_H
#define NEXUSOS_H

#include <stddef.h>
#include <stdbool.h>

void  print(const char *filename);
int   nexus_getkey();
int   nexus_getkeyblock();
void *nexus_malloc(size_t size);
void  nexus_free(void *ptr);
void  nexus_putchar(int c);
void  nexus_terminal_readline(char *out, int max, bool output_while_typing);
void  nexus_process_load_start(const char *filename);
#endif
