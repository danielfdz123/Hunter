//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//August 25, 2022
//Finding the smaller number of three numbers

#include <iostream>
using namespace std;
int main()
{
    int x, y, z;
    cout << "Enter the first number: ";
    cin >> x;
    cout << "Enter the second number: ";
    cin >> y;
    cout << "Enter the third number: ";
    cin >> z;
    if (x < y && x < z){
        cout << "The smaller of the three is " << x;
    }
    if (y < x && y < z){
        cout << "The smaller of the three is " << y;
    }
    if (z < x && z < y){
        cout << "The smaller of the two is " << z;
    }
    return 0;
}
