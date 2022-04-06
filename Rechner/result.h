#ifndef RESULT_H
#define RESULT_H

#include <QString>

class Result
{
public:
    Result();

    double get() const;
    bool isValid() const;
    void set(const double i);
    void reset();

    QString toString() const;

private:
    double _val = 0;
    bool _valid = false;

};

#endif // RESULT_H
