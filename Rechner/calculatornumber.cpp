#include "calculatornumber.h"
#include <math.h>

void CalculatorNumber::addDigit(const int i)
{
    if( _volatile)
    {
        reset();
    }

    if(i < 0 || i > 9 )
    {
        return;
    }

    if( checkMaxPrecision())
    {
        return;
    }

    if( _commaPressed)
    {
        if( _floatPart == 0 && i == 0)
        {
            _floatLeadingZeroes++;
        }
        else
        {
            _floatPart = _floatPart * 10 + i;
        }
    }
    else
    {
        _integerPart = _integerPart * 10 + i;
    }
}

void CalculatorNumber::setCommaPressed(const bool b)
{
    if( _volatile)
    {
        reset();
    }

    _commaPressed = b;
}

void CalculatorNumber::toggleNegated()
{
    if( _volatile)
    {
        reset();
    }

    if( _negated )
    {
        _negated = false;
    }
    else
    {
        _negated = true;
    }
}

double CalculatorNumber::get() const
{
    double val = _integerPart;

    if( _commaPressed )
    {
        double flt = _floatPart;
        while( flt > 1 )
        {
            flt /= 10;
        }

        for( int i = _floatLeadingZeroes+1; i > 0; i--)
        {
            flt /= 10 ;
        }

        val += flt;
    }

    if( _negated )
        val *= -1;

    return val;
}

void CalculatorNumber::set(const double d)
{
    reset();
    if( d > 0 )
    {
        _integerPart = trunc(d);
    }

    unsigned int remainingDigits = 15 - countDigits(_integerPart) -1;

    _floatPart = trunc(trunc(d) * 10 * remainingDigits);

    while( _floatPart % 10 == 0 && _floatPart != 0)
    {
        _floatPart /= 10;
        _floatLeadingZeroes++;
    }
}

void CalculatorNumber::setVolatile()
{
    _volatile = true;
}

QString CalculatorNumber::toString() const
{
    QString s(QString::number(_integerPart));
    if( _commaPressed )
    {
        s.append(",");


        for( int i = _floatLeadingZeroes; i > 0; --i)
        {
            s.append("0");
        }

        if( _floatPart > 0 )
        {
            s.append(QString::number(_floatPart));
        }
    }
    if( _negated )
    {
        s.prepend("-");
    }

    return s;
}

void CalculatorNumber::reset()
{
    _integerPart = 0;
    _floatLeadingZeroes = 0;
    _floatPart = 0;
    _negated = false;
    _commaPressed = false;
    _volatile = false;
}

void CalculatorNumber::removeLast()
{
    if( _volatile)
    {
        reset();
        return;
    }

    if( _commaPressed)
    {
        if( _floatPart > 0)
        {
            _floatPart = floor(_floatPart / 10);
        }
        else if( _floatLeadingZeroes > 0)
        {
            _floatLeadingZeroes--;
        }
        else if( _commaPressed )
        {
            _commaPressed = false;
        }
    }
    else
    {
        _integerPart = floor(_integerPart / 10);
    }
    checkMaxPrecision();
}

bool CalculatorNumber::checkMaxPrecision() const
{
    int digitCount = countDigits(_integerPart);
    if( _commaPressed )
    {
        digitCount += countDigits(_floatPart);
        digitCount += _floatLeadingZeroes;
    }

    if( digitCount >= 15)
    {
        emit errorOccured(true);
        return true;
    }

    emit errorOccured(false);
    return false;
}

unsigned int CalculatorNumber::countDigits(const unsigned long long i) const
{
    unsigned long long j(i);
    unsigned int count = 0;
    while(j > 1)
    {
        j = floor(j/10);
        count ++;
    }
    return count;
}

double operator+(const double op1, const CalculatorNumber &op2)
{
    return op1 + op2.get();
}

double operator+(const CalculatorNumber &op1, const double op2)
{
    return op1.get() + op2;
}

double operator+(const CalculatorNumber &op1, const CalculatorNumber &op2)
{
    return op1.get() + op2.get();
}

double operator-(const double op1, const CalculatorNumber &op2)
{
    return op1 - op2.get();
}

double operator-(const CalculatorNumber &op1, const double op2)
{
    return op1.get() - op2;
}

double operator-(const CalculatorNumber &op1, const CalculatorNumber &op2)
{
    return op1.get() - op2.get();
}

double operator*(const double op1, const CalculatorNumber &op2)
{
    return op1 * op2.get();
}

double operator*(const CalculatorNumber &op1, const double op2)
{
    return op1.get() * op2;
}

double operator*(const CalculatorNumber &op1, const CalculatorNumber &op2)
{
    return op1.get() * op2.get();
}

double operator/(const double op1, const CalculatorNumber &op2)
{
    return op1 / op2.get();
}

double operator/(const CalculatorNumber &op1, const double op2)
{
    return op1.get() / op2;
}

double operator/(const CalculatorNumber &op1, const CalculatorNumber &op2)
{
    return op1.get() / op2.get();
}

