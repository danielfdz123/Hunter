#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

#include <algorithm>
#include <unordered_map>

// //Ignore this, I just wanted to output the base file as a whole
// int main () 
// {   
//     std::ifstream file("test_input1.txt");
//     if(!file.is_open())
//     {
//         std::cout << "Error, can not open file.";
//         return 1;
//     } 
//     char characters;
//     while(file)
//     {
//         characters = file.get();
//         std::cout << characters;
//     }
//     return 0;
// }

int main() 
{
    //Helper variables
    std::vector<int> vector;
    int num;

    //Reads in file & initializes vector
    std::ifstream file("test_input1.txt");

    // Checks if file is readable or not
    if (!file.is_open()) 
    {
        std::cout << "Check your file silly because this isn't working";
        return 1;
    }

    //Skips the first line, which holds the little header at the start of the file
    std::string line;
    while (std::getline(file, line)) 
    {
        std::istringstream temp(line);
        // Pushes elements into the vector
        while(temp >> num) 
        {
            vector.push_back(num);
        }
    }
    file.close();

    // //Testing the vector to see if the push_backs were done properly
    // for (int i = 0; i < vector.size(); i++) 
    // {
    //     std::cout << vector[i] << " ";
    // }

    stdSort("Male elephant seal weights", vector);
    // quickSelect1("Male elephants seal weights", vector);
    // quickSelect2("Male elephants seal weights", vector);
    // countingSort("Male elephants seal weights", vector);
    return 0;
}