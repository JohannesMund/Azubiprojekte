#pragma once

#include <QObject>
#include <QPushButton>

/**
 * @brief Repräsentiert eine einzelne Spielkarte
 * @remark wird mit einem Integer initialisiert, welcher das anzuzeigende Bild repräsentiert
 */

class CMemoryButton : public QPushButton
{
    Q_OBJECT

signals:

    /**
     * @brief buttonSelected wird gesendet, wenn ein Spieler diese Karte ausgewählt hat.
     */
    void buttonSelected();

public:
    CMemoryButton(const int internalValue);

    /**
     * @brief getInternalValue gibt den internen Wert (der für die Auswahl des Bildes veramtwortlich ist) zurück
     * @return
     */

    int getInternalValue() const;

    /**
     * @brief unreveal dreht eine audgwedeckte Karte um.
     */
    void unreveal();

protected:
    void resizeEvent(QResizeEvent* e) override;

private:
    void buttonClicked(const bool checked);
    const int _internalValue = -1;
};
