//
// Created by brent on 1/10/22.
//

#include <unordered_set>
#include "Action.h"


Action::Action(const ImmutableCard* card, const std::unordered_set<Act> acts, const Player* player) :
    _card(card),
    _acts(acts),
    _player(player) {}

const ImmutableCard* Action::getCard() const {
    return _card;
}

const std::unordered_set<Act>& Action::getAct() const{
    return _acts;
}

const Player* Action::getPlayer() const{
    return _player;
}

std::ostream &operator<<(std::ostream &os, const Action &action) {
    const ImmutableCard* card = action._card;
    os << action._player << ": ";
    if(card == nullptr){
        os << "draw" << std::endl;
    }else{
        os << *card << std::endl;
    }
    return os;
}







