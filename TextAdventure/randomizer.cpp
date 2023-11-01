#include "randomizer.h"

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <random>

unsigned int Randomizer::getRandom(const unsigned int max)
{
    return std::rand() % max;
}

void Randomizer::init()
{
    std::srand(std::time(nullptr));
}

void Randomizer::shuffle(std::vector<CRoom*>& v)
{
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine{seed};
    std::shuffle(v.begin(), v.end(), rng);
}
