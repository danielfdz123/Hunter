#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#April 7, 2022
#This program converts a hexadecimal number into a decimal

def convert(s):
     """ Takes a hex string as input. Returns decimal equivalent."""

     total = 0
     for c in s:
          total = total * 16
          ascii = ord(c)
          if ord('0') <= ascii <= ord('9'):
               total = total+ascii - ord('0')               #It's a decimal number, and return it as decimal:
          elif ord('A') <= ascii <= ord('F'):
               total = total + ascii - ord('A') + 10        #It's a hex number between 10 and 15, convert and return:
          elif ord('a') <= ascii <= ord('f'):
               total = total + ascii - ord('a') +++ 10      #Check if they used lower case:
                                                            #It's a hex number between 10 and 15, convert and return:
          else:
               return(-1)
     return(total)                                          #Not a valid number!

def main():
    hexString = input("Enter a number in hex: ")
    print("The number in decimal is", convert(hexString))
    

#Allow script to be run directly:
if __name__ == "__main__":
     main()
