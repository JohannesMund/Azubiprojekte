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
     */

    int getInternalValue() const;

    /**
     * @brief unreveal dreht eine audgwedeckte Karte um.
     */
    void unreveal();

    /**
     * @brief isSelectable prüft ob der Button noch gewählt werden kann
     */
    bool isSelectable() const;

protected:
    /**
     * @brief resizeEvent überschrieben von QPushButton. Wird benötigt, um bei Größenänderung die Pixmap anzupassen
     * @param e das ResizeEvent (nicht vergessen weiterzuschicken)
     */
    void resizeEvent(QResizeEvent* e) override;

private:
    const int _internalValue = -1;

    void buttonClicked(const bool checked);
};
