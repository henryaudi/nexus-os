#include "nexusos.h"

int main(int argc, char **argv)
{
    print("Hello World");
    while (1)
    {
        if (getkey() != 0)
        {
            print("Key pressed\n");
        }
    }
    return 0;
}