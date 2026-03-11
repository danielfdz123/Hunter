// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// September 21, 2022
// This program prints a traingle made of *, but the length is determined via the user

#include <iostream>
using namespace std;
int main()
{
    int length;
    cout << "Enter side length: ";
    cin >> length;
    int k = 1;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << "*";
        }
        cout << endl;
        k++;
    }
    return 0;
}
