section .asm

extern int21h_handler
extern no_interrupt_handler
extern isr80h_handler
extern interrupt_handler

global int21h
global no_interrupt
global idt_load
global enable_interrupts
global disable_interrupts
global isr80h_wrapper

enable_interrupts:
    sti
    ret

disable_interrupts:
    cli
    ret

idt_load:
    push ebp
    mov ebp, esp

    mov  ebx, [ebp + 8]
    lidt [ebx]
    
    pop  ebp
    ret

int21h:
    pushad
    call int21h_handler
    popad
    iret

no_interrupt:
    pushad
    call no_interrupt_handler
    popad
    iret

%macro interrupt 1
    global int%1
    int%1:
        pushad
        push esp
        push dword %i
        call interrupt_handler
        add  esp, 8
        popad
        iret

%endmacro

%assign i 0
%rep 521
    interrupt i
%assign i i+1
%endrep


isr80h_wrapper:
    
    pushad  ; Pushed the general purpose registers onto the stack

    ; INTERRUPE FRAME END

    push esp                    ; Push stack pointer pointing to the interrupt frame
    push eax                    ; Push the syscall number
    call isr80h_handler
    mov  dword[tmp_res], eax
    add  esp, 8

    ; Restore the general purpose registers for user land
    popad
    mov eax, [tmp_res]
    iretd

section .data
; Inside here is stored the return result from isr80h_handler.
tmp_res: dd 0

%macro interrupt_array_entry 1
    dd int%1
%endmacro

interrupt_pointer_table:
%assign i 0
%rep 512
    interrupt_array_entry i
%assign i i+1
%endrep