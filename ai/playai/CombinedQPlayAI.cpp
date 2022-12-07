//
// Created by brent on 7/12/22.
//


#include "CombinedQPlayAI.h"

void CombinedQPlayAI::generalUpdate(double reward) {

    CardType actType = _lastAct.getCardType();
    CardNumber actNumber = _lastAct.getCardNumber();

    // update all acts with same type
    for(CardNumber an: EnumToVector::getCardNumberVector()){
        ImmutableCard act = ImmutableCard(actType, an);
        double value = _qmodel.getValue(_lastState, act);
        if(inInterval(value, _dmax - 1, _dmax +1) && inInterval(value, _dmin - 1, _dmin +1)){
            _qmodel.valueUpdate(_lastState, act, reward);
        }
    }

    // update all acts with same number
    for(CardType at: EnumToVector::getCardTypeVector()){
        ImmutableCard act = ImmutableCard(at, actNumber);
        double value = _qmodel.getValue(_lastState, act);
        if(inInterval(value, _dmax - 1, _dmax +1) && inInterval(value, _dmin - 1, _dmin +1)){
            _qmodel.valueUpdate(_lastState, act, reward);
        }
    }

    // we know for shure this state act combination was correct or false, so save it
    _qmodel.setValue(_lastState, _lastAct, reward);
}

CombinedQPlayAI::CombinedQPlayAI(double alpha) : StateActPredictQPlayAI(alpha) {

}
