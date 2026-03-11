// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// October 6, 2022
// Project 1 Task D

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int maze[10][10];
    int start_row, start_col, end_row, end_col, row, col;

    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            cin >> maze[r][c];
        }
    }
    cin >> start_row >> start_col >> end_row >> end_col;
    row = start_row;
    col = start_col;

    string semicolon;
    while (semicolon != ";")
    {
        cin >> semicolon;
    }

    string x;
    while (cin >> x)
    {
        string arr[x.size()];
        for (int i = 0; i < x.size(); i++)
        {
            arr[i] = x[i];
        }
        for (string i : arr)
        {
            if (i == ";")
            {
                if (row == end_row && col == end_col)
                {
                    cout << "You got out of the maze." << endl;
                }
                else
                {
                    cout << "You are stuck in the maze." << endl;
                }
                row = start_row;
                col = start_col;
            }
            if (i == "R" && maze[row][col + 1] != 1)
            {
                col++;
            }
            else if (i == "L" && maze[row][col - 1] != 1)
            {
                col--;
            }
            else if (i == "U" && maze[row - 1][col] != 1)
            {
                row--;
            }
            else if (i == "D" && maze[row + 1][col] != 1)
            {
                row++;
            }
            else
            {
                row = row;
                col = col;
            }
        }
    }
}