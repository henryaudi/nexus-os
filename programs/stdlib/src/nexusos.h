#ifndef NEXUSOS_H
#define NEXUSOS_H

#include <stddef.h>

void  print(const char *filename);
int   getkey();
void *nexus_malloc(size_t size);
void  nexus_free(void *ptr);
void  nexus_putchar(int c);
#endif
