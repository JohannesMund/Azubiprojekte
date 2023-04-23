#pragma once

#include <algorithm>
#include <ctime>
#include <random>

/**
 * Hilfskonstrukt für random funktionen
 */
namespace Randomizer
{

inline void initRand()
{
    std::srand(std::time(nullptr));
}

template <typename T>
void shuffle(T& v)
{

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(v.begin(), v.end(), g);
}

} // namespace Randomizer
