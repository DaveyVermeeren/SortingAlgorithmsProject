#include "MergeSort.h"

MergeSort::MergeSort()
{
    
}

MergeSort::~MergeSort()
{
    
}

bool MergeSort::ExecuteSort(std::vector<int>& a_List, int a_Left, int a_Right, ListMap& a_Map)
{
    if (a_List.empty())
    {
        return false;
    }

    if (a_Left >= a_Right)
    {
        return false;
    }

    int middle = (a_Left + (a_Right - 1)) / 2;
    ExecuteSort(a_List, a_Left, middle, a_Map);
    ExecuteSort(a_List, middle + 1, a_Right, a_Map);
    return Merge(a_List, a_Left, middle, a_Right, a_Map);
}

bool MergeSort::Merge(std::vector<int>& a_List, int a_Left, int a_Middle, int a_Right, ListMap& a_Map)
{
    int LeftSize = a_Middle - a_Left + 1;
    int RightSize = a_Right - a_Middle;

    std::vector<int> LeftArray;
    std::vector<int> RightArray;

    //Split up the two sides in temporary arrays
    for (int i = 0; i < LeftSize; i++)
    {
        LeftArray.push_back(a_List[a_Left + i]);
    }

    for (int j = 0; j < RightSize; j++)
    {
        RightArray.push_back(a_List[a_Middle + 1 + j]);
    }

    //Sort and merge the two arrays
    int LeftIndex = 0;
    int RightIndex = 0;
    int MergeIndex = a_Left;

    while (LeftIndex < LeftSize && RightIndex < RightSize)
    {
        if (LeftArray[LeftIndex] <= RightArray[RightIndex])
        {
            a_List[MergeIndex] = LeftArray[LeftIndex];
            LeftIndex++;
        }
        else
        {
            a_List[MergeIndex] = RightArray[RightIndex];
            RightIndex++;
        }

        MergeIndex++;
    }

    //Get rid of any remaining elements
    while (LeftIndex < LeftSize)
    {
        a_List[MergeIndex] = LeftArray[LeftIndex];
        LeftIndex++;
        MergeIndex++;
    }

    while (RightIndex < RightSize)
    {
        a_List[MergeIndex] = RightArray[RightIndex];
        RightIndex++;
        MergeIndex++;
    }

    a_Map.UpdateQuads(a_List);
    return true;
}
