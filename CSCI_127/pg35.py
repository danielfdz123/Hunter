#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#March 29, 2022
#This program prints out a greeting depending on what time it is

time = int(input("Enter an hour of the day (24 hr time): "))

if 12 > time:
    print("Good Morning!")
elif 17 > time > 11:
    print("Good Afternoon!")
else:
    print("Good Evening!")
