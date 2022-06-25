#include "BubbleSort.h"

BubbleSort::BubbleSort()
{
    m_Checks = 0;
    m_Element = 0;
}

BubbleSort::~BubbleSort()
{
    
}

bool BubbleSort::ExecuteSort(std::vector<int>& a_List, ListMap& a_MapList)
{
    if (a_List.empty())
    {
        printf("The list is empty\n");
        return false;
    }

    unsigned int NextValue = 0;
    bool Swapped = false;
    unsigned int MaxValue = a_List.size();

    if (m_Element < a_List.size())
    {
        Swapped = false;
        for (unsigned int val = 0; val < a_List.size(); val++)
        {
            NextValue += 1;
            if (MaxValue <= NextValue)
            {
                continue;
            }

            if (a_List[val] > a_List[NextValue])
            {
                std::swap(a_List[val], a_List[NextValue]);
                m_Checks += 1;
                Swapped = true;
            }
            else
            {
                m_Checks += 1;
                continue;
            }

        }

        a_MapList.UpdateQuads(a_List);

        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));

        if (!Swapped)
        {
            return true;
        }

        MaxValue -= 1;
        NextValue = 0;
        m_Element++;
    }

    return true;
}
