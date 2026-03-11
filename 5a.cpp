// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// October 15, 2022
// Lab 5A

#include <iostream>
using namespace std;
bool isDivisibleBy(int n, int d)
{
    if (d == 0)
    {
        return false;
    }
    else if (n % d == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n, d;
    cout << "Enter a dividen: ";
    cin >> n;
    cout << "Enter a divisor: ";
    cin >> d;

    if (isDivisibleBy(n, d) == 1)
    {
        cout << n << " is divisible by " << d << '.';
    }
    else
    {
        cout << n << " is not divisible by " << d << '.';
    }
    return 0;
}
