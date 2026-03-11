#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#March 4, 2022
#This program askes the user for 5 integers, which will be the degress the turtle willturn to the left by

import turtle
beef = turtle.Turtle()

a = int(input("Enter a number: "))
b = int(input("Enter a number: "))
c = int(input("Enter a number: "))
d = int(input("Enter a number: "))
e = int(input("Enter a number: "))

for i in range(a, b, c, d, e):
    beef.forward(100)
    beef.left(i)
