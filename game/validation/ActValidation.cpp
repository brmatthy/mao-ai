//
// Created by brent on 9/10/22.
//

#include "ActValidation.h"

bool performedCorrectAct(const std::vector<Action>& played, const Action& action){

}

std::unordered_set<Act> getActsForCard(const std::vector<Action>& played, const ImmutableCard* newCard){
    std::unordered_set<Act> acts;

    // let all the rules say what acts must be performed
    chnar(acts, played, newCard);
    bong(acts, played, newCard);

}


void chnar(std::unordered_set<Act>& acts, const std::vector<Action>& played, const ImmutableCard* newCard){
    if(newCard->getCardType() == HEARTS || played.at(played.size() - 1).getCard()->getCardType() == HEARTS){
        acts.insert(CHNAR);
    }
}

void bong(std::unordered_set<Act>& acts, const std::vector<Action>& played, const ImmutableCard* newCard){
    const ImmutableCard* current = newCard;
    for (int i = 0; current->getCardNumber() == EIGHT; i++){
        acts.insert(BONG);
        current = played.at(played.size() - i).getCard();
    }
}



