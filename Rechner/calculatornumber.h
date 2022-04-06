#ifndef CALCULATORNUMBER_H
#define CALCULATORNUMBER_H

#include <QString>

#include <QObject>

class CalculatorNumber : public QObject
{
    Q_OBJECT
public:
    CalculatorNumber();

    void addDigit(const int i);
    void setCommaPressed(const bool b);
    void toggleNegated();

    double get() const;
    QString toString() const;

    void reset();
    void removeLast();

    static double sqrt(const CalculatorNumber& op);

signals:
    void errorOccured(const bool b) const;

private:
    unsigned long long _integerPart = 0;
    unsigned long long _floatPart = 0;
    int _floatLeadingZeroes = 0;

    bool _commaPressed = false;
    bool _negated = false;

    bool maxPrecisionReached() const;


};



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
