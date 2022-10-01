//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_PLAYER_H
#define MAO_AI_PLAYER_H

#include <vector>
#include "../game/card/ImmutableCard.h"
#include "../game/act/Action.h"

/**
 * This is an abstract base class for any player.
 */
class Player {
protected:
    std::vector<ImmutableCard*> cards;
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
     * Let the player play a card
     * @return A reference to the card
     */
    virtual ImmutableCard& play() = 0;

    /**
     * Let the player do an action after playing a card
     * @return The action
     */
    virtual Act act() = 0;

    /**
     * Ask the player if he thinks the last played move was incorrect
     * @return `True` if the player wants to correct the last move, `false` otherwise
     */
    virtual bool correctLastMove() = 0;

    /**
     * Let the player draw a card. The card will be added to the player's card collection
     * @param card The drawn card
     */
    void drawCard(ImmutableCard& card);

    /**
     * Check if the player has no cards left
     * @return True` if the player has no cards left, `false` otherwise
     */
    bool hasNoCards();
};


#endif //MAO_AI_PLAYER_H
