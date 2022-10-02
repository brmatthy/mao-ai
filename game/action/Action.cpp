//
// Created by brent on 1/10/22.
//

#include "Action.h"


Action::Action(ImmutableCard& card, const Act act, Player* player) : act(act) {
    if(act != DRAW_CARD){
        this->card = &card;
    }
    this->player = player;
}

ImmutableCard& Action::getCard() {
    return *this->card;
}

Act Action::getAct() {
    return act;
}

Player &Action::getPlayer() {
    return *this->player;
}







