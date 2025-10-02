
/* This is a comment in assembly language */

/* Variables are stored in the .data section */
.data
addi x5, x0, 10   # x5 = 10
addi x6, x0, 20   # x6 = 20
li x7, 30         # x7 = 30 (load immediate)

/* RISC-V data transfer
    lw = load word (4 bytes) brings data from memory to register
    sw = store word (4 bytes) writes data from register to memory
    lb = load byte (1 byte) brings 1 byte from memory to register
    sb = store byte (1 byte) writes 1 byte from register to memory
    la = load an address into somewhere
    */

    /* load word / store word example */
    /* c code: int A[100]; x8 = A[0]; */
       int x = A[1]; x = x5
       x++;
       A[1] = x;   
       
    */
    lw x1 4(x8)  # load A[1] into x1 (4 bytes offset)
    addi x1, x1, 1 # increment x1
    sw x1, 4(x8)  # store x1 back into A[1]
    


/* RISC-V arithmetic instructions
    add = addition
    sub = subtraction
    mul = multiplication
    div = division
    and = bitwise AND
    or = bitwise OR
    xor = bitwise XOR
    sll = shift left logical   # can be used for multiplication by powers of 2



;     Signed (bge, blt, jg, jl, idiv, imul) → treat MSB as sign.

; Unsigned (bgeu, bltu, ja, jb, div, mul) → treat MSB as part of the magnitude.

; loops
addi x9, x9, 0      # i = 0
addi x10, x0, 10    # n = 10
loop: 
    bge x9, x10, end_loop
    addi x9, x9, 1
    j loop ; loops back to the beginning of the loop
end_loop:

/* RISC-V conditional branches
    beq = branch if equal
    bne = branch if not equal
    blt = branch if less than
    bge = branch if greater than or equal
    bltu = branch if less than unsigned
    bgeu = branch if greater than or equal unsigned
    */

    /* Example: if (x5 == x6) x7 = x5 + x6; else x7 = x5 - x6; */
    beq x5, x6, equal
    sub x7, x5, x6  # else part
    j end_if ; jump to end of if
equal:
    add x7, x5, x6
end_if:


; Jump table
; jump table is like an index of addresses to jump to (array)
; switch (x10) {
;     case 0: ... break;
;     case 1: ... break;
;     case 2: ... break;
;     default: ... break;
; }
    li x12, 3   # upper bound for jump table
    bgeu x10, x12, default_case  # if x10 >= 3, go to default case
    la x13, jump_table  # load address of jump table
    slli x12, x10, 2  # multiply x10 by 4 (size of each address)
    add x13, x13, x12  # get address of jump table entry
    lw x13, 0(x13)  # load address from jump table
    jr x13  # jump to address jump_table + offset (x10 * 4)

    jump_table:
        case0     # address of code for case 0 is at index 0
        case1     # address of code for case 1 is at index 1
        case2     # address of code for case 2 is at index 2


; Fi




; Calling functions; jal = jump and link (used to call functions)
; jalr = jump and link register (used to return from functions)
; jal x1, function_name  # jump to function_name and store return address in x1
; ... function code ...




function:
    # function code here
    addi x5, x5, 1
    jr ra  ; jumps to ra + 4



jal ra, function







