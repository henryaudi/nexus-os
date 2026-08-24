[BITS 32]

global _start
extern c_start
extern nexus_exit

section .asm

_start:
    call c_start
    call nexus_exit
    ret