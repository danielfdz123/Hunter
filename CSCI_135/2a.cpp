//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//September 7, 2022
//Squaring a number as long as its between 0 and 100

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    while(1 > num or num > 99){
        cout << "Integer out of range, enter one between 0 and 100: ";
        cin >> num;
    }
    num = pow(num, 2);
    cout << "Number squared is: " << num;
    return 0;
}
    
