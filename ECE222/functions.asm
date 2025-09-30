

; register conventions
; t - temporary registers (caller saved, if you want to save it, you must save it before calling a function) (t0-t6)
; s - saved registers, callee saved (function being called must save them) (s0-s11)
; a - argument registers (x10-x17) (used to pass arguments to functions, return values in a0 and a1, a0-a7)
; ra - return address (x1) (used to store return address for function calls)
; sp - stack pointer (x2) (points to top of stack) (always use sp to store temporary elements)

; after a function is called we assume t registers are unknown, assume s registers are preserved

; example question: Given some risc-V code what does that function do? Explain in < 3 sentences

; example



function: 
; prologue
    addi sp, sp, -16  # make space on stack, stack is used to just store stuff
    sw ra, 12(sp)     # save return address
    ; only saves registers that will be used
    sw s0, 8(sp)      # save s0
    sw s1, 4(sp)      # save s1
    sw s2, 0(sp)      # save s2

    # function code here
    addi s0, a0, 1    # s0 = a0 + 1
    addi s1, a1, 2    # s1 = a1 + 2
    add s2, s0, s1    # s2 = s0 + s1

; epilogue
    mv a0, s2 ; move s2 to a0 to return it
    lw ra, 12(sp)     # restore return address
    lw s0, 8(sp)      # restore s0
    lw s1, 4(sp)      # restore s1
    lw s2, 0(sp)      # restore s2
    addi sp, sp, 16   # deallocate space on stack
    jr ra             # return to caller

; calling the function
    li a0, 5          # load first argument
    li a1, 10         # load second argument
    jal ra, function  # call function
    # result is now in s2 (or a0 if you modify the function to return in a0)

; function calling another function
    function2: 
    # prologue
        addi sp, sp, -4  # make space on stack
        sw ra, 0(sp)     # save return address  to return back to main thread
    # function code here
    jal ra, function 

    # epilogue
        lw ra, 0(sp)
        addi sp, sp, 4   # deallocate space on stack
        jr ra            # return to caller



; recursion
factorial:
    l t0, 1
    bge a0, 