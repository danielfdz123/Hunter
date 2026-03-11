//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//August 25, 2022
//Finding the smaller number of two integers

#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cout << "Enter the first number: ";
    cin >> x;
    cout << "Enter another number: ";
    cin >> y;
    if (x > y){
        cout << "The smaller of the two is " << y;
    }
    else{
        cout << "The smaller of the two is " << x;
    }
    return 0;
}
    
