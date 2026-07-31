#include "kheap.h"
#include "heap.h"
#include "config.h"
#include "kernel.h"
struct heap       kernel_heap;
struct heap_table kernel_heap_table;

void kheap_init()
{
    int total_table_entries = NEXUS_HEAP_SIZE_BYTES / NEXUS_HEAP_BLOCK_SIZE;

    kernel_heap_table.entries = (HEAP_BLOCK_TABLE_ENTRY *)(NEXUS_HEAP_TABLE_ADDRESS);
    kernel_heap_table.total   = total_table_entries;

    void *end = (void *)(NEXUS_HEAP_ADDRESS + NEXUS_HEAP_SIZE_BYTES);
    int   res = heap_create(&kernel_heap, (void *)(NEXUS_HEAP_ADDRESS), end, &kernel_heap_table);
    if (res < 0)
    {
        print("Failed to create kernel heap\n");
    }
}
