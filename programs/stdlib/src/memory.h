#ifndef NEXUS_MEMORY_H
#define NEXUS_MEMORY_H

#include <stddef.h>

void *memset(void *ptr, int c, size_t size);
int   memcmp(void *s1, void *s2, int size);
void *memcpy(void *dest, void *src, int len);
#endif
