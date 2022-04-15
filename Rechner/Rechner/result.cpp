#include "result.h"

#include <QTextStream>
#include <math.h>

double Result::get() const
{
    if (_valid)
    {
        return _val;
    }
    return 0;
}

bool Result::isValid() const
{
    return _valid;
}

void Result::set(const double i)
{
    _val = i;
    _valid = true;
}

void Result::reset()
{
    _val = 0;
    _valid = false;
}

QString Result::toString() const
{
    int precision = 15; // Maximale Anzahl an stellen laut IEEE 754
    float f(abs(std::floor(_val)));

    while (f > 1 && precision > 0)
    {
        f /= 10;
        precision--;
    }

    QString s;
    QTextStream ts(&s);
    ts.setRealNumberNotation(QTextStream::RealNumberNotation::FixedNotation);
    ts.setRealNumberPrecision(precision - 1);
    ts << _val;

    s.remove(QRegExp("0+$"));
    s.remove(QRegExp("\\.$"));
    return s;
}
