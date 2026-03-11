#Daniel Andres Fernandea
#daniel.fernandez16@myhunter.cuny.edu
#March 1, 2022
#This program loads an image, displays it, and then creates, display and saves a new image that has only the red channel displayed.

import matplotlib.pyplot as plt    #Import the packages for images and arrays:
import numpy as np

img = plt.imread('csBridge.png')         #Read in image from csBridge.png

#Show original image
plt.imshow(img)
plt.show()                

#Make changes to image
img2 = img.copy()        # Copy image
img2[:,:,0] = 0          # Red channel = 0
img2[:,:,1] = 0          # Green channel = 0

#Show new image
plt.imshow(img2)
plt.show()                  

plt.imsave('blueH', img2)  #Save the image we created to the file: blueH.png