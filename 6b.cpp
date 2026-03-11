// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// October 23, 2022
// Lab 6B

#include <iostream>
using namespace std;
char shiftChar(char c, int rshift)
{
    if (islower(c))
    {
        c = (c - 'a' + rshift) % 26 + 'a';
    }
    else if (isupper(c))
    {
        c = (c - 'A' + rshift) % 26 + 'A';
    }
    return c;
}
string encryptCaesar(string plaintext, int rshift)
{
    string newstring;
    for (int i = 0; i < plaintext.size(); i++)
    {
        if (isalpha(plaintext[i]))
        {
            newstring += shiftChar(plaintext[i], rshift);
        }
        else
        {
            newstring += plaintext[i];
        }
    }
    return newstring;
}
int main()
{
    string word;
    cout << "Enter a string: ";
    getline(cin, word);
    int shift;
    cout << "Enter a shift: ";
    cin >> shift;
    cout << "Ciphertext: " << encryptCaesar(word, shift);
}
