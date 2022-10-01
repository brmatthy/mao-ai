//
// Created by brent on 1/10/22.
//

#include "Action.h"


Action::Action(ImmutableCard& card_ptr, const Act act) : act(act) {
    if(act != DRAW_CARD){
        this->card = &card_ptr;
    }
}

ImmutableCard& Action::getCard() {
    return *this->card;
}

Act Action::getAct() {
    return act;
}


