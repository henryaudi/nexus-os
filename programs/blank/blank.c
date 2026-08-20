#include "nexusos.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char **argv)
{
    print("Hello World!\n");
    print(itoa(123456789));
    putchar('Z');

    void *ptr = malloc(512);
    free(ptr);
    while (1)
    {
        if (getkey() != 0)
        {
            print("Key pressed\n");
        }
    }
    return 0;
}