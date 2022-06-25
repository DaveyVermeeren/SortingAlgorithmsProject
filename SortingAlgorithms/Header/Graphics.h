#pragma once
#include "ListMap.h"
#include "AlgorithmsStruct.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"

struct Vector2Int
{
    float x;
    float y;
};

class Graphics
{
public:
    Graphics(std::vector<int>& a_List, int Max, Algorithms choice);
    ~Graphics();
    void Render();
    void Update(std::vector<int>& a_List);

    S2D_Window* window;

private:
    bool Sorted;
    bool Sorting;
    bool Finished;
    int Left;
    int Right;
    int timer;
    ListMap* MapList;
    Algorithms Choice;
    BubbleSort* SortBubble;
    QuickSort* SortQuick;
    MergeSort* SortMerge;
    HeapSort* SortHeap;
    InsertionSort* SortInsertion;
};

extern Graphics* Graph;
