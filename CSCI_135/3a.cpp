// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// September 21, 2022
// Lab 3, Task A

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;
int main()
{
    ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    string dates;
    cout << "Enter date (xx/xx/2018): ";
    cin >> dates;

    string junk;
    getline(fin, junk);

    string date;
    float eastSt, eastEl, westSt, westEl;
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
    {
        fin.ignore(INT_MAX, '\n');

        if (date == dates)
        {
            cout << "East Basin Storage: " << eastSt << " billion gallons." << endl;
        }
    }
    fin.close();
}
