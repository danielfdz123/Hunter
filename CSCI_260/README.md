# CSCI 260 (Computer Architecture II)
CSCI 26000 - Computer Architecture II

All of the homework and project assignments I worked on while taking CSCI 260 at Hunter College during the Summer 2024 semester.

Majority of these coding labs are using MIPS, and a few C++ every now and then. This class heavily revoles around MIPS but the C++ files within are simply used to help me translate the code over to MIPS. 
____________________________________________________________________________________________________________________________________________________________
Homework/Project Overview:

(hw2a.asm) MIPS code that implements:  m = 2 − (7 ∗ (9 ∗ n + 3));

(hw2b.asm) MIPS code that implements: C[1] = C[0]; 
                                      C[0] = m − 5;
                                      
(hw2c.asm) MIPS code that implements: D[m ∗ 3 + C[2]] = (∗k) − C[1];
    
(hw3.asm) Building IoT data packet sequentially using MIPS instructions

(hw4.asm) Implements a SUM OF SQUARES function and a MULTIPLY function that takes in two positive integers, passed in through registers $a0 and $a1, and returns their product in $v0. Will also have the equivalent C++ code as comments

(hw4.cpp) A sample C++ code used to implement and assist me in building the SUM OF SQUARES function required for hw4.asm

(CSCI260Project.asm) Using the bitmap diaply on MARS (a MIPS simulator) this program draws a diamond with a color gradient with a yellow background using the corresponding MIPS instructions we learned in class. The program can also allow users to change attributes of the diamond itself like color, size, and location
