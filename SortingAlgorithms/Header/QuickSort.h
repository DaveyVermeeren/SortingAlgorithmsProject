#pragma once
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include "ListMap.h"

//TODO: Make iterative version for visual representation

class QuickSort
{
public:
    QuickSort();
    ~QuickSort();
    
    //Takes the last element as the pivot
    bool ExecuteSort(std::vector<int>& a_List, int a_Left, int a_Right, ListMap& a_Map);
    int Partition(std::vector<int>& a_List, int a_Left, int a_Right, ListMap& a_Map);

private:
};
