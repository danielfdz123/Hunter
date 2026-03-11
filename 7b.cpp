//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//Octoberr 31, 2022
//Lab 7b

#include <iostream>
#include <cctype>
using namespace std;

int countChar(string line, char c)
{
    int open = 0;
    for (int i = 0; i < line.length(); i++) 
    {
        if (line[i] == c)
        {
            open++;
        }
    }
  return open;
}

string removeLeadingSpaces(string line) 
{
    int i = 0;
    string spaces = "";
    while(isspace(line[i])) 
    {
        i++;
    }
    spaces = line.substr(i,line.length());
    return spaces;
}

int main()
{
    string line;
    int open = 0;
    int Tnum = 0;
    int openplus;
    char c = '{';
    char s = '}';
    string correctLine;
    while (getline(cin,line))
    {
        correctLine = removeLeadingSpaces(line);
        openplus = countChar (correctLine, c);
        open += openplus;
        for (int i=0; i<correctLine.length(); i++) 
        {
            if (correctLine[i] == s)
            {
                open--;
            }

        }
        if (correctLine[0] == s && openplus<=1)
        {
            Tnum--;

        }
        for (int i=0; i<Tnum; i++)
        {
            cout << "\t";
        }
        Tnum = open;
        cout << correctLine << endl;

    }
}
