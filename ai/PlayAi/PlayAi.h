//
// Created by brent on 4/11/22.
//

#ifndef MAO_AI_PLAYAI_H
#define MAO_AI_PLAYAI_H


#include "../util/Ai.h"
#include "../../player/interfaces/PlayInterface.h"

class PlayAi : public PlayInterface, public Ai{
public:
    void acceptCorrection(CorrectionStatus status) override = 0;

    int play(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) override = 0;

    bool wantsCard(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) override = 0;

};


#endif //MAO_AI_PLAYAI_H
