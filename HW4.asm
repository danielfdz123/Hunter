# THIS IS HW4.CPP BUT IN ASSEMBLY 

SUM_OF_SQUARES:
#Allocate stack space for 4 words
    addi $sp, $sp, -16
    sw $ra, 12($sp)          #Save return address
    sw $s0, 8($sp)           #Push onto stack
    sw $s1, 4($sp)           
    sw $s2, 0($sp)           

    add $s0, $zero, $a0      #s0 = n (n is our test value)
    add $s1, $zero, $zero    #s1 = 0 (sum of squares)
    add $s2, $zero, $zero    #s2 = 0 (loop counter)

SosLOOP:
    addi $t0, $s2, 1         	  #t0 = s2 + 1
    slt $t1, $s0, $t0        	  #s0 < t0
    bne $t1, $zero, sosEndLoop    #if slt != 0, exit the loop

    add $a0, $t0, $zero      # a0 = t0
    add $a1, $t0, $zero      # a1 = t0
    jal MULTIPLY             # call MULTIPLY(t0, t0)
    add $s1, $s1, $v0        # add the products from MULTIPLY
    addi $s2, $s2, 1         # s2++
    j SosLOOP                #Repeat sosLOOP

sosEndLoop:
    add $v0, $s1, $zero      #v0 <- sum of squares

    lw $s2, 0($sp)           #Pop from stack
    lw $s1, 4($sp)           
    lw $s0, 8($sp)          
    lw $ra, 12($sp)          #reobtain return address
    addi $sp, $sp, 16        #Deallocate stack space
    jr $ra                   #return to MAIN

MULTIPLY:
#Allocates the stack ofr 4 words
    addi $sp, $sp, -16       
    sw $ra, 12($sp)          #Save return address
    sw $s0, 8($sp)           #Push onto stack
    sw $s1, 4($sp)           
    sw $s2, 0($sp)           

    add $s0, $zero, $a0      # s0 <- 0 (number A)
    add $s1, $zero, $a1      # s1 <- 0 (number B
    add $s2, $zero, $zero    # s2 <- 0 (product)
    add $s3, $zero, $zero    # s3 = 0 (counter)
    
mFOR:
    beq $s3, $s1, mEndLoop	  	#once s3 = product number B, EXIT FOR LOOP
    add $s2, $s2, $s0        		#s2 = s2 + s0 add values and store it in s2
    addi $s3, $s3, 1         		#increment counter (s3++)
    j mFOR               		#Repeat loop

mEndLoop:
    add $v0, $s2, $zero      #v0 <- product

    lw $s2, 0($sp)           #Pop from the staxk
    lw $s1, 4($sp)          
    lw $s0, 8($sp)           
    lw $ra, 12($sp)          #reobtain return adress
    addi $sp, $sp, 16        #Deallocate stack space
    jr $ra                   #return to sosLoop
 
END:
#rest of code