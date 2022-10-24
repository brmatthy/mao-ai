//
// Created by brent on 23/10/22.
//

#include "AllStatesFactory.h"
#include "../../../util/EnumToVector.h"

std::vector<GlobalNstate> getAllGlobalNstate(int n){
    std::vector<GlobalNstate> states = getAllGlobalNstateNotNull(n);
    ImmutableCard noneCard = ImmutableCard(CardType::NONE, CardNumber::NONE);
    for(int i = 1; i < n; i ++){
        std::vector<GlobalNstate> extraStates = getAllGlobalNstateNotNull(n - i);
        for(int j = 0; j < i; j++){
            for(GlobalNstate& state: extraStates){
                state.addBottomCard(&noneCard);
            }
        }
        for(const GlobalNstate& state: extraStates){
            states.push_back(state);
        }
    }
    return states;
}

std::vector<GlobalNstate> getAllGlobalNstateNotNull(int n){
    std::vector<GlobalNstate> states;
    std::vector<ImmutableCard> cardset;
    for(CardType type : EnumToVector::getCardTypeVector()){
        for(CardNumber number : EnumToVector::getCardNumberVector()){
            cardset.emplace_back(type, number);
        }
    }
    std::vector<ImmutableCard> prefix;
    addKLengthRec(states, cardset, prefix, n);
    return states;
}

// found at https://www.geeksforgeeks.org/print-all-combinations-of-given-length/
void addKLengthRec(std::vector<GlobalNstate>& states,
                   std::vector<ImmutableCard>& cardset,
                   std::vector<ImmutableCard>& prefix, int n){
    // Base case: k is 0,
    // print prefix
    if (n == 0){
        for(bool b : {true, false}){
            GlobalNstate state = GlobalNstate({}, b);
            for(const ImmutableCard& card: prefix){
                state.addCard(&card);
            }
            states.push_back(state);
        }
        return;
    }

    // One by one add all characters
    // from set and recursively
    // call for k equals to k-1
    for (const ImmutableCard& card : cardset){
        auto newPrefix = std::vector<ImmutableCard>(prefix);

        // Next character of input added
        newPrefix.push_back(card);

        // k is decreased, because
        // we have added a new character
        addKLengthRec(states, cardset, newPrefix, n - 1);
    }
}
