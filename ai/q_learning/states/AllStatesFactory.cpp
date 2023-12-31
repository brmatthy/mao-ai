//
// Created by brent on 23/10/22.
//

#include "AllStatesFactory.h"
#include "../../../util/EnumToVector.h"

std::vector<NCards> getAllNCards(int n){
    std::vector<NCards> states = getAllNCardsNotNull(n);
    ImmutableCard noneCard = ImmutableCard(CardType::NONE, CardNumber::NONE);
    for(int i = 1; i < n; i ++){
        std::vector<NCards> extraStates = getAllNCardsNotNull(n - i);
        for(int j = 0; j < i; j++){
            for(NCards& state: extraStates){
                state.addBottomCard(&noneCard);
            }
        }
        for(const NCards& state: extraStates){
            states.push_back(state);
        }
    }
    return states;
}

std::vector<NCards> getAllNCardsNotNull(int n){
    std::vector<NCards> states;
    std::vector<ImmutableCard> cardset;
    for(CardType type : EnumToVector::getCardTypeVector()){
        for(CardNumber number : EnumToVector::getCardNumberVector()){
            cardset.emplace_back(type, number);
        }
    }
    cardset.emplace_back(CardType::NONE, CardNumber::NONE);
    std::vector<ImmutableCard> prefix;
    addKLengthRec(states, cardset, prefix, n);
    return states;
}

// found at https://www.geeksforgeeks.org/print-all-combinations-of-given-length/
void addKLengthRec(std::vector<NCards>& states,
                   std::vector<ImmutableCard>& cardset,
                   std::vector<ImmutableCard>& prefix, int n){
    // Base case: k is 0,
    // print prefix
    if (n == 0){

        NCards state = NCards({});
        for(const ImmutableCard& card: prefix){
            state.addCard(&card);
        }
        states.push_back(state);
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
