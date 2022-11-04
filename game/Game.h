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

    int _currentPlayer = 0;
    int _direction = 1;
    bool _gameIsNotFinished = true;
    unsigned int _gameStepCount = 0;

    void drawNewCard(Player* player);
    const ImmutableCard* getTopCard();
    void switchDirection();
    void nextRoot();
    void pushAction(Action& action);
    void actionActCorrection(Player* p, const ImmutableCard* card);
    void takeAllCardsFromPlayer(Player* p);
    void flushActionsToPileAndShuffle();
    void shufflePile();

    /**
     * Simulates one turn of the game. Updates _gameIsNotFinished when player wins
     */
    void step();

public:

    Game();
    ~Game();

    /**
     * Give each player 3 cards, call step function until a player has no cards left.
     * Take al the leftover cards back from the players
     */
    void playGame();


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

    unsigned int getGameStepCount() const;
};




#endif //MAO_AI_GAME_H
