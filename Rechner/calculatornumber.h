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
     * @brief Standard- und Copykonstruktor
     */
    CalculatorNumber() : QObject(0){};
    CalculatorNumber(const CalculatorNumber& c);

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
     * @brief isNull
     * @return ob der Wert 0 ist
     * @remark get() == 0 sollte NICHT geprüft werden
     */
    bool isNull() const;

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

    /**
     * @brief emitError
     * Emitiert einen Fehler
     */
    void emitError();

    /**
     * @brief Überladene Operatoren
     */

    bool operator==(const CalculatorNumber &op) const;
    bool operator!=(const CalculatorNumber &op) const;

    void operator=(const CalculatorNumber &op);
    void operator=(const double &op);

    void operator<<(const int i);
    void operator<<(const char c);

    bool operator>(const double op) const;
    bool operator>(const CalculatorNumber &op) const;

    bool operator<(const double op) const;
    bool operator<(const CalculatorNumber &op) const;

signals:

    /**
     * @brief errorOccured
     * wird emittiert wenn ein Fehler aufgetreten ist (z.B. die maximale
     * Präzision eines floats erreicht wird
     * @param b fehler oder nicht fehler, das ist hier die frage
     */
    void errorOccured(const bool b);

private:
    unsigned long long _integerPart = 0;
    unsigned long long _floatPart = 0;
    int _floatLeadingZeroes = 0;

    bool _commaPressed = false;
    bool _negated = false;
    bool _volatile = false;

    bool checkMaxPrecision();
    unsigned int countDigits(const unsigned long long i) const;
};

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

/**
 * @brief globale rechnerei
 */

static double sqrt(CalculatorNumber& op)
{
    if( op<0 )
    {
        op.emitError();
        return 0;
    }
    return std::sqrt(op.get());
}
#endif // CALCULATORNUMBER_H
