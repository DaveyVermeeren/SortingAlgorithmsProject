#include "HeapSort.h"

HeapSort::HeapSort()
{
    
}

HeapSort::~HeapSort()
{
    
}

bool HeapSort::ExecuteSort(std::vector<int>& a_List, ListMap& a_MapList)
{
    if (a_List.empty())
    {
        return false;
    }

    //Create the Heap
    for (int i = a_List.size() / 2 - 1; i >= 0; i--)
    {
        Heapify(a_List, a_List.size(),i, a_MapList);
    }

    for (int i = a_List.size() - 1; i > 0; i--)
    {
        std::swap(a_List[0], a_List[i]);

        Heapify(a_List, i, 0, a_MapList);
    }

    a_MapList.UpdateQuads(a_List);
    return true;
}

void HeapSort::Heapify(std::vector<int>& a_List, int a_Size, unsigned int a_Index, ListMap& a_MapList)
{
    //In order to find the child nodes of a specific index, we use 2 * index + 1 or 2 if it is left or right respectively
    unsigned int Largest = a_Index;
    unsigned int Left = 2 * a_Index + 1;
    unsigned int Right = 2 * a_Index + 2;

    if (Left < a_Size && a_List[Left] > a_List[Largest])
    {
        Largest = Left;
    }

    if (Right < a_Size && a_List[Right] > a_List[Largest])
    {
        Largest = Right;
    }

    if (Largest != a_Index)
    {
        std::swap(a_List[a_Index], a_List[Largest]);

        Heapify(a_List, a_Size, Largest, a_MapList);
    }
}
