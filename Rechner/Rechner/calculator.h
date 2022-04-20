#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

#include "calculatornumber.h"
#include "result.h"

/**
 * @brief Calculator
 * Kapselt die Rechenrei, und schickt Signale wenn was anzuzeigen ist.
 */

class Calculator : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief eOperator
     * unterstützte Operatoren
     */
    enum class Operator
    {
        none,
        plus,
        minus,
        division,
        multiplication,
        percent,
        square,
        squareroot
    };

    explicit Calculator(QObject* parent = nullptr);

    /**
     * @brief numberPressed
     * Schiebt eine Ziffer in CalculatorNumber
     * @param i
     */
    void numberPressed(const int i);

    /**
     * @brief removeLast
     * entfernt die letzte Eingabe aus CalculatorNumber
     */
    void removeLast();

    /**
     * @brief commaPressed
     * Komma wurde gedrückt
     */
    void commaPressed();
    /**
     * @brief negatedPressed
     * +/- wurde gedrückt
     */
    void negatedPressed();
    /**
     * @brief setOperator
     * @param op
     * gibt den Operator für die nächste Rechnung vor
     */
    void setOperator(const Operator op);

    /**
     * @brief clearCurrent
     * C/CE
     */
    void clearCurrent();
    void clearAll();

    /**
     * @brief calc
     * rechnet
     */
    void calc();

    /**
     * @brief operator2String
     * @param op
     * @return String-repräsentation des Operators
     */
    static QString operator2String(const Operator& op);

signals:

    /**
     * @brief errorOccured
     * wird gesendet, wenn ein Fehler aufgetreten ist (z.B. die Genauigkeit gesprengt wurde, oder DIVby0 oder SQRT(-1)
     * @param b
     */
    void errorOccured(const bool b);

    /**
     * @brief resultUpdated
     * wird gesendet, wenn sich das ergebniss geändert hat
     * @param result
     */
    void resultUpdated(const QString& result);

    /**
     * @brief numberUpdated
     * wird gesendet, wenn sich der aktuelle Operand geändert hat
     * @param number
     */
    void numberUpdated(const QString& number);

    /**
     * @brief operatorUpdated
     * wird gesendet, wenn sich der Operator geändert hat.
     * @param op
     */
    void operatorUpdated(const QString& op);

private:
    void emitNumber();
    void emitResult();
    void emitOperator();

    CalculatorNumber _currentNumber;
    Result _currentResult;

    Operator _operator = Operator::none;
};

#endif // CALCULATOR_H
