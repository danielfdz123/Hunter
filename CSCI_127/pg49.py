#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#April 17, 2022
#This MIPS programs counts by 5 all the way to 50

ADDI $s0, $zero, 0 #set s0 to 0
ADDI $s1, $zero, 5  #use to increment counter, $s0
ADDI $s2, $zero, 50 #set s2 to 50
AGAIN: ADD $s0, $s0, $s1
BEQ $s2, $s0, DONE
J AGAIN
DONE:  #To break out of the loop
