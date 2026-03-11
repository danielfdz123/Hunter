//Daniel Andres Fernandez
//daniel.fernandez16@Myhunter.cuny.edu
//December 12, 2022
//Lab 12D

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(const vector<int> &v1, vector<int> &v2)
{
    vector<int>sum;
    int a = v1.size();
    int b = v2.size();
    
    int num;
    
    //Sees which vector has the largest size
    if(a > b)
    {
        num = a;
    }
    else 
    {
        num = 2;
    }
    
    //Adds the two vectors corresponding elements
    for(int i = 0; i < num; i++)
    {
        sum.push_back(v1[i] + v2[i]);
    }
    return sum;
}

int main() 
{
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};
    
    vector<int> vect = sumPairWise(v1, v2);    
    for(int i = 0; i < 3; i++)
    {
        cout << vect[i] << " ";
    }
}
