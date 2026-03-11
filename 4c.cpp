// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// October 3, 2022
// Lab 4C

#include <iostream>
using namespace std;
int main()
{
    int length;
    cout << "Enter length: ";
    cin >> length;

    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            if (i == j || j == (length + 1 - i))
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
