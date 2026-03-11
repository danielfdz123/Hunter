// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// Octoberr 31, 2022
// Lab 7a

#include <iostream>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string line)
{
    int i = 0;
    string spaces = "";
    while (isspace(line[i]))
    {
        i++;
    }
    spaces = line.substr(i, line.length());
    return spaces;
}

int main()
{
    string input;
    int count = 0;
    while (getline(cin, input))
    {
        if (removeLeadingSpaces(input)[0] == '}')
        {
            for (int i = 0; i < count - 1; i++)
            {
                cout << '\t';
            }
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                cout << '\t';
            }
        }
        cout << removeLeadingSpaces(input) << "\n";
    }
}