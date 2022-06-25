#pragma once
#include <simple2d.h>
#include <vector>
#include <string>
#undef main

constexpr int HEIGHT = 600;
constexpr int WIDTH = 800;
constexpr int HalfHeight = HEIGHT / 2;
constexpr int HalfWidth = WIDTH / 2;

struct ImageTile
{
    S2D_Image* Image;
    int Value;
};

class ListMap
{
public:
    ListMap(std::vector<int>& a_List, int Max);
    ~ListMap();

    void UpdateQuads(std::vector<int>& a_List);
    void FinishQuads(std::vector<int>& a_List);
    void ReplaceImage(std::string Filename, int Index, int Value);

    std::vector<ImageTile> quads;

private:
    int MaxValue;
    float StartPos;
    float AvailableLength;
    float QuadWidth;
    float QuadSpace;
    float AvailableHeight;
};