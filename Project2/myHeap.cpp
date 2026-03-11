#include "myHeap.hpp"

void heapMedian(const std::vector<int>* instructions) 
{
    // This will time the program and see how long it'll take to finish
    const auto t1_start = std::chrono::steady_clock::now();

    //Create a min/max heap
    //maxHeap will hold all values greater than the median
    //minHeap will hold all values less than the median
    std::priority_queue<int> maxHeap; 
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::vector<int> medianVect;

    //Helper Variables
    int maxMedian;
    int minMedian;

    // This will iterate through the instructions vector and pop the median when necessary
    for(auto it = instructions->begin(); it != instructions->end(); ++it) 
    {
        //If we come across a -1 we POP
        if (*it == -1) 
        {
            //Checks if heaps are NOT empty
            if(!maxHeap.empty() || !minHeap.empty()) 
            {
                //Top values of both heaps are the median, 
                maxMedian = maxHeap.top(); 
                minMedian = minHeap.top();
                //Lowest median from the two are pushed into the vector (medianVect)
                medianVect.push_back(std::min(maxMedian, minMedian)); 
                //Pops median so we can move onto the next run through
                maxHeap.pop(); 
                
                //Rebalance the heaps if necessary
                if (maxHeap.size() > minHeap.size() + 1) 
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                } 
                else if (minHeap.size() > maxHeap.size()) 
                {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }
        }
        else
        {
            //Pushes value into maxHeap if these conditions are satisfied
            if(maxHeap.empty() || *it <= maxHeap.top())
            {  
                maxHeap.push(*it); 
            } 
            //Pushes value into minHeap if these conditions are satisfied
            else 
            { 
                minHeap.push(*it);
            }

            //Rebalance the heaps if necessary (again)
            if (maxHeap.size() > minHeap.size() + 1) 
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } 
            else if (minHeap.size() > maxHeap.size()) 
            {
                maxHeap.push(minHeap.top());                    
                minHeap.pop();
            }
        }
    }

    //Will loop through medianVect and print out the medians
    for (int i = 0; i < medianVect.size(); i++) 
    {
        std::cout << medianVect[i] << " ";
    }
        
    //Stops the timing of how long it'll take to run this algorithm
    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration <double, std::micro>(t1_end - t1_start).count();
    std::cout << "\nThis program's runtime: " << t1 << " microseconds." << std::endl;
}
