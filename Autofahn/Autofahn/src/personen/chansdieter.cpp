#include "chansdieter.h"
#include <iostream>

#
CHansDieter::CHansDieter()
    :CPerson("Hans-Dieter", true)
{

}

CHansDieter::~CHansDieter()
{

}

void CHansDieter::drink(const CDrink *getraenk)
{
    std::cout << getName() << "Trinkt ein " << getraenk->getName() << std::endl;
    auto i = getraenk->getAlkoholPegel() * (1/4);

    addAlkohol(i);
}


