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

    bool star = true, start_star = true;
    for (int i = 0; i < length; i++)
    {
        star = start_star;
        for (int j = 0; j < width; j++)
        {
            if (star)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
            star = !star;
        }
        start_star = !start_star;
        cout << endl;
    }
    return 0;
}
