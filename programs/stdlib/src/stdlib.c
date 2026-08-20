#include "stdlib.h"
#include "nexusos.h"

void *malloc(size_t size)
{
    return nexus_malloc(size);
}

void  free(void *ptr)
{
    nexus_free(ptr);
}