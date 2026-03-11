#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#March 4, 2022
#This program prints a string in a list that adds 1 character per line 

s = input("Enter a message: ")
ls=len(s)
for i in range(ls):
    print(s[0:i])
for i in range(ls):
    print(s[i:ls])
