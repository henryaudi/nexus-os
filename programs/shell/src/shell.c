#include "shell.h"
#include "stdio.h"
#include "stdlib.h"
#include "nexusos.h"

int main(int argc, char **argv)
{
    print("NexusOS v1.0.0.\n");
    while (1) 
    {
        print("> ");
        char buf[1024];
        nexus_terminal_readline(buf, sizeof(buf), true);
        print("\n");
    }
    return 0;
}