#ifndef CPLAYERMANAGEMENT_H
#define CPLAYERMANAGEMENT_H

class CPlayerManagement
{
public:
    enum class Player
    {
        none,
        red,
        yellow
    };
    CPlayerManagement();

    void reset();

    Player getCurrentPlayer() const;
    void toggleCurrentPlayer();

private:
    Player _currentPlayer = Player::none;
};

#endif // CPLAYERMANAGEMENT_H
