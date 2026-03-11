#C[1] = C[0]
lw $t0, 0($s0)          #t0 <- C[0]
sw $t0, 4($s0)          #store t0 in C[1]

#C[0] = m -5
addi $t1, $s1, -5       #t1 <- m -5
sw $t1, 0($s0)          #store t1 in C[0]