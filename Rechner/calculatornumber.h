#ifndef CALCULATORNUMBER_H
#define CALCULATORNUMBER_H

#include <QString>
#include <QObject>

#include <math.h>

/**
 * @brief The CalculatorNumber class
 * Kapselt eine Zahl, die in der Anzeige des Taschenrechners angezeigt werden kann
 */

class CalculatorNumber : public QObject
{
    Q_OBJECT
public:

    static const int MaxPrecisision;

    /**
     * @brief addDigit
     * fügt eine Ziffer hinzu. hierbei wird darauf geachtet, dass andere Eingaben (Komma, +/-, etc) beachtet werden
     * @param i die hinzuzufügende ziffer
     */
    void addDigit(const int i);

    /**
     * @brief removeLast
     * entfernt die letzte Ziffer oder das komma
     */
    void removeLast();


    /**
     * @brief setCommaPressed
     * es wurde auf komma gedrückt
     * @param b komma hin oder komma weg
     */
    void setCommaPressed(const bool b);

    /**
     * @brief toggleNegated
     * toggelt +/-
     */
    void toggleNegated();

    /**
     * @brief get
     * @return die Zahl als float
     */
    double get() const;

    /**
     * @brief set
     * schreibt einen double
     * @param d
     */
    void set(const double d);

    /**
     * @brief setVolatile
     * setzt den wert volatile, die nächste eingabe wirde den wert resetten
     */
    void setVolatile();

    /**
     * @brief toString
     * @return die Zahl als string
     */
    QString toString() const;

    /**
     * @brief reset
     * setzt die Zahl zurück
     */
    void reset();

signals:

    /**
     * @brief errorOccured
     * wird emittiert wenn ein Fehler aufgetreten ist (z.B. die maximale
     * Präzision eines floats erreicht wird
     * @param b fehler oder nicht fehler, das ist hier die frage
     */

    void errorOccured(const bool b) const;

private:
    unsigned long long _integerPart = 0;
    unsigned long long _floatPart = 0;
    int _floatLeadingZeroes = 0;

    bool _commaPressed = false;
    bool _negated = false;
    bool _volatile = false;


    bool checkMaxPrecision() const;
    unsigned int countDigits(const unsigned long long i) const;

};

/**
 * @brief globale rechnerei
 */

static double sqrt(const CalculatorNumber& op)
{
    return std::sqrt(op.get());
}

/**
 * @brief Überladene Operatoren
 */

double operator+(const double op1, const CalculatorNumber &op2);
double operator+(const CalculatorNumber &op1, const double op2 );
double operator+(const CalculatorNumber &op1, const CalculatorNumber &op2 );

double operator-(const double op1, const CalculatorNumber &op2);
double operator-(const CalculatorNumber &op1, const double op2 );
double operator-(const CalculatorNumber &op1, const CalculatorNumber &op2 );

double operator*(const double op1, const CalculatorNumber &op2);
double operator*(const CalculatorNumber &op1, const double op2 );
double operator*(const CalculatorNumber &op1, const CalculatorNumber &op2 );

double operator/(const double op1, const CalculatorNumber &op2);
double operator/(const CalculatorNumber &op1, const double op2 );
double operator/(const CalculatorNumber &op1, const CalculatorNumber &op2 );


#endif // CALCULATORNUMBER_H
