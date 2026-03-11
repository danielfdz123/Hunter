#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#March 7, 2022
#This program allows the user to control the turtle with their own commands

import turtle

beef = turtle.Turtle()
screen = turtle.Screen()     
commands = input("Please enter commands: ")

for m in commands:
    if m == 'F':            
        beef.forward(50)
    elif m == 'L':
        beef.left(90)
    elif m == 'R':
        beef.right(90)
    elif m == '^':
        beef.penup()
    elif m == 'v':
        beef.pendown()
    elif m == 'B':
        beef.backward(50)
    elif m == 'S':
        beef.stamp()
    elif m == 'l':
        beef.left(45)
    elif m == 'r':
        beef.right(45)
    elif m == 'p':
        beef.color("purple")
    else: 
        print("Error: do not know the command:", c)

print("See graphics window for your image")
