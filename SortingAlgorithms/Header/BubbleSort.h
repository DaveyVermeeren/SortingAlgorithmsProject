#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "ListMap.h"

class BubbleSort
{
public:
    BubbleSort();
    ~BubbleSort();

    bool ExecuteSort(std::vector<int>& a_List, ListMap& a_MapList);

private:
    int m_Checks;
    int m_Element;
};
