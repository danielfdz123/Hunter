//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny,edu
//November 13, 2022
//Lab 9b

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Coord3D 
{
public:
    double x;
    double y;
    double z;
};

void move(Coord3D *ppos, Coord3D *pvel, double dt)
{
    ppos -> x += pvel -> x * dt;
    ppos -> y += pvel -> y * dt;
    ppos -> z += pvel -> z * dt;
}

double length(Coord3D* p)
{
    double x = p -> x;
    double y = p -> y;
    double z = p -> z;
    return sqrt(pow(x, 2) + pow(y,2) + pow(z, 2));
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
    if(length(p1) > length(p2))
    {
        return p1;
    }
    else
    {
        return p2;
    }
}

int main() 
{
    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0); 
    cout << pos.x << " " << pos.y << " " << pos.z << endl;
}
