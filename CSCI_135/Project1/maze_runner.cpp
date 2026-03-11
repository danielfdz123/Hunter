// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// September 22, 2022
// Project 1 Task B

#include <iostream>
#include <string>
using namespace std;

int endY(int startY, char letter), endX(int startX, char letter);
void success(int goalX, int pickX, int goalY, int pickY);
bool valid(int pickX, int pickY, int maze[6][6]);
int maze[6][6] = {
    1, 0, 1, 1, 1, 1,
    1, 0, 0, 0, 1, 1,
    1, 0, 1, 0, 0, 1,
    1, 0, 1, 0, 1, 1,
    1, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1};

int main()
{
    int pickX = 1;
    int pickY = 0;
    int goalX = 5;
    int goalY = 4;
    char s;

    cout << "Enter movement commands (R, L, U, D). Type G to give up." << endl;

    while (cin >> s)
    {
        // Give Up option
        if (s == 'G')
        {
            break;
        }

        // Calculate new position
        int newX = endX(pickX, s);
        int newY = endY(pickY, s);

        // Check if the move is valid
        if (valid(newX, newY, maze))
        {
            pickX = newX;
            pickY = newY;
            cout << "Current Position: (" << pickX << ", " << pickY << ") \n";

            // Check if the player has reached the goal
            if (pickX == goalX && pickY == goalY)
            {
                success(goalX, pickX, goalY, pickY);
                return 0; // Exit the program immediately
            }
        }
        else
        {
            cout << "Invalid move.\n"; // Inform user of invalid move
        }
    }

    // If the loop ends and the player hasn't reached the goal
    success(goalX, pickX, goalY, pickY);
    return 0;
}

int endX(int startX, char alphabet)
{
    if (alphabet == 'R')
    {
        startX += 1;
    }
    else if (alphabet == 'L')
    {
        startX -= 1;
    }
    return startX;
}

int endY(int startY, char yea)
{
    if (yea == 'D')
    {
        startY += 1;
    }
    else if (yea == 'U')
    {
        startY -= 1;
    }
    return startY;
}

void success(int goalX, int pX, int goalY, int pY)
{
    if (goalX == pX && goalY == pY)
    {
        cout << "You got out of the maze.\n";
    }
    else
    {
        cout << "You are stuck in the maze.\n";
    }
}

bool valid(int pX, int pY, int maze[6][6])
{
    // Check boundaries and whether the cell is passable
    return (pX >= 0 && pX < 6 && pY >= 0 && pY < 6 && maze[pY][pX] == 0);
}
