#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include "playermanagement.h"

/**
 * @brief The PlayField class
 * Kapselt das Spielfeld in einerm 3x3 Array
 */
class PlayField {
public:
  /**
   * @brief The PlayFieldCoords struct
   * Koordinaten auf dem Spielfeld, mit valid funktion
   */
  struct PlayFieldCoords : public QPair<int, int> {
  public:
    PlayFieldCoords() : QPair<int, int>(-1, -1) {}
    PlayFieldCoords(const int i1, const int i2) : QPair<int, int>(i1, i2) {}

    bool isValid() const {
      return first >= 0 && first <= 2 && second >= 0 && second <= 2;
    }
    int x() const { return first; }
    int y() const { return second; }
  };

  /**
   * @brief setField
   * Setzt ein Feld
   * @param coords die Koordinaten eines Feldes
   * @param p der Spieler der das Feld besetzt
   * @return
   */
  bool setField(const PlayFieldCoords coords, const PlayerManagement::Player p);

  /**
   * @brief reset
   * Setzt das Spielfeld zurück
   */
  void reset();

  /**
   * @brief getGameOver
   * @return true wenn das spiel vorbei ist
   */
  bool getGameOver() const;

  /**
   * @brief getWinner
   * @return gibt den Sieger zurück, PlayerManagement::Player::none bei
   * unentschieden
   * @remark nur sinnvoll wenn _gameOver == true
   */
  PlayerManagement::Player getWinner() const;

  /**
   * @brief getRandomEmptyField
   * @return gibt ein zufälliges leeres Feld zurück
   */
  PlayFieldCoords getRandomEmptyField();

  /**
   * @brief getWinningMove
   * Gibt ein Feld zurück, mit dem Spieler p gewinnen kann (wenn verfügbar)
   * @param p Der Spieler der Gewinnen soll
   * @return Ein Feld, mit dem p auf jeden fall gewinnt oder invalid coords
   * @remark Nicht die effizienteste Art... Es wird nacheinander jedes freie
   * feld besetzt und geschaut ob p damit gewinnt.
   */
  PlayFieldCoords getWinningMove(const PlayerManagement::Player p);

  /**
   * @brief getPreventLosingMove
   * Gibt ein Feld zurück das eine Niederlage für Spieler p verhindern kann
   * @param p der Spieler der nicht verlieren will
   * @return Ein Feld, das Spieler p besetzen muss um nicht zu verlieren, oder
   * invalid coords
   * @remark Nicht die effizienteste Art... Es wird nacheinander jedes freie
   * feld besetzt und geschaut ob der andere Spieler damit gewinnt.
   */
  PlayFieldCoords getPreventLosingMove(const PlayerManagement::Player p);

private:
  void setGameOver(const PlayerManagement::Player &winner);
  PlayerManagement::Player getWinningPlayer() const;

  QVector<PlayFieldCoords> getEmptyFields() const;
  bool areEmptyFieldsLeft() const;
  void checkForWinner();

  PlayerManagement::Player _winner = PlayerManagement::Player::none;
  PlayerManagement::Player _grid[3][3];
  bool _gameOver = false;
};

#endif // PLAYFIELD_H
