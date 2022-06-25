#pragma once
#include <vector>
#include <string>
#include "ListMap.h"

//TODO: Make iterative version for visual representation

class MergeSort
{
public:
    MergeSort();
    ~MergeSort();

    bool ExecuteSort(std::vector<int>& a_List, int a_Left, int a_Right, ListMap& a_Map);
    bool Merge(std::vector<int>& a_List, int a_Left, int a_Middle, int a_Right, ListMap& a_Map);

private:
};