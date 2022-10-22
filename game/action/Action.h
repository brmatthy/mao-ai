//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_ACTION_H
#define MAO_AI_ACTION_H

#include "../card/ImmutableCard.h"
#include "../../player/Player.h"
#include "Act.h"
#include <unordered_set>


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
     * The acts of the action.
     */
    const std::unordered_set<Act> _acts;
    /**
     * The player who did this action
     */
     const Player* _player;

public:
    Action(const ImmutableCard* card, const std::unordered_set<Act> acts, const Player* player);

    /**
     * Get a reference to the card
     * @return A reference to the card
     */
    const ImmutableCard* getCard() const;

    /**
     * Get the action
     * @return the action
     */
    const std::unordered_set<Act>& getAct() const;

    /**
     * Get a reference to the player
     * @return A reference to the player
     */
    const Player* getPlayer() const;

    friend std::ostream& operator<<(std::ostream& os, const Action& action);

};


#endif //MAO_AI_ACTION_H
