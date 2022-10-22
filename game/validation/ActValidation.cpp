//
// Created by brent on 9/10/22.
//

#include "ActValidation.h"

void getCorrectActs(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
    if(newCard == nullptr){ // draw card
        getActsForDraw(acts, played);
    }else{ // played a card
        getActsForCard(acts, played, newCard);
    }
}

bool compareMultisets(const std::unordered_multiset<Act>& correctActs, const std::unordered_multiset<Act>& acts){
    // verry sad way to check if 2 multisets are equal
    auto notFound = acts.end();
    for(Act act : correctActs){
        if(acts.find(act) == notFound){
            return false;
        }
    }
    notFound = correctActs.end();
    for(Act act : acts){
        if(correctActs.find(act) == notFound){
            return false;
        }
    }
    return true;
}

void getActsForDraw(std::unordered_multiset<Act>& acts, const std::deque<Action>& played){
    if(played.at(played.size() - getTopCardReversedIndex(played)).getCard()->getCardNumber() == CardNumber::SEVEN){
        acts.insert(Act::THANK_YOU);
    }
}


void getActsForCard(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
    // let all the rules say what acts must be performed
    chnar(acts, played, newCard);
    bong(acts, played, newCard);
    spades(acts, newCard);
    pleasantDay(acts, played, newCard);

}

int getTopCardReversedIndex(const std::deque<Action>& played){
    const ImmutableCard* topcard = nullptr;
    int i = 0;
    while (topcard == nullptr){
        i++;
        topcard = played.at(played.size() -i).getCard();
    }
    return i;
}


void chnar(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
    if(newCard->getCardType() == CardType::HEARTS
        || played.at(played.size() - getTopCardReversedIndex(played)).getCard()->getCardType() == CardType::HEARTS){
        acts.insert(Act::CHNAR);
    }
}

void bong(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
    const ImmutableCard* current = newCard;
    for (int i = getTopCardReversedIndex(played); current->getCardNumber() == CardNumber::EIGHT; i++){
        acts.insert(Act::BONG);
        current = played.at(played.size() - i).getCard();
        while (current == nullptr){
            i++;
            current = played.at(played.size() - i).getCard();
        }
    }
}

void spades(std::unordered_multiset<Act>& acts, const ImmutableCard* newCard){
    if(newCard->getCardType() == CardType::SPADES){
        acts.insert(toAct(newCard->getCardNumber()));
        acts.insert(Act::SPADES);
        acts.insert(toAct(newCard->getCardNumber()));
    }
}

void pleasantDay(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
    if(newCard->getCardNumber() == CardNumber::SEVEN){
        acts.insert(Act::HAVE_A_PLEASANT_DAY);
    }
    const ImmutableCard* card = played.back().getCard();
    if(card != nullptr && card->getCardNumber() == CardNumber::SEVEN){
        acts.insert(Act::THANK_YOU);
    }
}


