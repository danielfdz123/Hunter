// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// October 3, 2022
// Lab 4E

#include <iostream>
using namespace std;
int main()
{
    int length;
    cin >> length;
    for (int i = length; i > 0; i--)
    {
        for (int j = length; j > 0; j--)
        {
            if (i >= j)
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
