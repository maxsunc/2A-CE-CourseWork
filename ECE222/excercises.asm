

@ Convert this C code to assembly
@ struct Point {
@     int x; // Offset: 0
@     int y; // Offset: 4
@ };

@ Assume:
@ Address of Point 'p1' is in 's0'
@ Address of Point 'p2' is in 's1'

@ p2.x = p1.x;

lw t0, 0(s0)      @ Load p1.x into t0 offset 0
sw t0, 4(s1)      @ Store t0 into p2.x offset 4



@ ex 2:
@ Assume:
@ pointer 'p' (which holds memory address is in 's0')
@ Value of 'p' is currently ox1000

@ int j = *p;
@ p++;
@ *p = j;

lw t0, 0(s0)      @ Load value at address in p into t0
addi s0, s0, 4    @ Increment pointer p to point to next int (increment by 4 bytes, points to next element)
sw t0, 0(s0)      @ Store value of j (in t0) into address in p