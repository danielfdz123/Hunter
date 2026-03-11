#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#March 17, 2022
#This program prints the lower left quarter of an image specified by the user

import matplotlib.pyplot as plt
import numpy as np

# File specifications
image = 'hunterLogo.png'
output = 'hunterQuarter.png'

# Showing original image & setting dimension
img = plt.imread(image)
plt.imshow(img)
plt.show()
height = img.shape[0]
width = img.shape[1]

# Cropping image
img2 = img[height//2:, :width//2]

# Showing new image, then saving it to directory
plt.imshow(img2)
plt.show()
plt.imsave(output,img2)
