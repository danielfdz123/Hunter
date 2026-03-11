#ifndef QUICKSELECT1_HPP
#define QUICKSELECT1_HPP
#include <iostream>
#include <vector>
#include <chrono>

//The function Justin wants
void quickSelect1(const std::string & header, std::vector<int> data);

//Helper function (this is what does all the sorting/partitioning)
void insertionSort(std::vector<int>& data, int low, int high);
int partition(std::vector<int>& data, int low, int high);
int quickSelect(std::vector<int>& data, int low, int high, int k);
#endif