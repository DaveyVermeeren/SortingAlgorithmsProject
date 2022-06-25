#include "RNG.h"

RNG::RNG()
{
    
}

RNG::~RNG()
{
    
}

int RNG::GenerateInt(int a_Min, int a_Max)
{
    int rng;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(a_Min, a_Max);
    rng = distribution(generator);
    return rng;
}

float RNG::GenerateFloat(float a_Min, float a_Max)
{
    float rng;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<float> distribution(a_Min, a_Max);
    rng = distribution(generator);
    return rng;
}
