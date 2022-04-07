#include "cdrink.h"

CDrink::CDrink()
{

}

CDrink::~CDrink()
{

}

void CDrink::setName(const std::string name)
{
    c_name = name;
}

std::string CDrink::getName() const
{
    return c_name;
}

std::string CDrink::getSorteAsString() const
{
    return sorte2String(c_sorte);
}

CDrink::ESorte CDrink::getSorte() const
{
    return c_sorte;
}

std::string CDrink::sorte2String(const CDrink::ESorte sorte)
{
    switch(sorte)
    {
    case eBier:
        return "Bier";

    case eSchnaps:
        return "Schnaps";

    case eEnergy:
        return "Energy Drink";

    case eMineralwasser:
        return "Mineralwasser";

    case eUnbekannt:
        return "Unbekanntes, gruenlich dampfendes, zischendes Getraenk";
    }
    return "";
}
