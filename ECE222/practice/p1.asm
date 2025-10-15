    .section .text
    .globl main

main:
    li t0, 9          # base = 9
    li t1, 4          # exponent = 4
    li t2, 1          # result = 1

loop:
    mul t2, t2, t0    # result *= base
    addi t1, t1, -1   # exponent--
    bnez t1, loop     # repeat until exponent == 0

    lui t3, 0x80000   # load upper 20 bits of 0x80000000
    addi t3, t3, 8    # t3 = 0x80000008
    sw t2, 0(t3)      # store result at memory[0x80000008]

    # (optional end)
    li a7, 93
    ecall
