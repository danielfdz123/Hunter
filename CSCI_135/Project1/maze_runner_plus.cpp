// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// September 29, 2022
// Project 1 Task C

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int maze[6][6] =
        {
            1, 0, 1, 1, 1, 1,
            1, 0, 0, 0, 1, 1,
            1, 0, 1, 0, 0, 1,
            1, 0, 1, 0, 1, 1,
            1, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1};

    string x;
    int row = 0;
    int col = 1;
    int end_row = 4;
    int end_col = 5;

    cout << "Enter one or more strings of movement commands (R, L, U, D), and end it with ';', or only type 'G' to give up." << endl
         << "(Ex: ULL; RRR;)" << endl;

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
                    return 0;
                }
            }
            else if (i == "R")
            {
                if (maze[row][col + 1] != 1)
                {
                    col++;
                    cout << "Current Position: (" << row << ", " << col << ")." << endl;
                }
                else
                {
                    cout << "Invalid move." << endl;
                }
            }
            else if (i == "L")
            {
                if (maze[row][col - 1] != 1)
                {
                    col--;
                    cout << "Current Position: (" << row << ", " << col << ")." << endl;
                }
                else
                {
                    cout << "Invalid move." << endl;
                }
            }
            else if (i == "U")
            {
                if (maze[row - 1][col] != 1)
                {
                    row--;
                    cout << "Current Position: (" << row << ", " << col << ")." << endl;
                }
                else
                {
                    cout << "Invalid move." << endl;
                }
            }
            else if (i == "D")
            {
                if (maze[row + 1][col] != 1)
                {
                    row++;
                    cout << "Current Position: (" << row << ", " << col << ")." << endl;
                }
                else
                {
                    cout << "Invalid move." << endl;
                }
            }
            else if (i == "G")
            {
                cout << "You are stuck in the maze.";
                return 0;
            }
            else
            {
                row = row;
                col = col;
            }
        }
    }
    return 0;
}