#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#April 1, 2022
#This program prints the month name with its corresponding number upon input using functions
     
def monthString(monthNum):
    if monthNum == 1:
        monthString = "January"
    elif monthNum == 2:
         monthString = "February"
    elif monthNum == 3:
         monthString = "March"
    elif monthNum == 4:
         monthString = "April"
    elif monthNum == 5:
         monthString = "May"
    elif monthNum == 6:
         monthString = "June"
    elif monthNum == 7:
         monthString = "July"
    elif monthNum == 8:
         monthString = "August"
    elif monthNum == 9:
         monthString = "September"
    elif monthNum == 10:
         monthString = "October"
    elif monthNum == 11:
         monthString = "November"
    elif monthNum == 12:
         monthString = "December"

    return(monthString)

def main():
     n = int(input('Enter the number of the month: '))
     mString = monthString(n)
     print('The month is', mString)

#Allow script to be run directly:
if __name__ == "__main__":
     main()
