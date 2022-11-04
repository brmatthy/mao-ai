//
// Created by brent on 9/10/22.
//

#include <algorithm>
#include "ActValidation.h"

void getCorrectActs(std::unordered_set<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
    if(newCard == nullptr){ // draw card
        getActsForDraw(acts, played);
    }else{ // played a card
        getActsForCard(acts, played, newCard);
    }
}


const std::unordered_set<CorrectionStatus> compareMultisets(const std::unordered_set<Act>& correctActs, const std::unordered_set<Act>& acts){
    std::unordered_set<CorrectionStatus> faults;
    auto notFound = acts.end();
    for(Act act : correctActs){
        if(acts.find(act) == notFound){
            faults.insert(toCorrectionStatus(act));
        }
    }
    notFound = correctActs.end();
    for(Act act : acts){
        if(correctActs.find(act) == notFound){
            faults.insert(toCorrectionStatus(act));
        }
    }
    return faults;
}

void getActsForDraw(std::unordered_set<Act>& acts, const std::deque<Action>& played){
    if(played.at(played.size() - getTopCardReversedIndex(played)).getCard()->getCardNumber() == CardNumber::SEVEN){
        acts.insert(Act::THANK_YOU);
    }
}


void getActsForCard(std::unordered_set<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
    // let all the rules say what acts must be performed
    gnarr(acts, played, newCard);
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


void gnarr(std::unordered_set<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
    if(newCard->getCardType() == CardType::HEARTS
        || played.at(played.size() - getTopCardReversedIndex(played)).getCard()->getCardType() == CardType::HEARTS){
        acts.insert(Act::GNARR);
    }
}

void bong(std::unordered_set<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
    const ImmutableCard* current = newCard;
    short bongNumebr = 0;
    for (int i = getTopCardReversedIndex(played); i <= played.size() && current->getCardNumber() == CardNumber::EIGHT; i++){
        bongNumebr++;
        current = played.at(played.size() - i).getCard();
        while (current == nullptr && i <= played.size()){
            i++;
            current = played.at(played.size() - i).getCard();
        }
    }
    switch (bongNumebr) {
        case 1: acts.insert(Act::BONG);
        case 2: acts.insert(Act::BONG_2);
        case 3: acts.insert(Act::BONG_3);
        case 4: acts.insert(Act::BONG_4);
        default: ;
    }
}

void spades(std::unordered_set<Act>& acts, const ImmutableCard* newCard){
    if(newCard->getCardType() == CardType::SPADES){
        acts.insert(toAct(newCard->getCardNumber()));
        acts.insert(Act::SPADES);
        acts.insert(toAct(newCard->getCardNumber()));
    }
}

void pleasantDay(std::unordered_set<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
    if(newCard->getCardNumber() == CardNumber::SEVEN){
        acts.insert(Act::HAVE_A_PLEASANT_DAY);
    }
    const ImmutableCard* card = played.back().getCard();
    if(card != nullptr && card->getCardNumber() == CardNumber::SEVEN){
        acts.insert(Act::THANK_YOU);
    }
}


