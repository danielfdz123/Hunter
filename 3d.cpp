// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// September 26, 2022
// Lab 3D

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
        cerr << "File cannot be opened for reading.";
        exit(1);
    }

    string start_date, end_date;
    cout << "Enter starting date (xx/xx/2018): ";
    cin >> start_date;
    cout << "Enter ending date (xx/xx/2018): ";
    cin >> end_date;

    string junk;
    getline(fin, junk);

    string date, westEl;
    double eastSt, eastEl, westSt;
    bool beef = false;
    string west_arr[365][2];

    int i = 0;
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
    {
        fin.ignore(INT_MAX, '\n');
        if (start_date == date)
        {
            beef = true;
        }
        if (beef == true)
        {
            west_arr[i][0] = date;
            west_arr[i][1] = westEl;
            i++;
        }
        if (end_date == date)
        {
            fin.close();
            break;
        }
    }

    for (int j = i - 1; j >= 0; j--)
    {
        cout << west_arr[j][0] << ": " << west_arr[j][1] << " ft" << endl;
    }
}
