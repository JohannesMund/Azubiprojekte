#ifndef CDRINK_H
#define CDRINK_H

#include <string>

/**
 * @brief CDrink repräsentiert ein Getränk
 */

class CDrink
{
public:

    /**
     * @brief ESorte Ein Enum, welches verschiedene Getränketypen repräsentiert
     */
    enum ESorte
    {
        eUnbekannt,
        eBier,
        eSchnaps,
        eEnergy,
        eMineralwasser,

        eMax = eMineralwasser
    };

    CDrink();
    virtual ~CDrink();


    /**
     * @brief setName Setter für den Namen
     * @param[in] name der Name
     */
    void setName(const std::string name);

    /**
     * @brief getName Getter für den Namen
     * @return gibt dem Namen zurück
     */
    std::string getName() const;

    /**
     * @brief getSorte Getter für die Sorte
     * @return gibt die Sorte als String zurück
     */
    virtual std::string getSorteAsString() const;

    /**
     * @brief getSorte Getter für die Sorte
     * @return gibt die Sorte zurück
     */
    virtual ESorte getSorte() const;

    /**
     * @brief getAlkoholPegel Getter für den Alkoholpegel
     * @return gibt die Auswirkung auf den Alkoholpegel zurück
     */
    virtual double getAlkoholPegel() const = 0;

    /**
     * @brief sorte2String konvertiert die Sorte in einen String
     * @param[in] sorte die Sorte die zu konvertieren ist
     * @return Stringrepräsentation der Sorte
     */
    static std::string sorte2String(const ESorte sorte);

protected:
    std::string c_name;
    ESorte c_sorte = eUnbekannt;


private:


};

#endif // CDRINK_H
