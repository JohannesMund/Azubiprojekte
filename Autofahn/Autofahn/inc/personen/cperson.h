#ifndef CMITFAHRER_H
#define CMITFAHRER_H

#include <cdrink.h>
#include <string>

/**
 * @brief CPerson Repräsentiert eine Person die im Auto mitfahren kann
 */

class CPerson
{
public:

    /**
     * @brief Konstruktor
     * @param[in] name Name der Person
     * @param[in] hatLappen Hat die Person einen Führerschein? (optional)
     * @remark Wird verzichten auf einen Standardkonstruktor.
     */
    CPerson(const std::string name, const bool hatLappen = false);
    virtual ~CPerson();

    /**
     * @brief IsFahrtauglich
     * @return true wenn die Person noch als Fahrtauglich gilt
     */
    bool IsFahrtauglich();

    /**
     * @brief drink schüttet einen Drink in die Person hinein
     * @param[in] drink  der drink
     */
    virtual void drink(const CDrink* getraenk);

    /**
     * @brief drink schüttet einen Drink in die Person hinein
     * @param[in] drink der drink
     * @param[in] anzahl Die Menge der Drinks
     */
    virtual void drink(const CDrink* getraenk, const int anzahl);


    /**
     * @brief getName Getter für den Name
     */
    std::string getName() const;


protected:

    /**
     * @brief addAlkohol erhöht den Alkoholspiegel
     * @param[in] alkohol wert um den der Alkoholspiegel erhöht wird
     */
    void addAlkohol(const double alkohol);

private:

    std::string c_name;
    bool c_hatLappen = false;
    double c_alkoholpegel = 0;

};

#endif // CMITFAHRER_H
