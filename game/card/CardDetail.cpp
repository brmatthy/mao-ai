//
// Created by brent on 1/10/22.
//

#include "CardDetail.h"
#include <iostream>

const char* CardTypeToString(CardType ct){
    switch(ct){
        case HEARTS: return "♥";
        case CLOVERS: return "♣";
        case DIAMONDS: return "♦";
        case SPADES: return "♠";
        default: throw std::invalid_argument("No such card type");
    }
}

Act toAct(CardType ct){
    switch(ct){
        case HEARTS: return ACT_HEARTS;
        case CLOVERS: return ACT_CLOVERS;
        case DIAMONDS: return ACT_DIAMONDS;
        case SPADES: return ACT_SPADES;
        default: throw std::invalid_argument("No such card type");
    }
}

const char* CardNumberToString(CardNumber cn){
    switch(cn){
        case ACE: return "1";
        case TWO: return "2";
        case THREE: return "3";
        case FOUR: return "4";
        case FIVE: return "5";
        case SIX: return "6";
        case SEVEN: return "7";
        case EIGHT: return "8";
        case NINE: return "9";
        case TEN: return "10";
        case JACK: return "J";
        case QUEEN: return "Q";
        case KING: return "K";
        default: throw std::invalid_argument("No such card number");
    }
}

Act toAct(CardNumber cn){
    switch(cn){
        case ACE: return ACT_ACE;
        case TWO: return ACT_TWO;
        case THREE: return ACT_THREE;
        case FOUR: return ACT_FOUR;
        case FIVE: return ACT_FIVE;
        case SIX: return ACT_SIX;
        case SEVEN: return ACT_SEVEN;
        case EIGHT: return ACT_EIGHT;
        case NINE: return ACT_NINE;
        case TEN: return ACT_TEN;
        case JACK: return ACT_JACK;
        case QUEEN: return ACT_QUEEN;
        case KING: return ACT_KING;
        default: throw std::invalid_argument("No such card number");
    }
}