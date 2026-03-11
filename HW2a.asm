add $t0, $s1, $s1           #t0 <- 2n
add $t0, $t0, $t0           #t0 <- 4n
add $t0, $t0, $t0           #t0 <- 8n
add $t0, $t0, $s1           #t0 <- 9n

addi $s2, $t0, 3            #s2 <- 9n+3

add $t1, $s2, $s2           #t1 <- 2(9n+3)
add $t1, $t1, $t1           #t1 <- 4(9n+3)
add $t1, $t1, $t1           #t1 <- 8(9n+3)
sub $s3, $t1, $s2           #s3 <- 7(9n+3)

addi $t2, $zero, 2          #t2 <- 2
sub $s4, $t2, $s3           #t2 <- 2-(7(9n+3))