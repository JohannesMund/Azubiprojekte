#include "randomizer.h"

#include <cstdlib>
#include <ctime>

unsigned int Randomizer::getRandom(const unsigned int max)
{
    return std::rand() % max;
}

void Randomizer::init()
{
    std::srand(std::time(nullptr));
}
