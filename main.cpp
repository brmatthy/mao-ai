//
// Created by brent on 1/10/22.
//



#include <iostream>
#include "game/card/CardDetail.h"
#include <algorithm>
#include <random>
#include <deque>
#include "game/card/ImmutableCard.h"

int main(){
    //create
    std::deque<const ImmutableCard*> cards;
    for(int typeInt = HEARTS; typeInt < SPADES + 1; typeInt++){
        CardType type = static_cast<CardType>(typeInt);
        for(int numberInt = ACE; numberInt < KING + 1; numberInt++){
            CardNumber number = static_cast<CardNumber>(numberInt);
            const ImmutableCard* card = new ImmutableCard(type, number);
            cards.push_back(card);
        }
    }
    //print
    for(const ImmutableCard* card : cards){
        std::cout << *card;
    }
    std::cout << std::endl;

    //shuffle
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(),g);

    //print
    for(const ImmutableCard* card : cards){
        std::cout << *card;
    }

    //delete
    for(const ImmutableCard* card : cards){
        delete card;
    }
}