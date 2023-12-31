//
// Created by brent on 20/10/22.
//

#ifndef MAO_AI_QACTAI_H
#define MAO_AI_QACTAI_H


#include "../../player/interfaces/ActInterface.h"
#include "../q_learning/Qmodel.h"
#include "../q_learning/states/NCards.h"
#include "../q_learning/states/AllStatesFactory.h"
#include "../../util/EnumToVector.h"
#include "../util/Ai.h"

class QActAI : public ActInterface, public Ai {
private:
    Qmodel<NCards, Act> _qmodel;
    std::unordered_set<Act> _lastActs = {};
    NCards _lastState = NCards({});
    int _n;

public:
    QActAI(int n, double alpha);

    const std::unordered_set<Act> act(const std::deque<Action> &played, const ImmutableCard *played_card) override;

    void acceptCorrection(CorrectionStatus status) override;

};





#endif //MAO_AI_QACTAI_H
