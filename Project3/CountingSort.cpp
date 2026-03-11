#include "CountingSort.hpp"

void countingSort(const std::string & header, std::vector<int> data)
{
    // Start clock    
    // const auto t1_start = std::chrono::steady_clock::now();

    //Helper variable(s)
    int median, q1, q3;
    
    //Initiates hashMap where 2 ints make a pair
    //1st int: the values from the vector
    //2nd int: the number of occurances (hash value)
    std::unordered_map<int, int> hashMap;

    //For values in the data vector...
    for (int value : data)
    {
        //Check if the value is already in the hashMap
        if(hashMap.find(value) != hashMap.end())
        {
            //Increase increment if value is already in hashMap
            hashMap[value]++;
        }
        else
        {
            //Otherwise, set counter to 1 (used for newly discovered values)
            hashMap[value] = 1;
        }
    }

    //NOW WE SHALL PUSH THESE UNIQUE PAIRS INTO A VECTOR RAHHHHHHH

    //Declares vector
    std::vector<std::pair<int, int>> vectorPairs;

    //Loops through hashMap and pushes the vectorPairs into the vector
    for(const auto &vectPairs : hashMap)
    {
        //Pushes the value from the vector however many times the pair value is (# of occurrences)
        for(int i = 0; i < vectPairs.second; i++)
        {
            vectorPairs.push_back(vectPairs);
        }
    }    

    //Sorting yippie :)
    std::sort(vectorPairs.begin(), vectorPairs.end());

    //Find median (cases for both even/odd sizes)
    if(vectorPairs.size() % 2 == 0)
    {
        median = vectorPairs[vectorPairs.size()/2 -1].first;
    }
    else
    {
        median = vectorPairs[vectorPairs.size()/ 2].first;
    }

    //Find q1 (cases for both even/odd sizes)
    if(vectorPairs.size() % 2 == 0)
    {
        q1 = vectorPairs[vectorPairs.size()/4 -1].first;
    }
    else
    {
        q1 = vectorPairs[vectorPairs.size()/4].first;
    }

    //Find q3 (cases for both even/odd sizes)
    if(vectorPairs.size() % 2 == 0)
    {
        q3 = vectorPairs[0.75 * (vectorPairs.size() - 1)].first;
    }
    else
    {
        q3 = vectorPairs[0.75 * (vectorPairs.size())].first;
    }

    //Print the number of unique values
    std::cout << header << std::endl;
    std::cout << "Min: " << vectorPairs[0].first << std::endl;
    std::cout << "P25: " << q1 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << q3 << std::endl;
    std::cout << "Max: " << vectorPairs.back().first << std::endl;
    std::cout << "Unique: " << hashMap.size() << std::endl;

    // //Stops the timing and will output how long it'll take to run this algorithm
    // const auto t1_end = std::chrono::steady_clock::now();
    // int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();
    // std::cout << "\nThis program's runtime: " << t1 << " microseconds" << std::endl;

}
