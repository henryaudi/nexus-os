#include "nexusos.h"
#include "stdlib.h"
#include "stdio.h"
#include <stdbool.h>

int main(int argc, char **argv)
{
    print("Hello World!\n");
    print(itoa(123456789));
    printf("My age is %i\n", 29);

    void *ptr = malloc(512);
    free(ptr);

    char buf[1024];
    nexus_terminal_readline(buf, sizeof(buf), true);
    print(buf);
    
    print("\nExiting...\n");
    while (1)
    {
    }
    return 0;
}