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

void Calculator::setOperator(const Calculator::eOperator op)
{
    if (op == eOperator::squareroot || op == eOperator::square)
    {
        _operator = op;
        calc();
        _operator = eOperator::none;
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
    _operator = eOperator::none;
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

    if (_currentResult.isValid() == false && _operator != eOperator::square && _operator != eOperator::squareroot)
    {
        _currentResult.set(_currentNumber.get());
    }
    else
    {
        double op1 = _currentResult.get();
        double res = 0;

        switch (_operator)
        {
        case eOperator::plus:
            res = op1 + _currentNumber;
            break;
        case eOperator::minus:
            res = op1 - _currentNumber;
            break;
        case eOperator::multiplication:
            res = op1 * _currentNumber;
            break;
        case eOperator::division:
            res = op1 / _currentNumber;
            break;
        case eOperator::percent:
            res = op1 * (_currentNumber / 100);
            break;
        case eOperator::square:
            res = _currentNumber * _currentNumber;
            break;
        case eOperator::squareroot:
            res = sqrt(_currentNumber);
            break;
        case eOperator::none:
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

QString Calculator::operator2String(const Calculator::eOperator& op)
{
    switch (op)
    {
    case eOperator::plus:
        return "+";
        break;
    case eOperator::minus:
        return "-";
        break;
    case eOperator::multiplication:
        return "*";
        break;
    case eOperator::division:
        return "/";
        break;
    case eOperator::percent:
        return "%";
        break;
    case eOperator::square:
        return "x²";
        break;
    case eOperator::squareroot:
        return "√";
        break;
    case eOperator::none:
        return "";
        break;
    }
}
