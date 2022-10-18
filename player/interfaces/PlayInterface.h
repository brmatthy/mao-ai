//
// Created by brent on 18/10/22.
//

#ifndef MAO_AI_PLAYINTERFACE_H
#define MAO_AI_PLAYINTERFACE_H


#include "../../game/validation/Correction.h"
class Correction;

class PlayInterface {
public:
    /**
     * Suggest a card to play. This function will only be called when wantsCard() is `false`
     * @param playerCards The cards to choose from
     * @param played The stack of the game containing the played actions
     * @return The index of the suggested card
     */
    virtual int play(const std::deque<Action>& played, std::vector<const ImmutableCard*>& playerCards) = 0;

    /**
     * Ask the player if he wants to draw a card
     * @param playerCards The cards to choose from
     * @param played The stack of the game containing the played actions
     * @return `True` if the player wants to draw a card, `false` otherwise
     */
    virtual bool wantsCard(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) = 0;

    /**
     * Handle the correction that the player received, this may or may not be useful
     * @param correction The Correction
     */
    virtual void acceptCorrection(const Correction &correction) = 0;
};


#endif //MAO_AI_PLAYINTERFACE_H
