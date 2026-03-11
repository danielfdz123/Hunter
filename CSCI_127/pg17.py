#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#March 4, 2022
#This program askes the user for a noun and two verbs, then prints out a sentence

noun = input("Enter a noun: ")
verb1 = input("Enter a verb: ")
verb2 = input("Enter another verb: ")

template = "If it VERB1 like a NOUN and VERB2 like a NOUN, it probably is a NOUN."
template = template.replace("NOUN", noun)
template = template.replace("VERB1", verb1)
template = template.replace("VERB2", verb2)

print(template)
