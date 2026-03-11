#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#March 4, 2022
#This program print out a grid determined by the user, that alternates in red/white stripes

import matplotlib.pyplot as plt
import numpy as np

dimension = int(input("Enter size: "))

# Create an empty image (initialized to black)
img = np.zeros((dimension, dimension, 3))

# Set alternating rows to red (1, 0, 0)
img[::2, :, 0] = 1  # Red rows

# Set other rows to white (1, 1, 1)
img[1::2, :, :] = 1  # White rows

plt.imshow(img)
plt.show()