#include "cmemorybutton.h"

#include <QEvent>

CMemoryButton::CMemoryButton(const int internalValue) : QPushButton(""), _internalValue(internalValue)
{
    setCheckable(true);
    setMinimumSize(QSize(16, 16));
    setMaximumSize(QSize(256, 256));
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    QString ressourceText = QString(":/cards/img/%1.png");
    QIcon icon;
    icon.addPixmap(QPixmap(ressourceText.arg("back")), QIcon::Active);
    icon.addPixmap(QPixmap(ressourceText.arg(_internalValue)), QIcon::Disabled);
    setIcon(icon);

    connect(this, &QAbstractButton::clicked, this, &CMemoryButton::buttonClicked);

    unreveal();
}

int CMemoryButton::getInternalValue() const
{
    return _internalValue;
}

void CMemoryButton::buttonClicked(const bool checked)
{
    if (checked)
    {
        setEnabled(false);
        emit buttonSelected();
    }
}

void CMemoryButton::unreveal()
{
    setChecked(false);
    setEnabled(true);
}

void CMemoryButton::resizeEvent(QResizeEvent* e)
{
    QPushButton::resizeEvent(e);
    if (width() > height())
    {
        setIconSize(QSize(height() - 5, height() - 5));
    }
    else
    {
        setIconSize(QSize(width() - 5, width() - 5));
    }
}
