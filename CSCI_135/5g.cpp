// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// October 15, 2022
// Lab 5G

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

int nextPrime(int n)
{
    int i = n + 1;
    while (!(isPrime(i)))
    {
        i++;
    }
    return i;
}

int countPrimes(int a, int b)
{
    int num = 0;
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
        {
            num++;
        }
    }
    return num;
}

bool isTwinPrime(int n)
{
    if (!(isPrime(n)))
    {
        return false;
    }
    if (isPrime(n - 2) || isPrime(n + 2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int nextTwinPrime(int n)
{
    int i = n + 1;
    while (!(isTwinPrime(i)))
    {
        i++;
    }
    return i;
}

int largestTwinPrime(int a, int b)
{
    for (int i = b; i >= a; i--)
    {
        if (isTwinPrime(i))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int a, b;
    cout << "Enter a start number: ";
    cin >> a;
    cout << "Enter an end number: ";
    cin >> b;
    cout << largestTwinPrime(a, b);
}
