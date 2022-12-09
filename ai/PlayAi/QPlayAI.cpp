//
// Created by brent on 3/11/22.
//

#include "QPlayAI.h"

QPlayAI::QPlayAI(double alpha) : _qmodel(Qmodel<ImmutableCard, ImmutableCard>(ImmutableCard::getAllCards(),
                                                                  ImmutableCard::getAllCards(),alpha)){}


void QPlayAI::acceptCorrection(CorrectionStatus status) {
    if(status == )
    incrementFaults();
    _qmodel.valueUpdate(_lastState, _lastAct, -5);
    _lastState = ImmutableCard(CardType::NONE, CardNumber::NONE);
}

int QPlayAI::play(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) {
    incrementTurns();
    // reward if last action was correct
    if(ImmutableCard(CardType::NONE, CardNumber::NONE) != _lastState){
        _qmodel.valueUpdate(_lastState, _lastAct, 1);
    }
    _lastState = *played.at(played.size() - getTopCardReversedIndex(played)).getCard();
    for(int i = 0; i < playerCards.size(); ++i){
        _lastAct = *playerCards.at(i);
        if(_qmodel.doAction(_lastState, _lastAct)){ // check if you could play the card
            return i;
        }
    }
    // should never occur
    return 0;
}

bool QPlayAI::wantsCard(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) {
    const ImmutableCard* c_state = played.at(played.size() - getTopCardReversedIndex(played)).getCard();
    for(const ImmutableCard* c_act: playerCards){
        if(_qmodel.doAction(*c_state, *c_act)){ // check if you could play the card
            return false;
        }
    }
    return true;
}

