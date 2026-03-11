#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#February 28, 2022
#This program will stamp a turtle with the color of your choice

import turtle
beef = input("Please enter the name of a color: ")

taco = turtle.Turtle()
taco.shape("turtle")
taco.color(beef)
taco.stamp()

turtle.done()   # Allows turtle graphic window to not close on its own