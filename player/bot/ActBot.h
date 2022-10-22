//
// Created by brent on 18/10/22.
//

#ifndef MAO_AI_ACTBOT_H
#define MAO_AI_ACTBOT_H


#include "../interfaces/ActInterface.h"

class ActBot : public ActInterface{
public:
    const std::unordered_set<Act> act(const std::deque<Action> &played, const ImmutableCard *played_card) override;

    void acceptCorrection(const Correction &correction) override;

};


#endif //MAO_AI_ACTBOT_H
