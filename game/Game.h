//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_GAME_H
#define MAO_AI_GAME_H

#include <queue>
#include <deque>
#include "../player/Player.h"
#include "action/Action.h"

class Player;
class Action;

class Game {
private:
    std::vector<Player*> _players;
    std::queue<const ImmutableCard*> _pile;
    std::deque<Action> _played;

    short _maxCards;
    int _currentPlayer = 0;
    int _direction = 1;

    void drawNewCard(Player* player);
    const ImmutableCard* getTopCard();
    void switchDirection();
    void nextRoot();
    void pushAction(Action& action);
    void actionActCorrection(Player* p, const ImmutableCard* card);

public:

    Game();
    Game(short maxCards);
    ~Game();

    /**
     * Simulates one turn of the game
     */
    void step();

    /**
     * Checks if the given player is at turn
     * @param player The player to check
     * @return `true` if the player is at turn, `false` otherwise
     */
    bool isAtTurn(const Player* player) const;

    const std::deque<Action>& getPlayed() const;
};




#endif //MAO_AI_GAME_H
