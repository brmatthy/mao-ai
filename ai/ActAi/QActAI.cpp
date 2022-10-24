//
// Created by brent on 20/10/22.
//

#include "QActAI.h"
#include "../q_learning/states/AllStatesFactory.h"
#include "../../util/EnumToVector.h"

QActAI::QActAI(int n, double alpha): _qmodel(Qmodel<GlobalNstate, Act>(getAllGlobalNstate(n), EnumToVector::getActVector(), alpha)) {}

const std::unordered_set<Act> QActAI::act(const std::deque<Action> &played, const ImmutableCard *played_card) {
    return std::unordered_set<Act>();
}


void QActAI::acceptCorrection(CorrectionStatus status) {}


