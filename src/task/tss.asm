section .asm

global tss_load

tss_load:
    push ebp
    mov  ebp, esp
    mov  ax, [ebp + 8] ; Load the segment selector from the stack
    ltr  ax
    pop  ebp
    ret

