#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include "myAVLtree.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

//Ignore this, I just wanted to output the base file as a whole
// int main () 
// {   
//     std::ifstream file("testinput.txt");
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
// }


int main() 
{
    //The extra variables i needed for this
    std::string line;
    int num;

    //Reads in the file & initialize an empty vector
    std::ifstream file("input3.txt");
    std::vector<int> vector;

    //Simply checks if the file is readable or not. If it isn't, then an error message is displayed
    if(file.fail()) 
    {
        std::cout << "Error! Womp, womp." << std::endl;
        return 1;
    }

    //Will loop through the whole input file and start taking anything after an INSERT and taking its integer form
    //Will also grab any POP MEAN and will change it to a -1 
    while (std::getline(file, line)) 
    {
        std::istringstream temp(line);
        std::string string;
        temp >> string;

    //Responsible for any number that comes after INSERT, pushing the interger into the vector
        if(string == "insert") 
        {
            if(temp >> num)
            {
            vector.push_back(num);
            }
        } 
    //Responsible for the POP MEAN, basically changing those strings to a -1 and pushing it into the vector
        else if(string == "pop") 
        {
            vector.push_back(-1);
        } 
    }
    file.close();

    //VECTOR LOOP FOR TESTING INPUT FILE :)
    // for (int i = 0; i < vector.size(); i++)
    // {
    //     std::cout << vector[i] << " ";
    // }

    // //Testing the functions with their respective files
    // vectorMedian(&vector);
    // listMedian(&vector);
    // heapMedian(&vector);
    treeMedian(&vector);
    return 0;
};