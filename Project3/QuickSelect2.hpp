#ifndef QUICKSELECT2_HPP
#define QUICKSELECT2_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

void quickSelect2(const std::string & header, std::vector<int> data);

//Helper function (this is what does all the sorting/partitioning)
void insertionSort(std::vector<int>& data, int low, int high);
int partition(std::vector<int>& data, int low, int high);
int quickSelect(std::vector<int>& data, int low, int high, const std::vector<int>& keys);
#endif