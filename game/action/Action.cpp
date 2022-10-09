//
// Created by brent on 1/10/22.
//

#include "Action.h"


Action::Action(const ImmutableCard* card, Act act, const Player* player) : _act(act) {
    if(act != DRAW_CARD){
        _card = card;
    }
    _player = player;
}

const ImmutableCard* Action::getCard() const {
    return _card;
}

Act Action::getAct() const{
    return _act;
}

const Player* Action::getPlayer() const{
    return _player;
}







