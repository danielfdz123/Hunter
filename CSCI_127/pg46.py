#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#April l7, 20222
#This program asks the ruser to input a string, but if its empty it'll ask to enter a non empty string

beef = input("Enter a non-empty string: ")

while beef == '':
    print("That was empty. Try again.")
    beef = input("Enter a non-empty string: ")
else:
    print("You entered:", beef)
