[BITS 32]

section .asm

global print:function
global nexus_getkey:function
global nexus_malloc:function
global nexus_free:function
global nexus_putchar:function
global nexus_process_load_start:function
global nexus_process_get_arguments:function
global nexus_system:function

; void print(const char* filename)
print:
    push ebp

    mov  ebp, esp
    push dword[ebp + 8]
    mov  eax, 1
    int  0x80
    add  esp, 4
    
    pop  ebp
    ret

; int nexus_getkey()
nexus_getkey:
    push ebp
    mov  ebp, esp
    mov  eax, 2  ; Command getkey 
    int  0x80
    pop  ebp
    ret

; void nexus_putchar(int c)
nexus_putchar:
    push ebp
    mov  ebp, esp
    mov  eax, 3  ; COMMAND3 = putchar
    push dword[ebp + 8]  ; Variable "character"
    int  0x80
    add  esp, 4
    pop  ebp
    ret

; void *nexus_malloc(size_t size)
nexus_malloc:
    push ebp
    mov  ebp, esp
    mov  eax, 4          ; COMMAND4 - malloc
    push dword[ebp + 8]  ; Variable "character"
    int  0x80
    add  esp, 4
    pop  ebp
    ret

; void nexus_free(void *ptr)
nexus_free:
    push ebp
    mov  ebp, esp
    mov  eax, 5
    push dword[ebp + 8] 
    int  0x80
    add  esp, 4
    pop  ebp
    ret

; void nexus_process_load_start(const char *filename)
nexus_process_load_start:
    push ebp
    mov  ebp, esp
    mov  eax, 6  ; COMMAND6 - process_load_start (start a process)
    push dword[ebp + 8]  ; Variable "filename"
    int  0x80
    add  esp, 4
    pop  ebp
    ret

; int nexus_system(struct command_argument *argument)
nexus_system:
    push ebp
    mov  ebp, esp
    mov  eax, 7  ; COMMAND7 - process_system (runs a system command based on the args)
    push dword[ebp + 8]  ; Variable "argument"
    int  0x80
    add  esp, 4
    pop  ebp
    ret

; void nexus_process_get_arguments(struct process_arguments *args)
nexus_process_get_arguments:
    push ebp
    mov  ebp, esp
    mov  eax, 8  ; COMMAND8 - process_get_arguments
    push dword[ebp + 8]  ; Variable arguments
    int  0x80
    add  esp, 4
    pop  ebp
    ret