//Daniel Andres Fernandez
//daniel.fernandez16@Myhunter.cuny.edu
//December 12, 2022
//Lab 12A

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
    }
    return v;
}

int main() 
{
    int num = 15;
    vector <int> v = (makeVector(num));
    for(int i = 0; i < num; i++)
    {
        cout << v[i] << " ";
        
    }
}
