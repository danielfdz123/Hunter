lw $t0, 4($s1)          #t0 <- C[1]
lw $t1, 0($s3)          #t1 <- *k
sub $t2, $t1, $t0       #t2 = t1 - t0 <--> *k - C[1]

lw $t3, 8($s1)          #t3 <- C[2]
add $t3, $s2, $s2       #t4 = 2m <--> m + m
add $t4, $t4, $s2       #t5 = 3m <--> 2m + m
add $t3, $t4, $t3       #t3 <- 3m + C[2]

add $t3, $t3, $t3       #t3 = 2(3m+C[2]) <--> 3m+C[2] + 3m+C[2]
add $t3, $t3, $t3       #t3 = 4(3m+C[2]) <--> 2(3m+C[2]) + 2(3m+C[2])
add $t5, $s0, $t3       #offsett

sw $t2, 0($t5)          #setting it equal