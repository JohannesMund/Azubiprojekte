#pragma once

#include <QFrame>

class QGridLayout;
class CMemoryButton;

/**
 * @brief Repräsentiert das Spielfeld
 * @remark Es wird in erster Linie nur ein Layout mit Buttons gefüllt und ein wenig der Spielablauf gemanaged
 */

class CPlayField : public QFrame
{
    Q_OBJECT
public:
    CPlayField(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    /**
     * @brief init initialisiert das Spielfeld mit fields feldern
     * @param fields anzahl der Felder für das Spiel
     */
    void init(const int fields);

    /**
     * @brief getMaxFields Berechnet die maximale anzahl Spielfelder anhand der Ressourcendatei
     * @return die maximale Anzahl der Spielfelder
     */
    static unsigned int getMaxFields();

signals:

    /**
     * @brief togglePlayer Wird gesendet, wenn der Spieler wechelt
     */
    void togglePlayer();

    /**
     * @brief playerScored Wird gesendet, wenn der aktuelle Spieler scored
     */
    void playerScored();

    /**
     * @brief gameOver Wird gesendet, wenn das Spiel vorbei ist.
     */
    void gameOver();

private:
    CMemoryButton* _btnPressed1 = nullptr;
    CMemoryButton* _btnPressed2 = nullptr;
    std::vector<CMemoryButton*> _buttons = {};

    void buttonClicked(const unsigned int index);
    void clearButtonsAndLayout();
    void alignButtons();
    void checkGameOver();

    static std::vector<unsigned int> generateRandomNumbers(const int number);
};
