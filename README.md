# CSCI_335
Hunter College: CSCI 33500 [Software Analysis &amp; Design III]

All of the three projects I worked on while taking CSCI 335 at Hunter College during the Spring 2024 semester.
____________________________________________________________________________________________________________________________________________________________
Project Description:

  (Project 1): Using the given files, I implemented a Book class in Book.cpp and a moveAll function in MoveAll.cpp. These files will read in an input file of a series of book that will then be outputed. Each book will have it title, author, ISBN, icon, price, keywords, and its blurb. If the input file can not be read, there will also be an output that displays an error message saying that the file can not be read.  

  (Project 2): Using an input of numbers, this project implements 4 ADT that consists of two operations, insert and pop median. Here, we will compare the different methods of using these ADT's and see which one is more efficent by also timing them.
      · A vector that's kept sorted
      · A linked list that's kept sorted
      · A max heap holding all elements less than or equal to the median and a min heap holding all elements greater the median
      · Two AVL trees, one holding all elements less than or equal to the median and the other holding all elements greater than the median (Also holds duplicated values)

  (Project 3): Using an input file of integer files, this project will compute all statistics included in a 5 Number Summary (Minimum, Maximum, 25th, 50th, and 75th percentiles). The std::Sort() function wil be used, along with the QuickSelect, Insertion Sort, and the Counting Sort sorting algorithms to help execute these tasks. After it is sorted, we will then print out the 5-Number summaries from each of the input files.
      · 1. Using std::sort to sort and print out the appropriate data points and use as a guideline to ensure that we have the correct answer for the following methods. 
      · 2. Here we will be using quickSelect a total of 3 times. The first will have the middle of the vector as a key, the second will partition through the lower half for the 25th percentile, and the third will partition through the upper hgalf for the 75th percentile.
      · 3. Again be using quickSelect a total of 3 times, however the keys are the only thing that changes here. This time, we are passing vector in as the keys instead of a single key.
      · 4. Numbers will be put into a hash map with the data value being the hash key and the number of occurances as the hash value. Once that is done, push them all into a vector and iterate through the vector from there to find the 5 number summary. This method will also output a unique values count, which are the total numbers in the vector excluding duplicates.  
