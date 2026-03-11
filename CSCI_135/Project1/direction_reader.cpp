// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// September 18, 2022
// Project 1 Task A

#include <iostream>
using namespace std;
int main()
{
    string letters;
    cout << "Enter a list of commands: ";
    while (cin >> letters)
    {
        if (letters == "R")
        {
            cout << "Right" << endl;
        }
        else if (letters == "L")
        {
            cout << "Left" << endl;
        }
        else if (letters == "U")
        {
            cout << "Up" << endl;
        }
        else if (letters == "D")
        {
            cout << "Down" << endl;
        }
        else
        {
            cout << "Not a command!" << endl;
        }
    }
}
