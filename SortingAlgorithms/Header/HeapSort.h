#pragma once
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include "ListMap.h"

class HeapSort
{
public:
    HeapSort();
    ~HeapSort();

    bool ExecuteSort(std::vector<int>& a_List, ListMap& a_MapList);
    void Heapify(std::vector<int>& a_List, int a_Size ,unsigned int a_Index, ListMap& a_MapList);

private:
};