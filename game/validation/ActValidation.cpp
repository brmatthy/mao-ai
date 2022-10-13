//
// Created by brent on 9/10/22.
//

#include "ActValidation.h"

bool performedCorrectAct(const std::deque<Action>& played, const Action& action){
    if(action.getCard() == nullptr){ // draw card

    }else{ // played a card

    }

}

std::unordered_multiset<Act> getActsForDraw(const std::deque<Action>& played){
    std::unordered_multiset<Act> acts;
    if(played.front().getCard()->getCardNumber() == SEVEN){
        acts.insert(ACT_THANK_YOU);
    }
    return acts;
}


std::unordered_multiset<Act> getActsForCard(const std::deque<Action>& played, const ImmutableCard* newCard){
    std::unordered_multiset<Act> acts;

    // let all the rules say what acts must be performed
    chnar(acts, played, newCard);
    bong(acts, played, newCard);
    spades(acts, newCard);
    pleasantDay(acts, played, newCard);

}


void chnar(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
    if(newCard->getCardType() == HEARTS || played.at(played.size() - 1).getCard()->getCardType() == HEARTS){
        acts.insert(ACT_CHNAR);
    }
}

void bong(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
    const ImmutableCard* current = newCard;
    for (int i = 0; current->getCardNumber() == EIGHT; i++){
        acts.insert(ACT_BONG);
        current = played.at(played.size() - i).getCard();
    }
}

void spades(std::unordered_multiset<Act>& acts, const ImmutableCard* newCard){
    if(newCard->getCardType() == SPADES){
        acts.insert(toAct(newCard->getCardNumber()));
        acts.insert(ACT_SPADES);
        acts.insert(toAct(newCard->getCardNumber()));
    }
}

void pleasantDay(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
    if(newCard->getCardNumber() == SEVEN){
        acts.insert(ACT_HAVE_A_PLEASANT_DAY);
    }
    if(played.at(played.size() - 1).getCard()->getCardNumber() == SEVEN){
        acts.insert(ACT_THANK_YOU);
    }
}


