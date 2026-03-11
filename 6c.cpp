// Daniel Andreas Fernandez
// daniel.fernandez16@myhunter.cuny..edu
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
string encryptVigenere(string plaintext, string keyword)
{
    char c, keyc;
    int n;

    for (int i = 0; i < plaintext.size(); i++)
    {
        if (n > keyword.size() - 1)
        {
            n = 0;
        }
        c = plaintext[i];
        keyc = keyword[n];

        int kshift = (int(keyc) - 97);

        if (isalpha(c) == 0)
        {
            plaintext[i] = shiftChar(c, 0);
        }
        else
        {
            plaintext[i] = shiftChar(c, kshift);
            n++;
        }
    }
    return plaintext;
}

int main()
{
    string plaintext, kshift;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter keyword: ";
    cin >> kshift;
    cout << "Ciphertext: " << encryptVigenere(plaintext, kshift);
}
