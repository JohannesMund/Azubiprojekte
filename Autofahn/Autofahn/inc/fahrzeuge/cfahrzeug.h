#ifndef FAHRZEUG_H
#define FAHRZEUG_H

#include <string>
#include <vector>

#include "cperson.h"

/**
 * @brief Repräsentiert ein Fahrzeug
 */
class CFahrzeug
{
public:

    /**
     * @brief ein Enum, welches verschiedene Farben definiert
     */

    enum EFarben{
        eNix,
        eRot,
        eGelb,
        eGruen,
        eBlau,
        ePink
    };

    //Konstruktor
    CFahrzeug();

    //Destruktor
    virtual ~CFahrzeug();

    /**
     * @brief setFarbe Setter für die Farbe
     */
    void setFarbe(const EFarben farbe);

    /**
     * @brief setGeschwindigkeit Setter für die Geschwindigkeit
     */
    void setGeschwindigkeit(const int geschwindigkeit);

    /**
     * @brief getFarbe Getter für die Farbe
     */
    EFarben getFarbe() const;
    /**
     * @brief Getter für die aktuelle Geschwindigkeit
     */
    int getGeschwindigkeit() const;


    /**
     * @brief lässt das Fahrzeug losfahren
     * @remark dabei werden die Mitfahrer geprüft
     */
    void fahren();


    /**
     * @brief einsteigen Fügt einen Mitfahrer hinzu
     * @param [in][in] mitfahrer
     * @return true wenn der Mitfahrer erfolgreich eingestiegen ist
     * @remark es wird geprüft ob das Auto voll ist
     */
    bool einsteigen(const CPerson mitfahrer);

    /**
     * @brief IsSchnell entscheidet ob das Fahrzeug schnell fährt
     * @return true wenn das fahrzeug schnell unterwegs ist
     * @remark pure virtual wird in den Spezilisierungen implementiert
     */
    virtual bool IsSchnell() const = 0;

    /**
     * @brief IsVoll entscheidet ob das Fahrzeig voll ist
     * @return true wenn das Fahrzeug voll ist
     * @remark pure virtual, wird in den Spezialisierungen implementiert
     */
    virtual bool IsVoll() const = 0;

protected:

    /**
     * @brief farbe2String Conviniencefunktion um eine Farbe in einen String umzuwandeln
     * @param [in] farbe
     * @return die Farbe als string oder "keine Ahnung"
     */
    static std::string farbe2String(const EFarben farbe);

    EFarben c_farbe = eNix;
    int c_geschwindigkeit;
    std::string c_fahrzeugtyp = "Fahrzeug";

    std::vector<CPerson> c_mitfahrer = {};


};


#endif // FAHRZEUG_H
