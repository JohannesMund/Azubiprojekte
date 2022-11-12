#include "utils.h"

#include <algorithm>
#include <random>

void Randomizer::shuffle(std::vector<unsigned int>& v)
{
    // Randomisierer initialisieren
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine{seed};

    // Zahlen schön mischeln
    std::shuffle(v.begin(), v.end(), rng);
}
