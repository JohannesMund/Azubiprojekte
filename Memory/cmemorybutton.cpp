#include "cmemorybutton.h"
#include "cresourcehelper.h"
#include <QEvent>

CMemoryButton::CMemoryButton(const int internalValue) : QPushButton(""), _internalValue(internalValue)
{
    setCheckable(true);
    setFlat(true);
    setAutoFillBackground(true);

    setMinimumSize(QSize(16, 16));
    setMaximumSize(QSize(256, 256));
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QIcon icon;
    icon.addPixmap(QPixmap(":/img/back.png"), QIcon::Active);

    icon.addPixmap(QPixmap(CResourceHelper::getInstance()->getRecourceFileName(_internalValue)), QIcon::Disabled);
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

bool CMemoryButton::isSelectable() const
{
    return !isChecked();
}

void CMemoryButton::resizeEvent(QResizeEvent* e)
{
    if (width() > height())
    {
        setIconSize(QSize(height() - 5, height() - 5));
    }
    else
    {
        setIconSize(QSize(width() - 5, width() - 5));
    }
    QPushButton::resizeEvent(e);
}
