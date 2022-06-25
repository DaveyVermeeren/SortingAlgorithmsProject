#include "Graphics.h"

Graphics* Graph;

Graphics::Graphics(std::vector<int>& a_List, int Max, Algorithms choice)
{
    MapList = new ListMap(a_List, Max);

    Sorted = false;
    Sorting = false;
    Finished = false;
    timer = 0;
    Choice = choice;
    Left = 0;
    Right = a_List.size() - 1;

    switch (Choice)
    {
    case Bubble:
        SortBubble = new BubbleSort();
        break;
    case Quick:
        SortQuick = new QuickSort();
        break;
    case Merge:
        SortMerge = new MergeSort();
        break;
    case Heap:
        SortHeap = new HeapSort();
        break;
    case Insertion:
        SortInsertion = new InsertionSort();
        break;
    }
}

Graphics::~Graphics()
{
    
}

void Graphics::Render()
{
    for (auto CurImage : MapList->quads)
    {
        S2D_DrawImage(CurImage.Image);
    }
}

void Graphics::Update(std::vector<int>& a_List)
{
    if (!Sorted && timer >= 500)
    {
        switch (Choice)
        {
        case Bubble:
            SortBubble->ExecuteSort(a_List, *MapList);
            break;
        case Quick:
            Sorted = SortQuick->ExecuteSort(a_List, Left, Right, *MapList);
            break;
        case Merge:
            Sorted = SortMerge->ExecuteSort(a_List, Left, Right, *MapList);
            break;
        case Heap:
            SortHeap->ExecuteSort(a_List, *MapList);
            break;
        case Insertion:
            SortInsertion->ExecuteSort(a_List, *MapList);
            break;
        }
    }
    //else if (Sorted && !Finished)
    //{
    //    MapList->FinishQuads(a_List);
    //    Finished = true;
    //}

    timer++;

}

