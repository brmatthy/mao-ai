//
// Created by brent on 3/11/22.
//

#include "QPlayAI.h"

void QPlayAI::acceptCorrection(CorrectionStatus status) {

}

int QPlayAI::play(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) {
    _lastState = *played.at(played.size() - getTopCardReversedIndex(played)).getCard();
    for(int i = 0; i < playerCards.size(); ++i){
        if(_qmodel.doAction(_lastState, *playerCards.at(i))){ // check if you could play the card
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