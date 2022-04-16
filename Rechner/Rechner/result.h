#pragma once

#include <QString>

/**
 * @brief The Result class
 * kapselt das Ergebnis der Rechnerei als float
 */

class Result
{

public:
    /**
     * @brief get
     * @return die enthaltene Zahl als float
     */
    double get() const;

    /**
     * @brief isValid
     * @return ist das aktuelle ergebnis gültig oder uninitialisiert
     */
    bool isValid() const;

    /**
     * @brief set
     * setzt den wert
     * @param i
     */
    void set(const double i);

    /**
     * @brief reset
     * Setzt den wert zurück, isValid ist false
     */
    void reset();

    /**
     * @brief toString
     * @return die Zahl als String mit passender Präzision
     */
    QString toString() const;

private:
    double _val = 0;
    bool _valid = false;
};
