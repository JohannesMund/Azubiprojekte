#include "cperson.h"
#include <cbier.h>
#include <iostream>

CPerson::CPerson(const std::string name, const bool hatLappen)
{
    std::cout << "Ein lautes 'Plopp' ertoent, ploetzlich steht " << name << " da, und guckt sparsam" << std::endl;

    if( hatLappen == true)
    {
        std::cout << "Voller Stolz haelt " << name << " einen im Lotto gewonnenen Fuehrerschein hoch." << std::endl;
    }

    c_name = name;
    c_hatLappen = hatLappen;
}

CPerson::~CPerson()
{

}

bool CPerson::IsFahrtauglich()
{
    if( c_alkoholpegel > 0.5)
    {
        return false;
    }
    return c_hatLappen;
}


void CPerson::drink(const CDrink* getraenk)
{
    std::cout << c_name << "Trinkt ein " << getraenk->getName() << std::endl;
    addAlkohol(getraenk->getAlkoholPegel());
}

void CPerson::drink(const CDrink* getraenk, const int anzahl)
{
    for( int i = 0; i < anzahl; i++)
    {
        drink(getraenk);
    }
}

std::string CPerson::getName() const
{
    return c_name;
}

void CPerson::addAlkohol(const double alkohol)
{
    if(alkohol > 0)
    {
        std::cout << "Der Alkoholpegel steigt, die Fahrtauglichkeit sinkt." << std::endl;
    }
    else if( alkohol < 0)
    {
        std::cout << "Der Alkoholpegel sinkt, die Fahrtauglichkeit steigt." << std::endl;
    }

    c_alkoholpegel += alkohol;
    if( c_alkoholpegel < 0 )
    {
        c_alkoholpegel = 0;
    }
}
