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
    /**
     * The pile of cards, push cards to the front and pop them from the back
     */
    std::deque<const ImmutableCard*> _pile;
    /**
     * The stack of actions, push to the back and pop from the front
     */
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
    void takeAllCardsFromPlayer(Player* p);
    void flushActionsToPileAndShuffle();
    void shufflePile();

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

    /**
     * Return the stack of actions
     * @return A const reference to the deque of actions
     */
    const std::deque<Action>& getPlayed() const;

    /**
     * Add a player to the game. The game is not responsible for the deletion of this object
     * @param player The player to be added
     */
    void addPlayer(Player* player);
};




#endif //MAO_AI_GAME_H
