// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// September 21. 2022
// This code prints a box full of stars

#include <iostream>
using namespace std;

int main()
{
    int width, length;
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter length: ";
    cin >> length;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
