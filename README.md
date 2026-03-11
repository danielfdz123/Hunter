# CSCI 135 (Software Analysis & Design I)

Hunter College: CSCI 13500 [Software Analysis & Design I]

All of the coding lab assignments I worked on while taking CSCI 135 at CUNY Hunter College during the Fall 2022 semester. Below is a description of what each program does.
____________________________________________________________________________________________________________________________________________________________
**• INTRO TO LINUX AND TO C++**

  1a.cpp- Prompts the user to give 2 numbers, and output the smallest one fo the two
  
  1b.cpp- Prompts the user to give 3 numbers, and output the smallest of the 3
  
  1c.cpp- Primpts the user to enter a year and determines wether or not it is a leap year or not
  
  1d.cpp- Prompts the user to enter a month and year, to determine wether ot not it is a leap year or not, along with the amount of days in said month (28, 29, 30, 31)
  

**• LOOPS & ARRAYS**

  2a.cpp- Prompts the user to enter a number then it squares it
  
  2b.cpp- Prompts the user to enter 2 numbers, then will output all the numbers between said numbers
  
  2c.cpp- With an array of 10 ones, this code prompts the user to edit the array by selecting a valid index, then editing the value of that index with any number of their choice
  
  2d.cpp- Computes the first 60 digits of the fobonacci sequence

**• FILE I/O, PROCESS DATA** (_3a-3d will use the same input file_)

  3a.cpp- Reads in a file containing information about NYC's reservoirs from the year 2018. This program will prompt the user for a date, then output the recorded reservoir storage from that day
  
  3b.cpp- This progtam will output the highest and lowest recorded reservoir level
  
  3c.cpp- This program will prompt the user for two dates, then will output which basin (East/West) had a higher level than the other. If the levels are equal, then the program can also output that the levels are equal amongst the two basins
  
  3d.cpp- Prompts the user for two dates, then will output the recorded elevation for all the dates between the two dates the user has entered, all of which come from the WEST basin. However, the output of these records will be in reverse chronological order

**• PRINTING SHAPES**

  4a.cpp- Will prompt the user to enter two numbers, one that represents width and that other that represents length. Using these values, it'll output a box full of stars using the given width and length.
  
  4b.cpp- Does the exact same thing that 4a.cpp does, however there will be spaces between the stars, giving the stars a pattern going down the rows.
  
  4c.cpp- Prompts the user to enter a lengt, then will output an X that extends to the corresponding length
  
  4d.cpp- Prompts the user to enter a length, then will output an right triangle that extends down to the corresponding length. This triangle will be on the bottom left corner
  
  4e.cpp- Prompts the user to enter a length, then will output an right triangle that extends down to the corresponding length. This triangle will be on the top right corner, opposite from where 4d.cpp is
  
  4f.cpp- Prompts the user to enter a width and height which will then be used to make an upside down trapezoid
  
  4g.cpp- Prompts the user to enter a width and height which will then be used to make an alternating pattern of 3x3 squares made from stars.

**• FUNCTIONS AND PRIME NUMBERS**

  5a.cpp- Prompts the user to enter two numbers, and checks divisibility amongst them.
  
  5b.cpp- Prompts the user to enter a number, which checks if its prime or not
  
  5c.cpp- Prompts the user to enter a number, and the program will output a prime number that is closest and greater than the number given by the user
  
  5d.cpp- Prompts the user to enter a range of two numbers, which will then let us know how many prime number there are between these given numbers
  
  5e.cpp- Prompts the user to enter a number, which checks if its a twin prime or not
  
  5f.cpp- Prompts the user to enter a number, then outputs the closest, greater prime number to said number
  
  5g.cpp- Prompts the user to enter a range of two numbers, which will then let us know the greatest twin prime number within that range of those two numbers given by the user

**• STRINGS AND CYPHERS**

  6a.cpp- Using a string from the user, this program outputs the corresponding ASCII value of each character within the string
  
  6b.cpp- Using a string from the user, and a set shift length, this program shifts eachg character by the given shift length by the user, then outputs the new string generated after the shift
  
  6c.cpp- Using a string from the user, and a set keyword, this program will encryt the string using each character from the keyword via the Vigenere cipher method
  
**• AUTO STYLE**

  7a.cpp- This program reshapes the block of code by removing any leading spaces from each line
  
  7b.cpp- This program reshapes the block of code by adding any neccesary indentation to the code, making it easier to read

**• IMAGE PROCESSING**

  8a.cpp- Reads in an image, then inverts all the colors of that image
  
  8b.cpp- Reads in an image, then inverts all the colors of the RIGHT HALF of the image
  
  8c.cpp- Reads in an image and puts a solid white box in the middle of the image
  
  8d.cpp- Reads in an image and puts a solid white frame in the middle of the image
  
  8d.cpp- Reads in an image and increases the scale of the image to 200%
  
  8f.cpp- Reads in an image and makes it pixelated

**• POINTERS**

  9a.cpp- Using a set of x, y, z coordinates, this program will calculate the distance to get to point P with those sets of coordinates by using the euclidean distance formula
  
  9b.cpp- Using two sets of x, y, z coordinates, this program will calculate the distance to get to point P by also using the euclidean distance formula. However, it will let us know which point is further
  
  9c.cpp- Using a set of x, y, z coordinates and velocity, this program calculatesb the upddated position of a point based on its velocity
  
  9d.cpp- Does the same thing as 9c.cpp. However, we were given an incomplete function and our goal for this code was to fix it and have it running properly
  
  9e.cpp- Using a set string, this code dynamically allocates the memory of tthe stringm assignes it to a pointer then deletes the memory to avoid memory leaks

**• CLASSES**
  10a.cpp- Prompts the user to enter two intervals of time, and the program will output how many minutes each time is after midnight, along with their difference

  10b.cpp- Prompts the user to enter a start time, and an amount of minutes we would like to add to this start time. Then the program wil output the new time with these added minutes

  10c.cpp- Using a designated movie title, genre, and duration, it will output a movie schedule of when it starts and ends in 24 hour time format

  10d.cpp- Using a designated movie title, genre, and duration, it will otuput a schedule to where the next movie will play as soon as the previous one ends.

  10e.cpp- Using a designated movie title, genre, and duration, this program will output wether or not the timing of the two movies overlap eachother

**• MORE CLASSES** (Code builds off of one another as we progress in this section)

  11a.cpp- Implementing a profile class, this program manages the users profile with a username and their display name, allowing all of it to be displayed/updated

  11b.cpp- Implementing a new class called network, this program creates new users and sees wether or not the creating was a success or not. (1 = success; 0 = failure)

  11c.cpp- Using both a profile and network class, this program allows users to follow one another using he new follow function implemented in the Network function. The follow log will be in Dot file format
  
  11d.cpp- Implementing a new struct called Post, which will allow us to make posts and have the timeline of each username.

**• VECTORS**

  12a.cpp- This program returns a vector of n integers that range from 0 to n-1

  12b.cpp- This program returns a vector of only positive integers in the same order it was defined in

  12c.cpp- This program takes 2 vectors, and combines the two into one big vector. The results are then outputted

  12d.cpp- This program takes 2 vectors and adds the corresponding index of each vector together. The results are then outputted

