//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_PLAYER_H
#define MAO_AI_PLAYER_H

#include <vector>
#include <deque>
#include <unordered_set>
#include "../game/card/ImmutableCard.h"
#include "../game/action/Action.h"
#include "../game/action/Act.h"
#include "../game/validation/Correction.h"
#include "../game/Game.h"

class Action;
class Correction;
class Game;

/**
 * This is an abstract base class for any player.
 */
class Player {
protected:

    std::vector<const ImmutableCard*> _cards;
    const Game* _game;


public:

    /**
     * Let the player play a card, remove the pointer from the card vector
     * This function will only be called if the player thinks he can make
     * a correct move. (when the wantsCard() function returns `false`)
     * @return A reference to the card, cannot be nullptr
     */
    virtual const ImmutableCard* play() = 0;

    /**
     * Let the player do an action after playing a card
     * If the card is nullptr than it means you just drew a card instead of playing
     * @return The acts
     */
    virtual const std::unordered_multiset<Act> act(const std::deque<Action>& played, const ImmutableCard* played_card) = 0;

    /**
     * Ask the player if he thinks it's his turn
     * @return `True` if the player thinks it's his turn, `false` otherwise
     */
    virtual bool myTurn() = 0;

    /**
     * Ask the player if he wants to draw a card
     * @return `True` if the player wants to draw a card, `false` otherwise
     */
    virtual bool wantsCard() = 0;

    /**
     * If the player played out of turn or made an error in it's action, he receives a Correction
     * This function takes a Correction, and handles it.
     * @param correction The Correction
     */
    virtual void acceptCorrection(const Correction& correction) = 0;

    /**
     * Let the player draw a card. The card will be added to the player's card collection
     * @param card The drawn card
     */
    void drawCard(const ImmutableCard* card);

    /**
     * Check if the player has no cards left
     * @return True` if the player has no cards left, `false` otherwise
     */
    bool hasNoCards();

    /**
     * Get the number of cards the player is holding
     * @return The number of cards the player is holding
     */
    int cardCount();

    /**
     * Update the game that this player is playing
     * @param game
     */
    void setGame(Game* game);
};


#endif //MAO_AI_PLAYER_H
