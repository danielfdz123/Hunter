//Daniel Andres Fernandez
//daniel.fernandez16@Myhunter.cuny.edu
//December 12, 2022
//Lab 12B

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(vector<int> v)
{
    vector<int> vect;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] >= 0)
        {
            vect.push_back(v[i]);
        }
    }
    return vect;
}

int main() 
{
    vector<int> v{1,2,-1,3,4,5,-1,6};
    vector <int> v1 = goodVibes(v);
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
}
    
