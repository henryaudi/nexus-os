[BITS 32]

section .asm

global restore_general_purpose_registers
global task_return
global user_registers

task_return:
    mov  ebp, esp
    mov  ebx, [ebp + 4]    ; Access the structure pointer passed
    push dword [ebx + 24]  ; Push data/stack selector
    push dword [ebx + 40]  ; Push the stakc pointer
    
    pushf                  ; Push the flags register onto the stack
    pop eax
    or  eax, 0x200         ; Set the interrupt flag
    push eax

    push dword [ebx + 32]  ; Push the code segment
    push dword [ebx + 28]  ; Push the IP to execute

    ; Setup some segment registers
    mov ax, [ebx + 44]  
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    push dword [ebx + 4]
    call restore_general_purpose_registers
    add  esp, 4

    ; Leave kernel land and execute the userland code
    iretd

restore_general_purpose_registers:
    push ebp
    mov  ebp, esp
    mov  ebx, [ebp + 8]
    mov  edi, [ebx]
    mov  esi, [ebx + 4]
    mov  ebp, [ebx + 8]
    mov  edx, [ebx + 16]
    mov  ecx, [ebx + 20]
    mov  eax, [ebx + 24]
    mov  ebx, [ebx + 12]
    pop  esp
    ret

user_registers:
    mov ax, 0x23
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    ret