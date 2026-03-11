#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#April 6, 2022
#This program is a function that returns LIRR fees

def computeFare(zone, ticketType):
     
     fare1 = 8.75
     fare2 = 6.25
     fare3 = 10.25
     fare4 = 7.50
     fare5 = 12.00
     fare6 = 13.50
     fare7 = 9.75
     fare8 = 1

     if zone == 1 and ticketType == "peak":
          return(fare1)
     elif zone == 1 and ticketType == "off-peak":
          return(fare2)
     elif (zone == 2 or zone == 3) and ticketType == "peak":
          return(fare3)
     elif (zone == 2 or zone == 3) and ticketType == "off-peak":
          return(fare4)
     elif zone == 4 and ticketType == "peak":
          return(fare5)
     elif zone == 4 and ticketType == "off-peak":
          return(fare1)
     elif (zone == 5 or zone == 6 or zone == 7) and ticketType == "peak":
          return(fare6)
     elif (zone == 5 or zone == 6 or zone == 7) and ticketType == "off-peak":
          return(fare7)
     elif zone >= 8:
          return(fare8)

def main():
     z = int(input('Enter the zone number: '))
     t = input('Enter the ticket type (peak/off-peak): ').lower()
     fare = computeFare(z,t)
     print('The fare is', fare)

#Allow script to be run directly:
if __name__ == "__main__":
     main()
                   
