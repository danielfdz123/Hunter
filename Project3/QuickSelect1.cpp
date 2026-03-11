#include "QuickSelect1.hpp"

//Insertion Sort implementation
void insertionSort(std::vector<int>& data, int low, int high)
{
    //Will loop through the vector and start sorting 
    for(int i = low + 1; i <= high; i++) 
    {
        int key = data[i];
        int j = i - 1;
        while (j >= low && data[j] > key) 
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

//Partition function needed for QuickSelect
int partition(std::vector<int>& data, int low, int high) 
{
    //Pivot will be the index of whatever the high value is
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        //Will sawp terms i and j if the jth index <= pivot
        if (data[j] <= pivot) 
        {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);
    return i + 1;
}

//QuickSelect function that... performs the quickSelect duh XD
int quickSelect(std::vector<int>& data, int low, int high, int k) 
{
    //Helper variables
    int pivot;

    //Checking if parameters make sense. We cant partition if the higher value is less than the smaller one
    if (low <= high) 
    {
        //If the vector size is 20 or less, insertions sort will be called (as wanted in project specs)
        if (high - low + 1 <= 20) 
        {
            insertionSort(data, low, high);
            return data[k];
        }
        //Return value from the partition function becomes the new pivot 
        pivot = partition(data, low, high);

        //If the pivot is the same as the key, we just return that
        if(pivot == k) 
        {
            return data[k];
        } 
        //Call quickSelect if key is greater than pivot & returns its value
        else if(pivot < k) 
        {
            return quickSelect(data, pivot + 1, high, k);
        } 
        //Call quickSelect if key is less than the pivot
        else 
        {
            return quickSelect(data, low, pivot - 1, k);
        }
    }
    //Return -1 if error happens since we cant partition a
    return -1;
}

void quickSelect1(const std::string & header, std::vector<int> data)
{
    // //Start clock    
    // const auto t1_start = std::chrono::steady_clock::now();

    //Helper variables
    int median, medianPivot;
    int q1, q1pivot;
    int q3, q3pivot;

    //FIND MEDIAN (for both cases if size is even/odd)
    if(data.size() % 2 == 0)
    {
        medianPivot = data.size()/2 -1;
    }
    else
    {
        medianPivot = data.size()/2;
    }
    //Calls quickSelect to find the median
    median = quickSelect(data, 0, data.size() - 1, medianPivot);

    //FIND Q1 (for both cases is the size is even/odd)
    if(data.size() % 2 == 0)
    {
        q1pivot = data.size()/4 -1;
    }
    else
    {
        q1pivot = data.size()/4;
    }
    //Calls quickSelect to find the q1 (25th percentile)
    q1 = quickSelect(data, 0, data.size() - 1,q1pivot);

    //FIND Q3 (75th percentile) pivot and calls quickSE=elect to find the proper value
    q3pivot = 3* (data.size()/4)-1;
    q3 = quickSelect(data, 0, data.size(), q3pivot);

    //FIND MIN (search for the minimum only before the 25% mark)
    int min = data[0];
    for (int i = 1; i < data.size() / 4; i++) 
    {
        //Values are compared to the min, will constantly update when a new min is found
        min = std::min(min, data[i]);
    }

    //FIND MAX (search for maximum after the 75% mark)
    int max = data[data.size() - 1];
    for (int i = 3 * (data.size()/4) + 1; i < data.size(); i++) 
    {
        //Values are compared to the max. Will constantly update when a new max is found
        max = std::max(max, data[i]);
    }

    //Printing the infomration
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << q1 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << q3 << std::endl;
    std::cout << "Max: " << max << std::endl;

    // //Stops the timing and will output how long it'll take to run this algorithm
    // const auto t1_end = std::chrono::steady_clock::now();
    // int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();
    // std::cout << "\nThis program's runtime: " << t1 << " microseconds" << std::endl;

}