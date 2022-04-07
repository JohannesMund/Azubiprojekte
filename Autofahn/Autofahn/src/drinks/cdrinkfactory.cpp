
#include "cdrinkfactory.h"

#include <cbier.h>
#include <chexensuppe.h>
#include <cschnaps.h>
#include <cenergy.h>
#include <cmineralwasser.h>

#include <iostream>

std::string CDrinkFactory::zufallsname()
{
    std::vector<std::string> drinkNames = {"Grabbeldiewandnuff", "B-52", "Schlumpfpipi", "Bierbrause", "Bremsfluessigkeit", "Panzersprit", "Schwabentequila"};
    unsigned int i = (std::rand() % drinkNames.size());
    return drinkNames.at(i);
}

CDrink::ESorte CDrinkFactory::zufallsSorte()
{
    return (CDrink::ESorte)(std::rand() % CDrink::eMax);
}

std::vector<CDrink *> CDrinkFactory::eineRundeAlles(const int i)
{

    std::vector<CDrink*> v;


    for( int j = 0; j < i; j++)
    {
        v.push_back(makeDrink(zufallsSorte(), zufallsname()));
    }
    return v;
}

CDrink* CDrinkFactory::makeDrink(const CDrink::ESorte sorte, const std::string name)
{
    CDrink* d;
    switch(sorte)
    {
        case CDrink::eBier:
        {
            d = new CBier();
            d->setName(name);
            break;
        }
        case CDrink::eSchnaps:
        {
            d = new CSchnaps;
            d->setName(name);
            break;
        }
        case CDrink::eEnergy:
        {
            d = new CEnergy;
            d->setName(name);
            break;
        }
        case CDrink::eMineralwasser:
        {
            d = new CMineralWasser;
            d->setName(name);
            break;
        }
        case CDrink::eUnbekannt:
        {
            d = new CHexenSuppe();
            d->setName(name);
            break;
        }
    }

    return d;
}

CDrink* CDrinkFactory::makeBecks()
{
    return makeDrink(CDrink::eBier, "Beck's Pils");
}

CDrink* CDrinkFactory::makeRedBull()
{
    return makeDrink(CDrink::eEnergy, "RedBull");
}

CDrinkFactory::CDrinkFactory()
{

}
