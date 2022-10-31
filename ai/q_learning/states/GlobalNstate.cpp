//
// Created by brent on 23/10/22.
//
/*
#include "GlobalNstate.h"

bool GlobalNstate::operator==(const GlobalNstate &rhs) const {
    return static_cast<const NCards &>(*this) == static_cast<const NCards &>(rhs) &&
           _lastTurn == rhs._lastTurn;
}

bool GlobalNstate::operator!=(const GlobalNstate &rhs) const {
    return !(rhs == *this);
}

GlobalNstate::GlobalNstate(const std::vector<const ImmutableCard *> &cards, bool lastTurn) : NCards(cards),
_lastTurn(lastTurn) {}

std::ostream &operator<<(std::ostream &os, const GlobalNstate &nstate) {
    os << "{" << nstate._lastTurn << ", "<< static_cast<const NCards &>(nstate) << "}" << std::endl;
    return os;
}

*/