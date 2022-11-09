#include "utils.h"

#include <algorithm>
#include <random>

namespace
{
unsigned int _numRecourceFiles = (unsigned)-1;
unsigned int countRecourceFiles()
{
    QDirIterator it(":/cards/");
    unsigned int count = 0;
    while (it.hasNext())
    {
        it.next();
        count++;
    }

    _numRecourceFiles = count;
    return _numRecourceFiles;
}

} // namespace

unsigned int ResourceHelper::getRecourceFiles()
{
    if (_numRecourceFiles == (unsigned)-1)
    {
        countRecourceFiles();
    }
    return _numRecourceFiles;
}

void Randomizer::shuffle(std::vector<unsigned int>& v)
{
    // Randomisierer initialisieren
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine{seed};

    // Zahlen schön mischeln
    std::shuffle(v.begin(), v.end(), rng);
}
