//
// Created by brent on 9/11/22.
//

#include "ActPredictQPlayAI.h"

void ActPredictQPlayAI::generalUpdate(double reward) {
    CardType actType = _lastAct.getCardType();
    CardNumber actNumber = _lastAct.getCardNumber();

    // update all acts with same type
    for(CardNumber an: EnumToVector::getCardNumberVector()){
        _qmodel.valueUpdate(_lastState, ImmutableCard(actType, an), reward);
    }

    // update all acts with same number
    for(CardType at: EnumToVector::getCardTypeVector()){
        _qmodel.valueUpdate(_lastState, ImmutableCard(at, actNumber), reward);
    }
}

ActPredictQPlayAI::ActPredictQPlayAI(double alpha) : StateActPredictQPlayAI(alpha) {

}
