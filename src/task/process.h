#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>
#include "config.h"
#include "task.h"

struct process
{
    // The process ID
    uint16_t id;

    char filename[NEXUS_MAX_PATH];
    
    // The main process task
    struct task *task;

    // Track all the allocations made by the process
    void *allocations[NEXUS_MAX_PROGRAM_ALLOCATIONS];

    // The physical pointer to the process memory
    void *ptr;

    // The physical pointer to the stack memory
    void *stack;

    // The size of the data pointed by "ptr"
    uint32_t size;
};

int process_load_for_slot(const char *filename, struct process **process, int process_slot);

#endif