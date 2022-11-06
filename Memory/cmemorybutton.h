#pragma once

#include <QObject>
#include <QPushButton>

class CMemoryButton : public QPushButton
{
    Q_OBJECT

signals:
    void buttonSelected();

public:
    CMemoryButton(const int internalValue);

    int getInternalValue() const;
    void buttonClicked(const bool checked);
    void unreveal();

private:
    void reveal();

    const int _internalValue = -1;
};
