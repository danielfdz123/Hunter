// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// October 15, 2022
// Lab 5b

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

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (isDivisibleBy(n, i))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPrime(n) == 1)
    {
        cout << "This is a prime number.";
    }
    else
    {
        cout << "Not a prime number.";
    }
    return 0;
}
