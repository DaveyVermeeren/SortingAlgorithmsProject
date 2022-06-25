#include "ListMap.h"

ListMap::ListMap(std::vector<int>& a_List, int Max)
{
    MaxValue = Max;
    StartPos = 5.f;
    AvailableLength = (WIDTH - StartPos) / a_List.size();
    QuadWidth = 0.9f * AvailableLength;
    QuadSpace = AvailableLength - QuadWidth;
    AvailableHeight = (HalfHeight - 5) / MaxValue;

    for (unsigned int i = 0; i < a_List.size(); i++)
    {
        S2D_Image* Temp;
        Temp = S2D_CreateImage("Resources/Red.png");
        Temp->x = static_cast<int>(StartPos + i * QuadWidth + i * QuadSpace);
        Temp->y = HalfHeight + HalfHeight / 2;
        Temp->width = QuadWidth;
        Temp->height = a_List[i] * AvailableHeight;
        S2D_RotateImage(Temp, 180.f, S2D_TOP_LEFT);

        quads.push_back({ Temp, a_List[i] });
    }
}

ListMap::~ListMap()
{
    
}

void ListMap::ReplaceImage(std::string Filename, int Index, int Value)
{
    S2D_Image* Temp = S2D_CreateImage(Filename.c_str());
    S2D_Image* Old = quads[Index].Image;
    Temp->x = Old->x;
    Temp->y = Old->y;
    Temp->width = Old->width;
    Temp->height = Value * AvailableHeight;
    S2D_RotateImage(Temp, 180.f, S2D_TOP_LEFT);
    S2D_FreeImage(quads[Index].Image);
    quads[Index] = { Temp, Value };
}

void ListMap::UpdateQuads(std::vector<int>& a_List)
{
    for (unsigned int i = 0; i < a_List.size(); i++)
    {
        ReplaceImage("Resources/Red.png", i, a_List[i]);
    }
}

void ListMap::FinishQuads(std::vector<int>& a_List)
{
    for (unsigned int i = 0; i < a_List.size(); i++)
    {
        ReplaceImage("Resources/Green.png", i, a_List[i]);
    }
}