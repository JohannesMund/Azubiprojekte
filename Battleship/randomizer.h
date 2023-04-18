#pragma once

#include <algorithm>
#include <random>

namespace Randomizer
{

template <typename T>
void shuffle(T& v)
{

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(v.begin(), v.end(), g);
}

} // namespace Randomizer
