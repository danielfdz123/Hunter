#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#March 10, 2022
#This program organizes a list of names by last name, first name

fullNames = input("Enter a list of names (Ex: Doe, John; Doe, Jane): ")        #Creates variable
namelist = fullNames.split("; ")                                             #Splits ; from list of names

for i in namelist:
    beef = i.split(", ")                                                 #Splits , from first/last names
    print(beef[1] + ' ' + beef[0])                                       #Puts the names in First/Last name order
print("Thank you for using my name organizer!")