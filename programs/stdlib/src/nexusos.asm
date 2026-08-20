[BITS 32]

section .asm

global print:function
global getkey:function
global nexus_malloc:function
global nexus_free:function
global nexus_putchar:function

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

; int getkey()
getkey:
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

