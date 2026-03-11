#include "QuickSelect2.hpp"

//Insertion Sort implementation
void insertionSort(std::vector<int>& data, int low, int high)
{
    //Will loop through the vector and start sorting
    for (int i = low + 1; i <= high; i++) 
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
        //Will swap terms i and j if the jth index <= pivot
        if (data[j] <= pivot) 
        {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);
    return i + 1;
}

//QuickSelect function that performs the quickSelect
int quickSelect(std::vector<int>& data, int low, int high, const std::vector<int>& keys) 
{
    //Helper variables
    int pivot;

    //Checking if parameters make sense. We cant partition if the higher value is less than the smaller one
    if (low <= high) 
    {
        //If the vector size is 20 or less, call insertionSort (as wanted by project specs)
        if (high - low + 1 <= 20) 
        {
            insertionSort(data, low, high);
            return data[keys[0]];
        }
        //Pivot will be whatever the partition function returns
        pivot = partition(data, low, high);

        //We return the 1st term of the keys vector if its the same as the pivot
        if (pivot == keys[0]) 
        {
            return data[keys[0]];
        } 
        //Call quickSelect if the 1st term in the keys vector is greater than the pivot
        else if (pivot < keys[0]) 
        {
            return quickSelect(data, pivot + 1, high, keys);
        } 
        //Call quickSelect if the 1st term of the keys vector is less than the pivot 
        else 
        {
            return quickSelect(data, low, pivot - 1, keys);
        }
    }
    //Return -1 if error happens
    return -1;
}

void quickSelect2(const std::string & header, std::vector<int> data)
{
    // //Start clock    
    // const auto t1_start = std::chrono::steady_clock::now();

    //Helper variables
    //The vect variables are what will be passed in as the keys, which are a list of keys instead of 1
    int median, medianVect;
    int q1, q1Vect;
    int q3, q3Vect;
    int min, minVect;
    int max, maxVect;

    //FIND MEDIAN (for both cases if size is even/odd)
    if(data.size() % 2 == 0)
    {
        medianVect = data.size()/2 -1;
    }
    else
    {
        medianVect = data.size()/2;
    }
    median = quickSelect(data, 0, data.size() - 1, {medianVect});

    //FIND Q1 (for both cases if size is even/odd)
    if(data.size() % 2 == 0)
    {
        q1Vect = (data.size()/4 -1);
    }
    else
    {
        q1Vect = data.size()/4;
    }
    q1 = quickSelect(data, 0, data.size() - 1, {q1Vect});

    //FIND Q3
    q3Vect = 3* (data.size()/4)-1;
    q3 = quickSelect(data, 0, data.size() - 1, {q3Vect});

    //FIND MIN
    min = quickSelect(data, 0, data.size(), {0});

    //FIND MAX
    maxVect = data.size() -1;
    max = quickSelect(data, 0, data.size()-1, {maxVect});

    //Now we shall print out the infomration :D
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
