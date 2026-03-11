// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// April 26, 2022
// This C++ program converts km to miles

#include <iostream>
using namespace std;

int main() // C++ programs all have a main() function
{
    double num;
    cout << "Enter number in kilometers: ";
    cin >> num;

    double num1 = num * 0.621371;
    cout << "miles = " << num1;

    return 0;
}
