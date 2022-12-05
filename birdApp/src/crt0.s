.section .init, "ax"
.global _start
_start:
    .cfi_startproc
    .cfi_undefined ra
    .option push
    .option norelax
    la gp, __global_pointer$
    .option pop
    la sp, __stack_top
    add s0, sp, zero
    jal ra, init
    nop
    jal zero, main
    .cfi_endproc
    

.section .text, "ax"
.global getTicks, getStatus, getVideoToggle, getVidIntCtr, calcLargeSpriteControl, writeVidIntCtrToScreen, sleep, rand, seed_rand, moveLargeSprite, deleteLargeSprite, writeCharToTextPos
getTicks:
    li a5, 0
    ecall
getStatus:
    li a5, 1
    ecall
getVideoToggle:
    li a5, 2
    ecall
getVidIntCtr:
    li a5, 3
    ecall
calcLargeSpriteControl:
    li a5, 4
    ecall
writeVidIntCtrToScreen:
    li a5, 5
    ecall
sleep:
    li a5, 6
    ecall
rand:
    li a5, 7
    ecall
seed_rand:
    li a5, 8
    ecall
moveLargeSprite:
    li a5, 9
    ecall
deleteLargeSprite:
    li a5, 10
    ecall
writeCharToTextPos:
    li a5, 11
    ecall
.end
