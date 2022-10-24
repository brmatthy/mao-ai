//
// Created by brent on 23/10/22.
//

#include "NCards.h"


NCards::NCards(const std::vector<const ImmutableCard *>& cards) {
    for(const ImmutableCard* card : cards){
        addCard(card);
    }
}

void NCards::addCard(const ImmutableCard* card) {
    _types.push_back(card->getCardType());
    _numbers.push_back(card->getCardNumber());
}

void NCards::addCard(CardType type, CardNumber number) {
    _types.push_back(type);
    _numbers.push_back(number);
}

void NCards::addBottomCard(const ImmutableCard *card) {
    _types.insert(_types.begin(),card->getCardType());
    _numbers.insert(_numbers.begin(),card->getCardNumber());
}

bool NCards::operator==(const NCards &rhs) const {
    return _types == rhs._types &&
           _numbers == rhs._numbers;
}

bool NCards::operator!=(const NCards &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const NCards &cards) {
    os << "[";
    for(int i = 0; i < cards._types.size() - 1; i++){
        os << CardTypeToString(cards._types.at(i)) << CardNumberToString(cards._numbers.at(i)) << ",";
    }
    os << CardTypeToString(cards._types.at(cards._types.size() - 1)) << CardNumberToString(cards._numbers.at(cards._types.size() -1));
    os << "]";
    return os;
}


