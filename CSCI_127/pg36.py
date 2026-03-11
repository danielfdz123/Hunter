#Daniel AndresParking_Violations_Jan_2016.csv Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#March 29, 2022
#This program prints out user inputed column information based on Parking_Violations_Jan_2016.csv

import pandas as pd

file = 'Parking_Violations_Jan_2016.csv'
column = input("Enter column name: ")

tickets = pd.read_csv(file)
print("The 10 worst offenders are: ")
print(tickets[column].value_counts()[:10])