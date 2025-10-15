    .section .text
    .globl main

main:
    li   t0, 20291        # n
    lui  t6, 0x80000
    addi t6, t6, 4
    sw   t0, 0(t6)        # store n @0x80000004

    li   t1, 2            # i = 2 (trial divisor)

loop:
    rem  t2, t0, t1       # t2 = n % i
    beqz t2, found        # if divisible -> found
    mul  t3, t1, t1       # t3 = i*i
    blt  t0, t3, done     # if i*i > n -> done (no factor)
    addi t1, t1, 1
    j    loop

found:
    div  t3, t0, t1       # t3 = n / i

    # store p = i at 0x80000008
    lui  t4, 0x80000
    addi t4, t4, 8
    sw   t1, 0(t4)

    # store q = n/i at 0x8000000C
    addi t4, t4, 4
    sw   t3, 0(t4)

done:
    li   a0, 0
    li   a7, 93
    ecall
