// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny,edu
// November 13, 2022
// Lab 9d

#include <iostream>
using namespace std;

string *createAPoemDynamically()
{
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main()
{
    while (true)
    {
        string *p;
        p = createAPoemDynamically();

        // assume that the poem p is not needed at this point
        delete p;
    }
}