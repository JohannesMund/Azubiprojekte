#include "playfieldcoords.h"

PlayFieldCoords::PlayFieldCoords() : QPair<int, int>(-1, -1)
{
}

PlayFieldCoords::PlayFieldCoords(const int i1, const int i2) : QPair<int, int>(i1, i2)
{
}

bool PlayFieldCoords::isValid() const
{
    return first >= 0 && first <= 2 && second >= 0 && second <= 2;
}

int PlayFieldCoords::x() const
{
    return first;
}

int PlayFieldCoords::y() const
{
    return second;
}
