// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// September 9, 2022
// This program computes the firt 60 fibonacci numbers

#include <iostream>
using namespace std;
int main()
{
    int fib[60];
    int i;
    fib[0] = 0;
    fib[1] = 1;

    // give array index their values
    for (i = 2; i < 60; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // prints array
    for (i = 0; i < 60; i++)
    {
        cout << fib[i] << endl;
    }
    return 0;
}
