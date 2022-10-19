//
// Created by brent on 18/10/22.
//

#ifndef MAO_AI_ACTINTERFACE_H
#define MAO_AI_ACTINTERFACE_H


#include "CorrectionAccepter.h"

class ActInterface : public CorrectionAccepter {
public:
    virtual ~ActInterface() = default;
    /**
     * Tell the player all acts that must be performed with this card on this stack.
     * @param played The stack of the game containing the played actions
     * @param played_card The card that this player is about to play
     * @return An unordered_multiset containing the acts.
     */
    virtual const std::unordered_multiset<Act> act(const std::deque<Action>& played, const ImmutableCard* played_card) = 0;
};


#endif //MAO_AI_ACTINTERFACE_H
