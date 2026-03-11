#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#April 17, 2022
#This program makes a turtle move forward 10, but then turn in a random direction

import turtle
import random
beef = turtle.Turtle()

for i in range(100):
    beef.forward(10)
    a = random.randrange(0,360,1)
    beef.left(a)
