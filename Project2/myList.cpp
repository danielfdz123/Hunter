#include "myList.hpp"

void listMedian(const std::vector<int>* instructions) 
{
    //This will time the program and see how long it'll take to finish
    const auto t1_start = std::chrono::steady_clock::now();

    //New vectors; Nums is a COPY of the original vector with all the 
    std::list<int> nums;
    std::list<int> medianList;

    //This will iterate through the instructions list and pop the median when necessary
    for (auto it = instructions->begin(); it != instructions->end(); it++) 
    {
        if (*it == -1) 
        {
            if (nums.size() % 2 == 0) 
            {
                //Median is the ith index, which is 1 less than half of the size. 
                //Here, whatever value that is will be pushed into the medianList for output
                //Median value will be removed from the base vector 
                auto median = std::next(nums.begin(), nums.size() / 2 - 1);
                medianList.push_back(*median);
                nums.erase(median);
            }
            else 
            {
                //Median is the ith index, which is whatever half the size is
                //Here, whatever the value is will be pushed into the medianList for output
                //Median value will be removed from the base vector
                auto median = std::next(nums.begin(), nums.size() / 2);
                medianList.push_back(*median);
                nums.erase(median);
            }
        }
        //This sorts the list so that all the elements are in order
        else 
        {
            auto L_bound = std::lower_bound(nums.begin(), nums.end(), *it);
            nums.insert(L_bound, *it);
        }
    }

    //Will loop through the medianList and will print out values from the list
    for (auto it = medianList.begin(); it != medianList.end(); ++it) 
    {
        std::cout << *it << " ";
    }

    //Stops the timing and will output how long it'll take to run this algorithm
    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration <double, std::micro>(t1_end - t1_start).count();
    std::cout << "\nThis program's runtime: " << t1 << " microseconds." << std::endl;
}