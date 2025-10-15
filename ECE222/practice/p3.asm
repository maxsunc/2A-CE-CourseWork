    .section .text
    .globl main
; Write a RISC-V assembly program that calculates the Greatest Common Divisor (GCD) of two
; numbers. The Greatest Common Divisor (GCD) of two integers is the largest positive integer
; that divides both numbers exactly, without leaving a remainder. For example, the GCD of 48 and
; 18 is 6, because 6 is the largest number that divides both 48 and 18 evenly. The two numbers that
; your program will use are provided in the list below. Select the pair of numbers according to the
; last digit of your student ID number. For example, if the last digit of your student ID number is
; 4, your program is to calculate the GCD of 5952 and 7488. Note: In your code, first identify the
; smaller and larger numbers, then compute the GCD.
; Start your program by loading the numbers A and B into memory locations 0x80000004 and
; 0x80000008 respectively. Your program must calculate the GCD and store the result in memory
; location 0x80000010. Remember that the base address is 0x80000000.
; Last Digit
; of Student
; Number
; Number
; A (Dec)
; Number
; A (Hex)
; Number
; B (Dec)
; Number
; B (Hex)
; 0 4620 0x120C 7380 0x1CD4
; 1 5940 0x1734 8268 0x204C
; 2 4818 0x12D2 6702 0x1A2E
; 3 7146 0x1BEA 8526 0x214E
; 4 5952 0x1740 7488 0x1D40
; 5 6396 0x18FC 7710 0x1E1E
; 6 6816 0x1AA0 7560 0x1D88
; 7 6768 0x1A70 7296 0x1C80
; 8 6156 0x180C 7072 0x1BA0
; 9 1240 0x04D8 8064 0x1F80

; make address 0x80000004
main:
    li t0, 5952
    li t1, 7488

    ; fills with 0s
    lui t4, 0x80000  
    addi t4, t4, 4

    ; t 4 stors 0x800000004
    sw t0, 0(t4)

    sw 













;     .section .text
;     .globl main

; main:
;     # load numbers (assume last digit = 4)
;     li    t0, 5952        # A
;     li    t1, 7488        # B

;     # store A @ 0x80000004
;     lui   t4, 0x80000
;     addi  t4, t4, 4
;     sw    t0, 0(t4)

;     # store B @ 0x80000008
;     addi  t4, t4, 4       # now t4 = 0x80000008
;     sw    t1, 0(t4)

;     # ensure t0 <= t1 (swap if t0 > t1)
;     blt   t0, t1, loop    # if t0 < t1 jump to loop (order ok)
;     mv    t2, t0
;     mv    t0, t1
;     mv    t1, t2

; loop:
;     beqz  t1, done        # if b == 0, gcd is a (t0)
;     rem   t2, t0, t1      # r = a % b
;     mv    t0, t1          # a = b
;     mv    t1, t2          # b = r
;     j     loop

; done:
;     # store gcd (t0) at 0x80000010
;     lui   t4, 0x80000
;     addi  t4, t4, 16      # 0x80000000 + 16 = 0x80000010
;     sw    t0, 0(t4)

;     # exit (Linux RISC-V syscall)
;     li    a0, 0
;     li    a7, 93
;     ecall
