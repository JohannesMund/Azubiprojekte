#pragma once
#include <vector>
class CRoom;
namespace Randomizer
{
void init();

unsigned int getRandom(const unsigned int max);

void shuffle(std::vector<CRoom*>& v);

} // namespace Randomizer
