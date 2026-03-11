#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#March 10, 2022
#This program prints the average/maximum population of a borough based on the user input

import matplotlib.pyplot as plt
import pandas as pd

pop = pd.read_csv('nycHistPop.csv',skiprows=5)
borough = input("Enter borough: ")
mean = pop[borough].mean()
maxi = pop[borough].max()

print("Average population: ", mean)
print("Maximum populationL ", maxi)
