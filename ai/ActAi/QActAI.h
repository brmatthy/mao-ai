//
// Created by brent on 20/10/22.
//

#ifndef MAO_AI_QACTAI_H
#define MAO_AI_QACTAI_H


#include "../../player/interfaces/ActInterface.h"
#include "../q_learning/Qmodel.h"

class QActAI : public ActInterface {
private:

public:
    const std::unordered_set<Act> act(const std::deque<Action> &played, const ImmutableCard *played_card) override;

    void acceptCorrection(CorrectionStatus status) override;
};





#endif //MAO_AI_QACTAI_H
