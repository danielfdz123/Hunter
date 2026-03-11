#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#February 20, 2022
#This program prints an encrypted message

word = input("Enter a word: ")
codedWord = ""
for ch in word:
    offset = ord(ch) - ord('a') + 13
    wrap = offset % 26
    newChar = chr(ord('a') + wrap)
    print(wrap, chr(ord('a') + wrap))
    codedWord = codedWord + newChar

print("Your word in code is: ", codedWord)
