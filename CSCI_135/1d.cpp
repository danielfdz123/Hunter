//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//August 25, 2022
//Prints how many days a month has based on the input, which is month, and leap/common year

#include <iostream>
using namespace std;
int main()
{

int year, month;
cout << "Enter year: ";
cin >> year;
cout << "Enter month: "; 
cin >> month;
    
if (month == 2){
    if (year % 4 != 0){
        cout << "28 days";
        }
    else if (year % 100 != 0){
        cout << "29 Days";
        }
    else if (year % 400 != 0){
            cout << "28 Days";
        }
    else {
        cout << "29 days";
        }
    }     
else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
    cout<< "31 Days";
}
else {
    cout << "30 Days";
}
    return 0;
}
