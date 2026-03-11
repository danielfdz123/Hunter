#include "myVector.hpp"

void vectorMedian(const std::vector<int>* instructions) 
{
    //This will time the program and see how long it'll take to finish
    const auto t1_start = std::chrono::steady_clock::now();

    // //Helping variables 
    // auto median;
    // auto L_bound;

    //New vectors; Nums is a COPY of the original vector with all the 
    std::vector<int> nums;
    std::vector<int> medianVect; 

    //This will iterate through the instructions vector and pop the median when necessary
    for(auto it = instructions->begin(); it < instructions->end(); it++) 
    {
        //Checks the vector for if we see a -1, which means we will pop the median
        if(*it == -1)
        {
            //If the size is even...
            if(nums.size() % 2 == 0)
            {
                //Median is the ith index, which is 1 less than half of the size. 
                //Here, whatever value that is will be pushed into the medianVect for output
                //Median value will be removed from the base vector 
                auto median = (nums.begin() + nums.size() / 2 - 1);
                medianVect.push_back(*median);
                nums.erase(median);
            }
            //If the size of the vecotr is odd...
            else if(nums.size() % 2 != 0)
            {
                //Median is the ith index, which is whatever half the size is
                //Here, whatever the value is will be pushed into the medianVect for output
                //Median value will be removed from the base vector
                auto median = (nums.begin() + nums.size() / 2);
                medianVect.push_back(*median);
                nums.erase(median);
            }
        }
        //This sorts the vector to maintain its order
        else
        {
            auto L_bound = lower_bound(nums.begin(), nums.end(), *it);
            nums.insert(L_bound, *it);
        }
    }

    //Prints out any median from the medianVect
    for(int i = 0; i < medianVect.size(); i++)
    {
        std::cout << medianVect[i] << " ";
    }

    //Stops the timing and will print however long it takes to run this algorithm
    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
    std::cout << "\n\nThis program's runtime: " << t1 << " microseconds." << std::endl;
}

