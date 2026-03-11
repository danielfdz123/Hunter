#Daniel Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#April 6, 2022
#This program a map of NYC iwth a marker on Hunter College

import folium

mapCUNY = folium.Map(location=[40.75, -74.125], zoom_start=10)
folium.Marker(location = [40.768731, -73.964915], popup = "Hunter College").add_to(mapCUNY)
mapCUNY.save(outfile='nycMap.html')