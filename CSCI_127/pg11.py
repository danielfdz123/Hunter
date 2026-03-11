#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#February 28, 2022
#This program will show the shades of blue

import turtle
turtle.colormode(255)		#Allows colors to be given as 0...255
beef = turtle.Turtle()                 

for i in range(0,255,10):
     beef.forward(10)		#Move forward
     beef.pensize(i)		#Set the drawing size to be i (larger each time)
     beef.color(0,0,i)	

turtle.done()   # Allows turtle graphic window to not close on its own