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
    if(played.front().getCard()->getCardNumber() == SEVEN){
        acts.insert(ACT_THANK_YOU);
    }
}


void getActsForCard(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard){
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


