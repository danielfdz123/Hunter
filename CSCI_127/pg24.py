#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#March 6, 2022
#This program outputs the total number of plural nouns

nouns = input("Enter nouns: ")
word = nouns.count(" ")
total = word + 1

if total == 1:
    print("There is", total, "word")
else: 
    print("There are", total, "words")

plural = nouns.count("s ")

if nouns[-1] == 's':
    plural = plural + 1
    fraction = plural / total
    print("Fraction of your list that is plural:", fraction)
else:
    fraction = plural / total
    print("Fraction of your list that is plural:", fraction)