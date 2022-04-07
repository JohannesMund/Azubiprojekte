#ifndef CDRINKFACTORY_H
#define CDRINKFACTORY_H

#include "cdrink.h"
#include <string>
#include <vector>

/**
 * @brief Factory Klasse um verschiedene Drinks zu erzeugen
 */

class CDrinkFactory
{

public:

    static std::vector<CDrink*> eineRundeAlles(const int i = 1);


    /**
     * @brief makeDrink Erzeugt ein CDrinkObjekt
     * @param[in] sorte die Sorte des Drinks (Beeinflusst direkt den Typ der Klasse
     * @param[in] name Name des Drinks
     * @return gibt spezialisiertes Objekt von CDrink zurück
     */
    static CDrink* makeDrink(const CDrink::ESorte sorte, const std::string name);

    /**
     * @brief makeBecks Erzeugt ein CDrink Objekt
     * @return gibt ein als CBier spezialisiertes Objekt CDrink mit Name "Beck's Pils" zurück
     */
    static CDrink* makeBecks();

    /**
     * @brief makeRedBull Erzeugt ein CDrink Objekt
     * @return gibt ein als CEnergy spezialisiertes Objekt CDrink mit Name "RedBull" zurück
     */
    static CDrink* makeRedBull();



private:
    CDrinkFactory();

    static std::string zufallsname();
    static CDrink::ESorte zufallsSorte();

};

#endif // CDRINKFACTORY_H
