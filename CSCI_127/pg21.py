#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#March 5, 2022
#This program reads an image and counts the amount of white pixels, which are meant to represent snow

import matplotlib.pyplot as plt
import numpy as np

ca = plt.imread('CaliforniaDrought_02232011_md.png')   #Read in image
countSnow = 0                 #Number of pixels that are almost white
t = 0.75                      #Threshold for almost white-- can adjust between 0.0 and 1.0

#For every pixel:
for i in range(ca.shape[0]):
     for j in range(ca.shape[1]):   #Check if red, green, and blue are > t:
          if (ca[i,j,0] > t) and (ca[i,j,1] > t) and (ca[i,j,2] > t):
               countSnow = countSnow + 1

print("Snow count is", countSnow)