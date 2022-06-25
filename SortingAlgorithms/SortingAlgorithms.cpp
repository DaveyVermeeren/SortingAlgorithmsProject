#include <stdlib.h>
#include <iostream>
#include "RNG.h"
#include "Graphics.h"

std::vector<int> List;

void render()
{
    Graph->Render();
}

void update()
{
    Graph->Update(List);
}

int main()
{
    Algorithms Choice = Bubble;
    RNG Generator;
    int Size = 100;
    int Min = 1;
    int Max = 100;

    for (int i = 0; i < Size; i++)
    {
        int value = Generator.GenerateInt(Min, Max);
        List.push_back(value);
    }

    Graph = new Graphics(List, Max, Choice);

    Graph->window = S2D_CreateWindow(
        "Sorting Algorithm",
        WIDTH, HEIGHT,
        update, render,
        S2D_RESIZABLE
    );
    
    S2D_Show(Graph->window);

    return 0;
}
