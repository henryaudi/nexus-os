#include "stdio.h"
#include "nexusos.h"

int putchar(int c)
{
    nexus_putchar((char)c);
    return 0;
}