//
// Created by brent on 7/12/22.
//

#include "CombinedQPlayAI.h"

CombinedQPlayAI::CombinedQPlayAI(double alpha) :
    StateActPredictQPlayAI(alpha),
    _remberModel(Qmodel<ImmutableCard,ImmutableCard>(ImmutableCard::getAllCards(), ImmutableCard::getAllCards(), alpha)){}

void CombinedQPlayAI::generalUpdate(double reward) {

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

    // remember this exact pair
    _remberModel.setValue(_lastState, _lastAct, reward > 0 ? 100.0 : -100.0);

}

bool CombinedQPlayAI::check(const ImmutableCard &state, const ImmutableCard &action) {
    double remeber_val = _remberModel.getValue(state, action);
    //std::cout << remeber_val << std::endl;
    if(!inInterval(remeber_val, -10.0, 10.0)){
        //std::cout << (remeber_val > 0 ? "True": "False") << std::endl;
        return remeber_val >= 0;
    }
    return _qmodel.doAction(state, action);
}