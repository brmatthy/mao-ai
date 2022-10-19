//
// Created by brent on 1/10/22.
//

#include "ImmutableCard.h"

ImmutableCard::ImmutableCard(CardType mType, CardNumber mNumber) : _type(mType), _number(mNumber) {}

CardType ImmutableCard::getCardType() const {
    return _type;
}

CardNumber ImmutableCard::getCardNumber() const{
    return _number;
}

std::ostream &operator<<(std::ostream &os, const ImmutableCard &ic) {
    return os << CardTypeToString(ic._type) << CardNumberToString(ic._number);
}
