.data
# DONOTMODIFYTHISLINE
frameBuffer: .space 0x80000 # 512 wide X 256 high pixels
s: .word 119
x: .word 355
y: .word 195
cr: .word 128
cg: .word 61
cb: .word 0

# DONOTMODIFYTHISLINE
# Your other variables go BELOW here only

# s = SIZE OF DIAMOND
# x = middle X coordinate 
# Y = middle Y coordinate
# cr = red component
# cg = green component
# cb = blue component

.text
#.text is needed to see the stuff on the bitmap display
main:
    la $a0, frameBuffer         # Load the address of the framebuffer into $a0
    li $t0, 0x20000             # Pixel counter (512 x 256 pixels)
    li $t1, 0x00FFFF00          # Set the color to yellow
    
yellow_bg:
    sw $t1, 0($a0)              # Set current pixel to yellow
    addi $a0, $a0, 4            # Move to the next pixel (+4)
    addi $t0, $t0, -1           # Decrement the pixel counter
    slt $t2, $zero, $t0         # Check if pixel counter > 0
    bne $t2, $zero, yellow_bg   # Loop back to yellow_bg if true

    # Load diamond attributes
    lw $s0, s
    lw $s1, x
    lw $s2, y
    lw $s3, cr
    lw $s4, cg
    lw $s5, cb

# EVERYTHING HERE ARE CONDITION CHECKING!!!!

# Check 1 (If s is even via bitmasking)
    andi $t0, $s0, 1
    beq $t0, $zero, exit

# Check 2 (If s is bigger than 256
    slti $t0, $s0, 257 	# t0 = s < 257
    beq $t0, $zero, exit

# Check 3 (Determining wether not S result in the diamond going past the edge (256h or 512w)
    srl $t0, $s0, 1  	# t0 = s / 2

# Checking all 4 edges
    sub $t1, $s1, $t0 	# LEFT EDGE (t1 = x - t0) 
    slti $t2, $t1, 0	# Check if t1 < 0
    bne $t2, $zero, exit	# exit program if true
    
    add $t1, $s1, $t0 	# RIGHT SIDE (t1 = x - t0)
    slti $t2, $t1, 512	# Check if t1 < 512
    beq $t2, $zero, exit	# exit program if true

    sub $t1, $s2, $t0 	# UPPER EDGE (t1 = y - t0)
    slti $t2, $t1, 0	# Check if t1 < 0
    bne $t2, $zero, exit

    add $t1, $s2, $t0 	# BOTTOM EGDE (t1 = y - t0)
    slti $t2, $t1, 256	# t1 < 256
    beq $t2, $zero, exit	# exit ptogram if true
    
# NO MORE CASE CHECKING, NOW WE CALCULATE STUFF

    # Setting boundaries so we know where to work
    sub $t1, $s2, $t0 	# t1 = y - <half of s>
    add $t2, $s2, $t0 	# t2 = y + <half of s>
    addi $t2, $t2, -1	# t2 = t2 - 1

    # Moving to starting position
    addi $t3, $t1, 1	# t3 = (y - half of s> + 1
    
rDIAMOND_start:
    add $t4, $s1, $zero # Adjusting the start of the right half
    sub $t5, $t3, $s2   # t5 = y - (y - half of s> + 1)
    slt $t6, $t5, $zero	# t5 < 0
    beq $t6, $zero, skip_subINST	# If true, skip the following sub isntruction
    sub $t5, $zero, $t5			# t5 = 0 - t5 (this line fixes an error in which the drawing doesnt start from its designated point for some reason)
    
skip_subINST:
    sub $t6, $t0, $t5 	# Width of current row
    add $s7, $s4, $zero # Green channel loaded
    
rDIAMOND_properties:
    sll $t9, $s3, 16 	# red channel
    sll $t8, $s7, 8  	# green channel
    or $t9, $t9, $t8
    or $t9, $t9, $s5 	# blue color channel
    add $t8, $t3, $zero # t8 = y
    sll $t8, $t8, 9 	# t8 = y * 9
    add $t8, $t8, $t4 	# t8 = (y * 9) + x
    sll $t8, $t8, 2 	# t8 = [(y * 9) + x] * 4 (BYTES)
    sw $t9, frameBuffer($t8)
    addi $t4, $t4, 1 	# Move to next row
    addi $s7, $s7, -1 	# Decrease green channel by 1
    slt $t8, $s7, $zero
    beq $t8, $zero, skip_green
    add $s7, $zero, $zero
    
skip_green:
    sub $t7, $t4, $s1 	# Check if we've reached the edge
    slt $t8, $t7, $t6 	# t8 = t7 < t6 
    bne $t8, $zero, rDIAMOND_properties # Jump to proprties if true
    addi $t3, $t3, 1 	# Move onto next row
    slt $t8, $t2, $t3	# t8 = t2 < t3
    beq $t8, $zero, rDIAMOND_start	# Jump to start if true

    # Draw left half of diamond
    addi $t3, $t1, 1 # Start from top
    
lDIAMOND_start:
    add $t4, $s1, $zero # Adjusting the start of the left half
    sub $t5, $t3, $s2   # t5 = y - (y - half of s> + 1)
    slt $t6, $t5, $zero	# t6 = t5 < 0
    beq $t6, $zero, skip_subINST2	# Skip the following set of sub inst if true
    sub $t5, $zero, $t5			# t5 = 0 - t5 (this line fixes an error in which the drawing doesnt start from its designated point for some reaosn)
    
skip_subINST2:
    sub $t6, $t0, $t5 	          # Width of current row
    beq $t6, $zero, skip_left_row # If row width is 0, skip
    add $s6, $s3, $zero 	  # Red channel loaded
    
Ldiamond_properties:
    sll $t9, $s6, 16 		# Adjust red channel to the new location
    sll $t8, $s4, 8 		# green channel yay
    or $t9, $t9, $t8
    or $t9, $t9, $s5 		# blue channel yay
    add $t8, $t3, $zero		# t8 = y
    sll $t8, $t8, 9 		# t8 = y * 9
    add $t8, $t8, $t4 		# t8 = (y + 9) + x
    sll $t8, $t8, 2 		# t8 = [(y + 9) + x] * 4 (BYTES)
    sw $t9, frameBuffer($t8)
    addi $t4, $t4, -1 		# Move to next row
    addi $s6, $s6, -1 		# Decrease red channel by 1
    slt $t8, $s6, $zero		# t6 < 0
    beq $t8, $zero, skip_red	# jump to djust red if true	
    add $s6, $zero, $zero
    
skip_red:
    sub $t7, $s1, $t4 	# Check if we've reached the edge
    slt $t8, $t7, $t6	# t8 = t7 < t6
    bne $t8, $zero, Ldiamond_properties # Jump to properties if true
    
skip_left_row:
    addi $t3, $t3, 1 	# Next row
    slt $t8, $t2, $t3	# t2 < t3
    beq $t8, $zero, lDIAMOND_start # Jump to diamond start if true (repositioning)

exit:
    # Exit program
    li $v0, 10
    syscall