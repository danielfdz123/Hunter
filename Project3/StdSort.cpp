#include "StdSort.hpp"

void stdSort (const std::string & header, std::vector<int> data)
{
    //Start clock
    // const auto t1_start = std::chrono::steady_clock::now();

    //Using std::sort to sort everything from beginning to end (duh)
    std::sort(data.begin(), data.end());

    //Helper variables
    int median;
    int q1;
    int q3;

    //Finds median of the vector (starting off if its an even size or not)
    if (data.size() % 2 == 0) 
    {
        median = data[(data.size()/2 - 1)];
    } 
    else 
    {
        median = data[data.size()/2];
    }

    //Finds P25 (25th percentile)
    if(data.size() % 2 == 0)
    {
        q1 = data[data.size()/4 -1];
    }
    else
    {
        q1 = data[data.size()/4];
    }

    //Find P75 (75th percentile)
    q3 = data[0.75 * (data.size() - 1)];

    //Print the sorted vector
    std::cout << header << std::endl;
    std::cout << "Min: " << data[0] << std::endl;
    std::cout << "P25: " << q1 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << q3 << std::endl;
    std::cout << "Max: " << data.back() << std::endl;

    // //Print all values
    // for(int i = 0; i < data.size(); i++) 
    // {
    //     std::cout << data[i] << " ";
    // }

    // //Stops the timing and will output how long it'll take to run this algorithm
    // const auto t1_end = std::chrono::steady_clock::now();
    // int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();
    // std::cout << "\nThis program's runtime: " << t1 << " microseconds" << std::endl;

}