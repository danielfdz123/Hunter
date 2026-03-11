// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny..edu
// October 22, 2022
// Lab 6A

#include <iostream>
using namespace std;
int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i] << " " << (int)s[i] << endl;
    }
    return 0;
}