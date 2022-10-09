//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_PLAYER_H
#define MAO_AI_PLAYER_H

#include <vector>
#include "../game/card/ImmutableCard.h"
#include "../game/action/Action.h"
#include "../game/action/Act.h"
#include "../game/validation/Correction.h"

class Action;
class Correction;

/**
 * This is an abstract base class for any player.
 */
class Player {
protected:

    std::vector<const ImmutableCard*> cards;

    /**
     * Let the player play a card, remove the pointer from the card vector
     * @return A reference to the card
     */
    virtual ImmutableCard* play() = 0;

    /**
     * Let the player do an action after playing a card
     * @return The action
     */
    virtual Act act() = 0;

public:
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
     * Return the action the player wants to do
     * @return The action
     */
    Action performAction();

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
};


#endif //MAO_AI_PLAYER_H
