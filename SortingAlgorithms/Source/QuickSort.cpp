#include "QuickSort.h"

QuickSort::QuickSort()
{

}

QuickSort::~QuickSort()
{
    
}

bool QuickSort::ExecuteSort(std::vector<int>& a_List, int a_Left, int a_Right, ListMap& a_Map)
{
    if (a_List.empty())
    {
        return false;
    }

    if (a_Left < a_Right)
    {
        int pivot = Partition(a_List, a_Left, a_Right, a_Map);

        ExecuteSort(a_List, a_Left, pivot - 1, a_Map); //Left
        ExecuteSort(a_List, pivot + 1, a_Right, a_Map); //Right
    }

    return true;
}

//Partitions the vector with lower values on the left and higher on the right, with the pivot in the middle
int QuickSort::Partition(std::vector<int>& a_List, int a_Left, int a_Right, ListMap& a_Map)
{
    int pivot = a_List[a_Right];

    //Left side index, starting at -1
    int i = (a_Left - 1);

    for (int j = a_Left; j <= a_Right - 1; j++)
    {
        if (a_List[j] < pivot)
        {
            i++;
            std::swap(a_List[i], a_List[j]);
        }
    }

    std::swap(a_List[i + 1], a_List[a_Right]);
    a_Map.UpdateQuads(a_List);
    return (i + 1);
}
