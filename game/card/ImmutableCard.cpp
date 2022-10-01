//
// Created by brent on 1/10/22.
//

#include "ImmutableCard.h"

ImmutableCard::ImmutableCard(const CardType mType,const CardNumber mNumber) : type(mType), number(mNumber) {}

CardType ImmutableCard::getCardType() {
    return this->type;
}

CardNumber ImmutableCard::getCardNumber() {
    return this->number;
}

std::ostream &operator<<(std::ostream &os, const ImmutableCard &ic) {
    return os << "(" << CardNumberToString(ic.number) << " of " << CardTypeToString(ic.type) << ")";
}
