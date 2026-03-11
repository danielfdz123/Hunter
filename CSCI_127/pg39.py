#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#April 1, 2022
#This program prints the top 3 contributing factors for vehicle colisions

import pandas as pd

file = input("Enter CSV file name: ")
colisions = pd.read_csv(file)
print("Top three contributing factors for collisions: ")
print(colisions["CONTRIBUTING FACTOR VEHICLE 1"].value_counts()[:3])