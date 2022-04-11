#include "calculatornumber.h"
#include <math.h>

const int CalculatorNumber::MaxPrecisision = 15;

double sqrt(CalculatorNumber& op)
{
    if( op<0 )
    {
        emit op.errorOccured(true);
        return 0;
    }
    return std::sqrt(op.get());
}

CalculatorNumber::CalculatorNumber(const CalculatorNumber &c) : QObject(0)
{
    *this = c;
}

void CalculatorNumber::addDigit(const int i)
{
    if( _volatile)
    {
        reset();
    }

    if((i < 0) || (i > 9))
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
        while( flt >= 1 )
        {
            flt /= 10;
        }

        for( int i = _floatLeadingZeroes; i > 0; i--)
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

        _integerPart = abs(trunc(d));

    unsigned int remainingDigits = MaxPrecisision - countDigits(_integerPart);

    double dd = d;
    if( dd < 0 ) dd *= -1;
    dd-=_integerPart;

    while( remainingDigits )
    {
        remainingDigits--;
        dd*=10;
        if( dd < 1.0) _floatLeadingZeroes++;
    }

    _floatPart = trunc(dd);

    while( _floatPart % 10 == 0 && _floatPart != 0)
    {
        _floatPart /= 10;
    }

    _commaPressed = ( _floatPart != 0);
    _negated = d < 0;
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

    emit errorOccured(false);
}

bool CalculatorNumber::operator==(const CalculatorNumber &op) const
{
    return( op._integerPart == _integerPart &&
            op._floatPart == _floatPart &&
            op._floatLeadingZeroes == _floatLeadingZeroes &&
            op._negated == _negated);
}

bool CalculatorNumber::operator!=(const CalculatorNumber &op) const
{
    return !(op == *this);
}

void CalculatorNumber::operator<<(const int i)
{
    int ii(i);
    QVector<int> digits;

    while(ii)
    {
        digits.push_front(ii%10);
        ii/=10;
    }

    for( const auto digit : digits)
    {
        addDigit(digit);
    }
}

void CalculatorNumber::operator<<(const char c)
{
    if( c == '-')
    {
        _negated=true;
        return;
    }
    if( c == '.' || c == ',' )
    {
        _commaPressed = true;
    }
}

bool CalculatorNumber::operator>(const double op) const
{
    return get() > op;
}

bool CalculatorNumber::operator<(const double op) const
{
    return !(*this > op);
}

bool CalculatorNumber::operator<(const CalculatorNumber &op) const
{
    return !(*this > op);
}

bool CalculatorNumber::operator>(const CalculatorNumber &op) const
{
    return get() > op.get();
}

void CalculatorNumber::operator=(const CalculatorNumber &op)
{
    _integerPart = op._integerPart;
    _floatPart = op._floatPart;
    _floatLeadingZeroes = op._floatLeadingZeroes;
    _negated = op._negated;
    _commaPressed = op._commaPressed;
}

void CalculatorNumber::operator=(const double &op)
{
    set(op);
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

bool CalculatorNumber::isNull() const
{
    return _floatPart == 0 && _integerPart == 0;
}

bool CalculatorNumber::checkMaxPrecision()
{
    int digitCount = countDigits(_integerPart);
    if( _commaPressed )
    {
        digitCount += countDigits(_floatPart);
        digitCount += _floatLeadingZeroes;
    }

    if( digitCount > MaxPrecisision)
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
    unsigned int count = 1;
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
    if( op2.isNull())
    {
        return 0;
    }

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

