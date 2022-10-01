//
// Created by brent on 1/10/22.
//

#include "ImmutableCard.h"

ImmutableCard::ImmutableCard(const CardType mType,const CardNumber mNumber) : m_type(mType), m_number(mNumber) {}

CardType ImmutableCard::getCardType() {
    return this->m_type;
}

CardNumber ImmutableCard::getCardNumber() {
    return this->m_number;
}

std::ostream &operator<<(std::ostream &os, const ImmutableCard &ic) {
    return os << "(" << CardNumberToString(ic.m_number) << " of " << CardTypeToString(ic.m_type) << ")";
}
