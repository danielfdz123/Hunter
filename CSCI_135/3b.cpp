// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// September 26, 2022
// Lab 3B

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

    string junk;
    getline(fin, junk);

    string date;
    float eastSt, eastEl, westSt, westEl;

    float min = INT_MAX;
    float max = INT_MIN;

    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
    {
        fin.ignore(INT_MAX, '\n');
        if (eastSt < min)
        {
            min = eastSt;
        }
        else if (eastSt > max)
        {
            max = eastSt;
        }
    }
    fin.close();
    cout << "Minimum storage in East basin: " << min << " billion gallons." << endl;
    cout << "Maximum storage in East basin: " << max << " billion gallons." << endl;
}
