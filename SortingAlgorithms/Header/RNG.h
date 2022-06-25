#pragma once
#include <random>
#include <chrono>

class RNG
{
public:
    RNG();
    ~RNG();

    int GenerateInt(int a_Min, int a_Max);
    float GenerateFloat(float a_Min, float a_Max);
private:

};