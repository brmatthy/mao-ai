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

bool NCards::operator==(const NCards &rhs) const {
    return _types == rhs._types &&
           _numbers == rhs._numbers;
}

bool NCards::operator!=(const NCards &rhs) const {
    return !(rhs == *this);
}
