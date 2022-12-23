//
// Created by brent on 4/11/22.
//

#include "StateActPredictQPlayAI.h"


StateActPredictQPlayAI::StateActPredictQPlayAI(double alpha): _qmodel(Qmodel<ImmutableCard,ImmutableCard>(
        ImmutableCard::getAllCards(), ImmutableCard::getAllCards(), alpha)) {
}

void StateActPredictQPlayAI::reward() {
    generalUpdate(5);
}

void StateActPredictQPlayAI::punish() {
    generalUpdate(-1);
}

void StateActPredictQPlayAI::generalUpdate(double reward) {
    CardType stateType = _lastState.getCardType();
    CardType actType = _lastAct.getCardType();
    CardNumber stateNumber = _lastState.getCardNumber();
    CardNumber actNumber = _lastAct.getCardNumber();

    // update all type-type
    for(CardNumber sn: EnumToVector::getCardNumberVector()){
        for(CardNumber an: EnumToVector::getCardNumberVector()){
            _qmodel.valueUpdate(ImmutableCard(stateType, sn), ImmutableCard(actType, an),reward);
        }
    }
/*
    // update all type-number
    for(CardNumber sn: EnumToVector::getCardNumberVector()){
        for(CardType at: EnumToVector::getCardTypeVector()){
            _qmodel.valueUpdate(ImmutableCard(stateType, sn), ImmutableCard(at, actNumber),reward);
        }
    }

    // update all number-type
    for(CardType st: EnumToVector::getCardTypeVector()){
        for(CardNumber an: EnumToVector::getCardNumberVector()){
            _qmodel.valueUpdate(ImmutableCard(st, stateNumber), ImmutableCard(actType, an),reward);
        }
    }*/

    // update all number-number
    for(CardType st: EnumToVector::getCardTypeVector()){
        for(CardType at: EnumToVector::getCardTypeVector()){
            _qmodel.valueUpdate(ImmutableCard(st, stateNumber), ImmutableCard(at, actNumber),reward);
        }
    }

}

void StateActPredictQPlayAI::acceptCorrection(CorrectionStatus status) {
    incrementFaults();
    punish();
    _lastState = ImmutableCard(CardType::NONE, CardNumber::NONE);
}

int StateActPredictQPlayAI::play(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) {
    incrementTurns();
    // reward if last action was correct
    if(ImmutableCard(CardType::NONE, CardNumber::NONE) != _lastState){
        reward();
    }
    _lastState = *played.at(played.size() - getTopCardReversedIndex(played)).getCard();
    for(int i = 0; i < playerCards.size(); ++i){
        _lastAct = *playerCards.at(i);
        if(check(_lastState, _lastAct)){ // check if you could play the card
            return i;
        }
    }
    // should never occur
    return 0;
}

bool StateActPredictQPlayAI::wantsCard(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) {
    const ImmutableCard* c_state = played.at(played.size() - getTopCardReversedIndex(played)).getCard();
    for(const ImmutableCard* c_act: playerCards){
        if(check(*c_state, *c_act)){ // check if you could play the card
            return false;
        }
    }
    return true;
}

bool StateActPredictQPlayAI::check(const ImmutableCard &state,const ImmutableCard &action) {
    return _qmodel.doAction(state, action);
}




