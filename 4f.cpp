//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//October 3, 2022
//Lab 4F

#include <iostream>
using namespace std;
int main()
{
    int width, height, stars, spaces;
    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;
    
    spaces = 0;
    stars = width;
    for (int i = 0; i < height; i++)
    {
        spaces += 1;
        stars -= 2;
    }
    
    if(stars + 1 < 0)
    {
        cout << "Impossible Shape!";
    }
    else
    {
        cout << "Shape: " << endl;

        for(int j = 0; j < height; j++)
        {
            for(int k = 0; k < width; k++)
            {
                if(j >= k + 1 || k >= width - j)
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
    }
    return 0;
}
