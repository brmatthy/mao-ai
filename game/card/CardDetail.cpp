//
// Created by brent on 1/10/22.
//

#include "CardDetail.h"
#include <iostream>

const char* CardTypeToString(CardType ct){
    switch(ct){
        case CardType::HEARTS: return "♥";
        case CardType::CLOVERS: return "♣";
        case CardType::DIAMONDS: return "♦";
        case CardType::SPADES: return "♠";
        default: throw std::invalid_argument("No such card type");
    }
}

Act toAct(CardType ct){
    switch(ct){
        case CardType::HEARTS: return Act::HEARTS;
        case CardType::CLOVERS: return Act::CLOVERS;
        case CardType::DIAMONDS: return Act::DIAMONDS;
        case CardType::SPADES: return Act::SPADES;
        default: throw std::invalid_argument("No such card type");
    }
}

const char* CardNumberToString(CardNumber cn){
    switch(cn){
        case CardNumber::ACE: return "1";
        case CardNumber::TWO: return "2";
        case CardNumber::THREE: return "3";
        case CardNumber::FOUR: return "4";
        case CardNumber::FIVE: return "5";
        case CardNumber::SIX: return "6";
        case CardNumber::SEVEN: return "7";
        case CardNumber::EIGHT: return "8";
        case CardNumber::NINE: return "9";
        case CardNumber::TEN: return "10";
        case CardNumber::JACK: return "J";
        case CardNumber::QUEEN: return "Q";
        case CardNumber::KING: return "K";
        default: throw std::invalid_argument("No such card number");
    }
}

Act toAct(CardNumber cn){
    switch(cn){
        case CardNumber::ACE: return Act::ACE;
        case CardNumber::TWO: return Act::TWO;
        case CardNumber::THREE: return Act::THREE;
        case CardNumber::FOUR: return Act::FOUR;
        case CardNumber::FIVE: return Act::FIVE;
        case CardNumber::SIX: return Act::SIX;
        case CardNumber::SEVEN: return Act::SEVEN;
        case CardNumber::EIGHT: return Act::EIGHT;
        case CardNumber::NINE: return Act::NINE;
        case CardNumber::TEN: return Act::TEN;
        case CardNumber::JACK: return Act::JACK;
        case CardNumber::QUEEN: return Act::QUEEN;
        case CardNumber::KING: return Act::KING;
        default: throw std::invalid_argument("No such card number");
    }
}