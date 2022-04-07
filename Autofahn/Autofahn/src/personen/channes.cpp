#include "channes.h"

#include <iostream>
#include <string>

CHannes::CHannes()
    :CPerson("Hannes", true)
{

}

CHannes::~CHannes()
{

}

void CHannes::drink(const CDrink* getraenk)
{
    if( getraenk->getAlkoholPegel() > 0.0)
    {
        std::cout << "Hannes macht die Spassbremse und lehnt alkoholische Getraenke ab" << std::endl;
        return;
    }

    CPerson::drink(getraenk);

    if( getraenk->getSorte() == CDrink::eEnergy &&
        getraenk->getName() == "RedBull")
    {
        std::cout << "Aufgrund der Abscheulichkeit des dargebotenen Getraenks muss sich " << getName() << " hart uebergeben" << std::endl;
    }
}
