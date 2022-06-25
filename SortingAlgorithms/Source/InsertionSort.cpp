#include "InsertionSort.h"

InsertionSort::InsertionSort()
{

}

InsertionSort::~InsertionSort()
{
    
}

bool InsertionSort::ExecuteSort(std::vector<int>& a_List, ListMap& a_MapList)
{
    if (a_List.empty())
    {
        return false;
    }

    int previous = 0;
    int current = 0;

    for (int i = 1; i < a_List.size(); i++)
    {
        current = a_List[i];
        previous = i - 1;

        while (previous >= 0 && a_List[previous] > current)
        {
            std::swap(a_List[previous + 1], a_List[previous]);
            previous = previous - 1;
        }
        a_List[previous + 1] = current;
    }

    a_MapList.UpdateQuads(a_List);

    return true;
}

