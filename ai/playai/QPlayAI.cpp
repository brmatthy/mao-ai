//
// Created by brent on 3/11/22.
//

#include "QPlayAI.h"

void QPlayAI::acceptCorrection(CorrectionStatus status) {
    incrementFaults();
    _qmodel.valueUpdate(_lastState, _lastAct, -6);
}

int QPlayAI::play(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) {
    _qmodel.valueUpdate(_lastState, _lastAct, 1);
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

