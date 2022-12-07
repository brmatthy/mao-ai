//
// Created by brent on 20/10/22.
//

#include "QActAI.h"

QActAI::QActAI(int n, double alpha): _qmodel(Qmodel<NCards, Act>(getAllNCards(n), EnumToVector::getActVector(), alpha)), _n(n) {}




const std::unordered_set<Act> QActAI::act(const std::deque<Action> &played, const ImmutableCard *played_card) {
    incrementTurns();
    // tell the qmodel that te remaining acts were good
    for(Act act : _lastActs){
        _qmodel.valueUpdate(_lastState, act, 1.0);
    }
    _lastActs.clear();
    _lastState = NCards(played, played_card, _n);
    for(Act act: _qmodel.getActions()){
        if(_qmodel.doAction(_lastState, act)) _lastActs.insert(act);
    }
    return _lastActs;
}


void QActAI::acceptCorrection(CorrectionStatus status) {
    Act act = toAct(status);
    // only incrementFaults acts will remain
    _lastActs.erase(act);
    _qmodel.valueUpdate(_lastState, act, -1.0);
    incrementFaults();
}




