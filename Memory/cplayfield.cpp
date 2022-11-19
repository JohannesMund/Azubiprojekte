#include "cplayfield.h"
#include "cmemorybutton.h"
#include "cresourcehelper.h"
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
    createNewButtons(fields);
    addButtonsToLayout();
}

void CPlayField::createNewButtons(const unsigned int number)
{
    for (auto btn : _buttons)
    {
        if (btn != nullptr)
        {
            layout()->removeWidget(btn);
            delete btn;
        }
    }
    _buttons.clear();

    auto values = generateRandomNumbers(number);

    for (auto val : values)
    {
        CMemoryButton* btn = new CMemoryButton(val);

        /// Man bemerke das Lambda, wir kopieren idx in den scope
        auto idx = _buttons.size();
        connect(btn, &CMemoryButton::buttonSelected, this, [=]() { buttonClicked(idx); });
        _buttons.push_back(btn);
    }
}

void CPlayField::addButtonsToLayout()
{
    const int numRowsCols = calcNumColumns();

    int row = 0;
    int col = 0;

    _btnPressed1 = nullptr;
    _btnPressed2 = nullptr;

    delete layout();

    QGridLayout* pLayout = new QGridLayout(this);

    for (const auto btn : _buttons)
    {
        pLayout->addWidget(btn, row, col);

        col++;
        if (col >= numRowsCols)
        {
            col = 0;
            row++;
        }
    }

    setLayout(pLayout);
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

unsigned int CPlayField::calcNumColumns() const
{
    /// Wir versuchen, die Anzahl Zeilen / Spalten in Abhängigkeit von Höhe /Breite zu bekommen
    const double factor = double(height()) / double(width());
    const auto numButtons = _buttons.size();

    /// Wir fangen bei 1 an zu zählen, weil wir wollen hier nicht mit 0 Zeilen oder 0 Spalten rauskommen
    double rows = 1;
    int cols = 1;

    while ((floor(rows) * cols) < numButtons)
    {
        cols++;
        rows += factor;
    }
    return cols;
}

std::vector<unsigned int> CPlayField::generateRandomNumbers(const int number)
{
    /// Einen Vektor mit allen möglichen werten fülle (alles das, was wir in den Ressourcen haben
    std::vector<unsigned int> possibleValues;
    unsigned int numCards = CResourceHelper::getInstance()->countCards();
    for (unsigned int i = 1; i <= numCards; i++)
    {
        possibleValues.push_back(i);
    }

    Randomizer::shuffle(possibleValues);

    /// aus dem gemischen Vektor nehmen wir die ersten number/2 stück, so haben wir jede runde andere Bilder
    std::vector<unsigned int> values;
    for (int i = 0; i < round(number / 2); i++)
    {
        /// Jeden wert 2x!
        values.push_back(possibleValues.at(i));
        values.push_back(possibleValues.at(i));
    }

    Randomizer::shuffle(values);
    return values;
}
unsigned int CPlayField::getMaxFields()
{
    return CResourceHelper::getInstance()->countCards() * 2;
}

void CPlayField::resizeEvent(QResizeEvent* e)
{
    QFrame::resizeEvent(e);
    addButtonsToLayout();
}
