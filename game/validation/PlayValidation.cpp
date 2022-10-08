//
// Created by brent on 7/10/22.
//

#include "PlayValidation.h"

bool playedCorrectCard(const ImmutableCard* lastCard, const ImmutableCard* newCard){
    return lastCard->getCardNumber() == newCard->getCardNumber();
}