#include "calculator.h"

Calculator::Calculator(QObject* parent) : QObject(parent)
{
    connect(&_currentNumber, &CalculatorNumber::errorOccured, [&](const bool& b) { emit errorOccured(b); });
}

void Calculator::numberPressed(const int i)
{
    _currentNumber << i;
    emitNumber();
}

void Calculator::removeLast()
{
    _currentNumber.removeLast();
    emitNumber();
}

void Calculator::commaPressed()
{
    _currentNumber.setCommaPressed(true);
    emitNumber();
}

void Calculator::negatedPressed()
{
    _currentNumber.toggleNegated();
    emitNumber();
}

void Calculator::setOperator(const Calculator::Operator op)
{
    if (op == Operator::squareroot || op == Operator::square)
    {
        _operator = op;
        calc();
        _operator = Operator::none;
        emitOperator();
    }
    else
    {
        calc();
        _operator = op;
        emitOperator();
    }
}

void Calculator::clearCurrent()
{

    _currentNumber.reset();
    emitNumber();
}

void Calculator::clearAll()
{
    _currentResult.reset();
    _operator = Operator::none;
    clearCurrent();
}

void Calculator::emitNumber()
{
    emit numberUpdated(_currentNumber.toString());
}

void Calculator::emitResult()
{
    if (_currentResult.isValid())
    {
        emit resultUpdated(_currentResult.toString());
    }
    else
    {
        emit resultUpdated("0");
    }
}

void Calculator::emitOperator()
{
    emit operatorUpdated(operator2String(_operator));
}

void Calculator::calc()
{

    if (_currentResult.isValid() == false && _operator != Operator::square && _operator != Operator::squareroot)
    {
        _currentResult.set(_currentNumber.get());
    }
    else
    {
        double op1 = _currentResult.get();
        double res = 0;

        switch (_operator)
        {
        case Operator::plus:
            res = op1 + _currentNumber;
            break;
        case Operator::minus:
            res = op1 - _currentNumber;
            break;
        case Operator::multiplication:
            res = op1 * _currentNumber;
            break;
        case Operator::division:
            res = op1 / _currentNumber;
            break;
        case Operator::percent:
            res = op1 * (_currentNumber / 100);
            break;
        case Operator::square:
            res = _currentNumber * _currentNumber;
            break;
        case Operator::squareroot:
            res = sqrt(_currentNumber);
            break;
        case Operator::none:
            res = _currentNumber.get();
            break;
        }

        _currentResult.set(res);
        _currentNumber.set(res);
    }

    _currentNumber.setVolatile();
    emitNumber();
    emitResult();
}

QString Calculator::operator2String(const Calculator::Operator& op)
{
    switch (op)
    {
    case Operator::plus:
        return "+";
        break;
    case Operator::minus:
        return "-";
        break;
    case Operator::multiplication:
        return "*";
        break;
    case Operator::division:
        return "/";
        break;
    case Operator::percent:
        return "%";
        break;
    case Operator::square:
        return "x²";
        break;
    case Operator::squareroot:
        return "√";
        break;
    case Operator::none:
        return QString();
        break;
    }
    return QString();
}
