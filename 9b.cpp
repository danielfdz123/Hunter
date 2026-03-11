// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny,edu
// November 13, 2022
// Lab 9b

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

double length(Coord3D *p)
{
    double x = p->x;
    double y = p->y;
    double z = p->z;
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Coord3D *fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
    if (length(p1) > length(p2))
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
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl
         << endl;

    Coord3D *ans = fartherFromOrigin(&pointP, &pointQ);

    cout << "Furthest Point: " << ans << endl; // So which point is farther?
}
