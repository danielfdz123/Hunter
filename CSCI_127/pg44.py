#Danie Andres Fernandez
#daniel.fernandez16@myhunter.cuny.edu
#April 7, 2022
#This program creates a map and marks the current location and closest CUNY

import folium
import pandas as pd

def getData():                    
    name = 'CUNYcampuses.csv'
    df = pd.read_csv(name)

    return(df)

def getColumnNames():               
    latName = 'Latitude'
    lonName = 'Longitude'
    return(latName,lonName)

def getLocale():
    lat = float(input ("Enter current latitude: "))
    lon = float(input ("Enter current longtitude: "))
    return(lat, lon)

def computeDist(x1,y1,x2,y2):
    d = 0.0
    d = ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))

    return(d)

def dotAllPoints(cMap,df,latCol,lonCol):
    for i, row in df.iterrows():
        folium.CircleMarker(location=[row[latCol],row[lonCol]], radius=4,color='red').add_to(cMap)


def markAndFindClosest(cMap,df,latCol,lonCol,cLat,cLon):
     df['Dist'] = df[[latCol,lonCol]].apply(lambda row: computeDist(*row,cLat,cLon), axis=1)
     minRow = df[df['Dist'] == df['Dist'].min()]
     
     folium.Marker(location=[float(minRow[latCol]),float(minRow[lonCol])],popup="Closest CUNY Campus").add_to(cMap)
     folium.Marker(location=[cLat,cLon],popup="You Are Here",icon=folium.Icon(color='red')).add_to(cMap)
     
def writeMap(cMap):
     outF = 'closestPoint.html'
     cMap.save(outfile=outF)

def main():
     dataF = getData()
     latColName, lonColName = getColumnNames()
     lat, lon = getLocale()
     cityMap = folium.Map(location = [lat,lon], tiles = 'cartodbpositron',zoom_start=11)
     dotAllPoints(cityMap,dataF,latColName,lonColName)
     markAndFindClosest(cityMap,dataF,latColName,lonColName,lat,lon)
     writeMap(cityMap)

if __name__ == "__main__":
     main()