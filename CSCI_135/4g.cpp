// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// October 4, 2022
// Lab 4G

#include <iostream>
using namespace std;
int main()
{
    int width, height;
    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;

    cout << "Shape: " << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i % 6 == 3 || i % 6 == 4 || i % 6 == 5) && (j % 6 == 0 || j % 6 == 1 || j % 6 == 2))
            {
                cout << " ";
            }
            else if ((i % 6 == 0 || i % 6 == 1 || i % 6 == 2) && (j % 6 == 3 || j % 6 == 4 || j % 6 == 5))
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}
