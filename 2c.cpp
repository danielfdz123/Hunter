//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//September 9, 2022
//This program prompts the user to edit an array

#include <iostream>
using namespace std;
int main ()
{
    //Print array
    int arr[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl << endl;
    
    //Gets x and y
    int x, y;			 
    cout << "Enter array index: ";
    cin >> x;
    cout << "Enter new value: ";
    cin >> y;
    
    //If x is good, update array
    if (0 <= x && x <= 9)
    {
        arr[x] = y;
        for (int i = 0; i < 10; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl << endl;
    }
    
    //If index was good, repeat  
    while (0 <= x && x <= 9)
    {
        cout << "Enter array index: ";
        cin >> x;
        cout << "Enter new value: ";
        cin >> y;
        
        if (0 <= x && x <= 9)
        {
            arr[x] = y;
            for (int i = 0; i < 10; i++)
    	    {
    	        cout << arr[i] << "  ";
    	    }
    	    cout << endl << endl;;
        }
    }
    cout << "\nIndex out of range. Exit";
    return 0;
}
