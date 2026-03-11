//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny,edu
//November 13, 2022
//Lab 9a

#include <iostream>
#include <cmath>
using namespace std;


class Coord3D 
{
public:
    double x;
    double y;
    double z;
};

double length(Coord3D *p)
{
    double x = p -> x;
    double y = p -> y;
    double z = p -> z;
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}


int main() 
{
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl; 
}
