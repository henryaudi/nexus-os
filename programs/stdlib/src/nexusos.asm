[BITS 32]

global print:function
global getkey:function
global nexus_malloc:function
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

; void *nexus_malloc(size_t size)
nexus_malloc:
    push ebp
    mov  ebp, esp
    mov  eax, 4          ; COMMAND4 - malloc
    push dword[ebp + 8]  ; Variable "size"
    int  0x80
    add  esp, 4
    pop  ebp
    ret
