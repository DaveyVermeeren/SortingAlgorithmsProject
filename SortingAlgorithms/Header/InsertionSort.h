#pragma once
#include <vector>
#include <string>
#include "ListMap.h"

class InsertionSort
{
public:
    InsertionSort();
    ~InsertionSort();

    bool ExecuteSort(std::vector<int>& a_List, ListMap& a_MapList);

private:
};