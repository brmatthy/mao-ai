//
// Created by brent on 20/10/22.
//

#include "QActAI.h"
#include "../q_learning/states/AllStatesFactory.h"
#include "../../util/EnumToVector.h"

QActAI::QActAI(int n, double alpha): _qmodel(Qmodel<GlobalNstate, Act>(getAllGlobalNstate(n), EnumToVector::getActVector(), alpha)), _n(n) {}

const std::unordered_set<Act> QActAI::act(const std::deque<Action> &played, const ImmutableCard *played_card) {
    _lastActs.clear();
    NCards state = NCards(played, played_card, _n);
    for(Act act: _qmodel.getActions()){
        if(_qmodel.doAction(state, act)) _lastActs.insert(act);
    }
    return _lastActs;
}


void QActAI::acceptCorrection(CorrectionStatus status) {

}


