
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

int main()
{
    int n;
    cout << "Enter a start number: ";
    cin >> n;

    if (isTwinPrime(n) == 1)
    {
        cout << "Is a Twin Prime.";
    }
    else
    {
        cout << "Not Twin Prime.";
    }
}
