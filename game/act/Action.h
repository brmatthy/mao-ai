//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_ACTION_H
#define MAO_AI_ACTION_H

#include "../card/ImmutableCard.h"

/**
 * All the possible acts
 */
enum Act{
    NONE,
    DRAW_CARD
};


/**
 * Class that represents an action. Takes a card, but is not responsible for the deletion of the card
 */
class Action {
private:
    /**
     * Pointer to the card played in this action, this should be nullptr if no card was played.
     */
    ImmutableCard* card;
    /**
     * The act of the action.
     */
    Act act;

public:
    Action(ImmutableCard& card_ptr, Act act);

    /**
     * Get a reference to the card
     * @return A reference to the card
     */
    ImmutableCard& getCard();

    /**
     * Get the act
     * @return the act
     */
    Act getAct();


};


#endif //MAO_AI_ACTION_H
