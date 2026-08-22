#include "shell.h"
#include "stdio.h"
#include "stdlib.h"
#include "nexusos.h"

int main(int argc, char **argv)
{
    print("NexusOS (c) v1.0.0 designed by SuperHard Inc. in UT, USA.\n");
    while (1) 
    {
        print("> ");
        char buf[1024];
        nexus_terminal_readline(buf, sizeof(buf), true);
        nexus_process_load_start(buf);
        
        print("\n");
    }
    return 0;
}