//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//May 2, 2022
//This C++ Program greets you depending on what month (by number) the user enters

#include <iostream>
using namespace std;
int main()
{
    int month;
    cout<<"Enter the month: ";
    cin >>month;
    if (month<3 || month>11)
    { 
        cout<<"Happy Winter";
    }
    else if (month<=3 && month<7)
    {
        cout<<"Happy Spring";
    }
    else if(month>=7 && month<9)
    {
        cout<<"Happy Summer";
    }
    else
    {
        cout<<"Happy Fall";
    }
    return 0;
}
