// Daniel Andres Fernandez
// danitl.fernandez16@myhunter.cuny.edu
// October 28, 2022
// Lab 10a

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Time
{
public:
    int h;
    int m;
};

int minutesSinceMidnight(Time time)
{
    int final = 0;
    final += time.m;
    final += time.h * 60;
    return final;
}

int minutesUntil(Time earlier, Time later)
{
    int total = 0;
    total += later.m - earlier.m;
    total += (later.h - earlier.h) * 60;
    return total;
}

int main()
{
    Time time1, time2;
    cout << "Enter the following using 24-hour time, and with the following format. (Ex: '10 30' represents 10:30)\n";
    cout << "Enter first time: ";
    cin >> time1.h >> time1.m;
    cout << "Enter second time: ";
    cin >> time2.h >> time2.m;
    int difference = minutesUntil(time1, time2);
    int min1 = minutesSinceMidnight(time1);
    int min2 = minutesSinceMidnight(time2);
    cout << "These moments of time are " << min1 << " and " << min2 << " minutes after midnight." << endl
         << "The interval between them is " << difference << " minutes.";
}
