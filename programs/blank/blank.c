#include "nexusos.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char **argv)
{
    printf("NexusOS (c) 2026 Designed by SuperHard Inc., UT, USA \n");
    char words[] = "Hello how are you";
    const char *token = strtok(words, " ");
    while (token)
    {
        printf("Token: %s\n", token);
        token = strtok(0, " ");
    }
    return 0;
}