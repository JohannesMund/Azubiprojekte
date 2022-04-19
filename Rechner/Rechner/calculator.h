#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

#include "calculatornumber.h"
#include "result.h"

class Calculator : public QObject
{
    Q_OBJECT
public:
    enum class eOperator
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

    void numberPressed(const int i);
    void removeLast();

    void commaPressed();
    void negatedPressed();
    void setOperator(const eOperator op);

    void clearCurrent();
    void clearAll();

    void calc();

    explicit Calculator(QObject* parent = nullptr);

signals:

    void errorOccured(const bool b);

    void resultUpdated(const QString& result);
    void numberUpdated(const QString& number);
    void operatorUpdated(const QString& op);

private:
    void emitNumber();
    void emitResult();
    void emitOperator();

    static QString operator2String(const eOperator& op);

    CalculatorNumber _currentNumber;
    Result _currentResult;

    eOperator _operator = eOperator::none;
};

#endif // CALCULATOR_H
