//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//May 12, 2022
//This C++ program prints out a the birth year of the user, but keeps asking if its 2018 or more recent

#include <iostream>
using namespace std;
int main()
{
    int age;
    cout << "Enter your birth year: ";
    cin >> age;
    while (age>=2017){
        cout << "You entered a year in the future.\n";
        cout << "Enter your birth year: ";
        cin >> age;}
    cout << "You entered: " << age;
    return 0;
}
