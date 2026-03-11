#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#April 7, 2022
#This program prints out a collision map

import folium
import pandas as pd

beef = input('Enter file name: ')
out = input('Enter output file: ')

file = pd.read_csv(beef)
print(file["TIME"])

mapNY = folium.Map(location=[40.768731, -73.964915],tiles="Cartodb Positron")

for index,row in file.iterrows():
    lat = row["LATITUDE"]
    lon = row["LONGITUDE"]
    name = row["TIME"]
    newMarker = folium.Marker([lat, lon], popup=name)
    newMarker.add_to(mapNY)

mapNY.save(outfile=out + ".html")
