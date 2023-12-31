//
// Created by brent on 1/10/22.
//

#include "ImmutableCard.h"
#include "../../util/EnumToVector.h"

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

bool ImmutableCard::operator==(const ImmutableCard &rhs) const {
    return _type == rhs._type &&
           _number == rhs._number;
}

bool ImmutableCard::operator!=(const ImmutableCard &rhs) const {
    return !(rhs == *this);
}

std::vector<ImmutableCard> ImmutableCard::getAllCards() {
    std::vector<ImmutableCard> cards = {};
    for(CardType type: EnumToVector::getCardTypeVector()){
        for(CardNumber number: EnumToVector::getCardNumberVector()){
            cards.emplace_back(type, number);
        }
    }
    return cards;
}

ImmutableCard ImmutableCard::getEmptyCard()
{
    return ImmutableCard(CardType::NONE, CardNumber::NONE);
}
