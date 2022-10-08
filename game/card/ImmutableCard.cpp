//
// Created by brent on 1/10/22.
//

#include "ImmutableCard.h"

ImmutableCard::ImmutableCard(CardType mType, CardNumber mNumber) : _type(mType), _number(mNumber) {}

const CardType ImmutableCard::getCardType() {
    return _type;
}

const CardNumber ImmutableCard::getCardNumber() {
    return _number;
}

std::ostream &operator<<(std::ostream &os, const ImmutableCard &ic) {
    return os << "(" << CardNumberToString(ic._number) << " of " << CardTypeToString(ic._type) << ")";
}
