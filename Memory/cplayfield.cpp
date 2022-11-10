#include "cplayfield.h"
#include "cmemorybutton.h"
#include "utils.h"

#include <QDirIterator>
#include <QGridLayout>
#include <QPushButton>

#include <chrono>
#include <math.h>

namespace
{

} // namespace

CPlayField::CPlayField(QWidget* parent, Qt::WindowFlags f) : QFrame(parent, f)
{
    setLayout(new QGridLayout(this));
}

void CPlayField::init(const int fields)
{
    const int numRowsCols = std::ceil(std::sqrt(fields));

    int row = 0;
    int col = 0;

    _btnPressed1 = nullptr;
    _btnPressed2 = nullptr;

    clearButtonsAndLayout();

    auto values = generateRandomNumbers(fields);

    setLayout(new QGridLayout(this));
    auto pLayout = qobject_cast<QGridLayout*>(layout());

    for (int i = 0; i < fields; i++)
    {
        CMemoryButton* btn = new CMemoryButton(values.at(i));
        pLayout->addWidget(btn, row, col);
        _buttons.push_back(btn);

        // Man bemerke das Lambda, wir kopieren das i in den scope
        connect(btn, &CMemoryButton::buttonSelected, this, [=]() { buttonClicked(i); });

        col++;
        if (col >= numRowsCols)
        {
            col = 0;
            row++;
        }
    }
    alignButtons();
}

void CPlayField::buttonClicked(const unsigned int index)
{
    if (index >= _buttons.size())
    {
        return;
    }

    CMemoryButton* btn = _buttons.at(index);

    if (_btnPressed1 != nullptr && _btnPressed2 != nullptr)
    {
        if (_btnPressed1->getInternalValue() != _btnPressed2->getInternalValue())
        {
            _btnPressed1->unreveal();
            _btnPressed2->unreveal();
        }

        _btnPressed1 = nullptr;
        _btnPressed2 = nullptr;
    }

    if (_btnPressed1 == nullptr)
    {
        _btnPressed1 = btn;
        return;
    }
    else
    {
        _btnPressed2 = btn;
    }

    if (_btnPressed1->getInternalValue() == _btnPressed2->getInternalValue())
    {
        emit playerScored();
        checkGameOver();
    }
    else
    {
        emit togglePlayer();
    }
}

void CPlayField::clearButtonsAndLayout()
{
    for (auto btn : _buttons)
    {
        if (btn != nullptr)
        {
            layout()->removeWidget(btn);
            delete btn;
        }
    }
    delete layout();
    _buttons.clear();
}

void CPlayField::alignButtons()
{
    auto pLayout = qobject_cast<QGridLayout*>(layout());
    for (int i = 0; i < pLayout->columnCount(); i++)
    {
        pLayout->setColumnStretch(i, 1);
    }

    for (int i = 0; i < pLayout->rowCount(); i++)
    {
        pLayout->setRowStretch(i, 1);
    }
}

void CPlayField::checkGameOver()
{
    for (auto btn : _buttons)
    {
        if (btn->isSelectable())
        {
            return;
        }
    }
    emit gameOver();
}

std::vector<unsigned int> CPlayField::generateRandomNumbers(const int number)
{

    // Einen Vektor mit allen möglichen werten fülle (1..32, das was wir in den Ressourcen haben
    std::vector<unsigned int> possibleValues;

    for (unsigned int i = 1; i <= ResourceHelper::countCards(); i++)
    {
        possibleValues.push_back(i);
    }

    Randomizer::shuffle(possibleValues);

    // aus dem gemischen Vektor nehmen wir die ersten number/2 stück, so haben wir jede runde andere Bilder
    std::vector<unsigned int> values;
    for (int i = 0; i < round(number / 2); i++)
    {
        values.push_back(possibleValues.at(i));
        values.push_back(possibleValues.at(i));
    }

    Randomizer::shuffle(values);
    return values;
}
unsigned int CPlayField::getMaxFields()
{
    return ResourceHelper::countCards() * 2;
}
