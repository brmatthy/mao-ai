//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_ACTION_H
#define MAO_AI_ACTION_H

#include "../card/ImmutableCard.h"
#include "../../player/Player.h"
#include "Act.h"


class Player;


/**
 * Class that represents an action. Takes a card, but is not responsible for the deletion of the card
 */
class Action {
private:
    /**
     * Pointer to the card played in this action, this should be nullptr if no card was played.
     */
    const ImmutableCard* _card;
    /**
     * The action of the action.
     */
    Act _act;
    /**
     * The player who did this action
     */
     const Player* _player;

public:
    Action(const ImmutableCard* card, Act act, const Player* player);

    /**
     * Get a reference to the card
     * @return A reference to the card
     */
    const ImmutableCard* getCard() const;

    /**
     * Get the action
     * @return the action
     */
    Act getAct() const;

    /**
     * Get a reference to the player
     * @return A reference to the player
     */
    const Player* getPlayer() const;

};


#endif //MAO_AI_ACTION_H
