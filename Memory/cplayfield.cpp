#include "cplayfield.h"
#include "cmemorybutton.h"

#include <QGridLayout>
#include <QPushButton>

#include <algorithm>
#include <chrono>
#include <math.h>
#include <random>

const int CPlayField::_maxFields = 64;

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

    clearButtons();

    auto values = generateRandomNumbers(fields);

    QGridLayout* buttonLayout = qobject_cast<QGridLayout*>(layout());

    for (int i = 0; i < fields; i++)
    {
        CMemoryButton* btn = new CMemoryButton(values.at(i));
        buttonLayout->addWidget(btn, row, col);
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

    setLayout(buttonLayout);
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
    }
    else
    {
        emit togglePlayer();
    }
}

void CPlayField::clearButtons()
{
    for (auto btn : _buttons)
    {
        delete btn;
    }

    _buttons.clear();
}

std::vector<unsigned int> CPlayField::generateRandomNumbers(const int number)
{
    // Randomisierer initialisieren
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine{seed};

    // Einen Vektor mit allen möglichen werten fülle (1..32, das was wir in den Ressourcen haben
    std::vector<unsigned int> possibleValues;

    for (unsigned int i = 1; i <= round(_maxFields / 2); i++)
    {
        possibleValues.push_back(i);
    }

    // Zahlen schön mischeln
    std::shuffle(possibleValues.begin(), possibleValues.end(), rng);

    // aus dem gemischen Vektor nehmen wir die ersten number/2 stück, so haben wir jede runde andere Bilder
    std::vector<unsigned int> values;
    for (int i = 0; i < round(number / 2); i++)
    {
        values.push_back(possibleValues.at(i));
        values.push_back(possibleValues.at(i));
    }

    // und dann nochmal schön mischeln
    std::shuffle(values.begin(), values.end(), rng);
    return values;
}
