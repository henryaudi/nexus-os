#ifndef ISR80H_H
#define ISR80H_H

enum SystemCommands
{
    SYSTEM_COMMAND0_SUM = 0,
    SYSTEM_COMMAND1_PRINT,
};

void isr80h_register_commands();

#endif