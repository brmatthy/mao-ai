//
// Created by brent on 1/10/22.
//

#include <unordered_set>
#include "Action.h"


Action::Action(const ImmutableCard* card, const std::unordered_set<Act> acts, const Player* player) : _acts(acts), _card(card), _player(player) {}

const ImmutableCard* Action::getCard() const {
    return _card;
}

const std::unordered_set<Act>& Action::getAct() const{
    return _acts;
}

const Player* Action::getPlayer() const{
    return _player;
}







