#include "cschnaps.h"

#include <cdrinkfactory.h>

CSchnaps::CSchnaps()
{
    c_sorte = CDrink::eSchnaps;
}

CSchnaps::~CSchnaps()
{

}

double CSchnaps::getAlkoholPegel() const
{
    return 0.3;
}

