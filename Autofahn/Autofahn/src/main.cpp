#include "cauto.h"
#include "cpanzer.h"

#include <cbier.h>
#include <cdrinkfactory.h>
#include <cenergy.h>
#include <channes.h>
#include <chansdieter.h>
#include <cmineralwasser.h>
#include <cschnaps.h>
#include <iostream>

using namespace std;

void printBreak(std::string title, std::string subtitle)
{
    cout << endl;
    cout << "========== " << title << " ==========" << endl;
    cout << subtitle;
    cout << endl << endl;
}

int main()
{

    printBreak("Initialisierung", "Schauen wir mal, dass wir die Leute zusammenbekommen");

    CPerson gabi("Gabriel", true);
    CPerson dennis("Dennis");
    CPerson lukas("Lukas");
    CHannes hannes;
    CPerson sebastian("Sebastian", true);
    CPerson assiGabi("Assi-Gabi", true);

    CHansDieter hansDieter;


    printBreak("Party hard", "Schuetten wir mal was in die Leute rein");

    auto redBull = CDrinkFactory::makeRedBull();
    auto jackDaniels = CDrinkFactory::makeDrink(CDrink::eSchnaps, "Jack Daniels");
    auto wodka = CDrinkFactory::makeDrink(CDrink::eSchnaps, "Wodka Gorbi");
    auto becks = CDrinkFactory::makeBecks();
    auto sprudel = CDrinkFactory::makeDrink(CDrink::eMineralwasser, "Sprudel");

    hannes.drink(redBull);
    hannes.drink(sprudel);
    hannes.drink(jackDaniels);

    dennis.drink(wodka);

    assiGabi.drink(becks);
    assiGabi.drink(becks, 5);

    delete redBull;
    delete jackDaniels;
    delete wodka;
    delete becks;
    delete sprudel;

    printBreak("einfaches Auto", "Die Azubimeute cruised mit dem Auto herum");

    CAuto einfachesAuto;
    einfachesAuto.setFarbe(CFahrzeug::eRot);
    einfachesAuto.setGeschwindigkeit(100);

    einfachesAuto.einsteigen(gabi);
    einfachesAuto.einsteigen(lukas);
    einfachesAuto.einsteigen(dennis);
    einfachesAuto.einsteigen(hansDieter);
    einfachesAuto.fahren();

    printBreak("Panzer", "Der assoziale, besoffene Gabriel will Panzer fahren");

    CPanzer f2;
    f2.setGeschwindigkeit(100);
    f2.einsteigen(assiGabi);

    f2.fahren();


    printBreak("rotes Auto", "Die Azubimeute moechte den Dennis auch mal im roten Auto fahren lassen");

    CRotesAuto einhorn;
    einhorn.einsteigen(dennis);
    einhorn.einsteigen(gabi);
    einhorn.einsteigen(lukas);
    einhorn.einsteigen(hannes);
    einhorn.einsteigen(sebastian);
    einhorn.einsteigen(assiGabi);

    einhorn.setGeschwindigkeit(100);
    einhorn.fahren();





    return 0;
}
