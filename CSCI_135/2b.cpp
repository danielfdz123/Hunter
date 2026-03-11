//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//September 7, 2022
//Printing all the numbers from one end to the other, based on user inout

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num1, num2;
    cout << "Enter an integer: ";
    cin >> num1;
    cout << "Enter another integer: ";
    cin >> num2;
    for(int i = num1; i < num2; i++) {
        cout << i << ' ';
    }
    return 0;
}
    
