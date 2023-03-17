#include "cplayfield.h"

#include <QGridLayout>

CPlayField::CPlayField(QWidget* parent, Qt::WindowFlags f) : QFrame(parent, f)
{
    setLayout(new QGridLayout(this));
}

void CPlayField::init()
{
    createButtons();
    addButtonsToLayout();
}

void CPlayField::createButtons()
{
    for (int i = 0; i < 25; i++)
    {
        std::vector<CMineSweeperButton*> line;
        for (int j = 0; j < 25; j++)
        {
            auto i = rand() % 10;

            auto p = new CMineSweeperButton(i == 0);
            line.push_back(p);
        }
        _buttons.push_back(line);
    }
}
void CPlayField::addButtonsToLayout()
{

    delete layout();
    QGridLayout* l = new QGridLayout(this);

    int row = 0;
    int col = 0;

    l->setMargin(0);
    l->setContentsMargins(1, 1, 0, 0);

    for (const auto& line : _buttons)
    {
        for (const auto button : line)
        {
            l->addWidget(button, row, col);
            col++;
        }
        col = 0;
        row++;
    }
    setLayout(l);
}
