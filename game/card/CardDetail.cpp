//
// Created by brent on 1/10/22.
//

#include "CardDetail.h"
#include <iostream>

const char* CardTypeToString(CardType ct){
    switch(ct){
        case HEARTS: return "Hearts";
        case CLOVERS: return "Clovers";
        case DIAMONDS: return "Diamonds";
        case SPADES: return "Spades";
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
        case ACE: return "Ace";
        case TWO: return "Two";
        case THREE: return "Three";
        case FOUR: return "Four";
        case FIVE: return "Five";
        case SIX: return "Six";
        case SEVEN: return "Seven";
        case EIGHT: return "Eight";
        case NINE: return "Nine";
        case TEN: return "Ten";
        case JACK: return "Jack";
        case QUEEN: return "Queen";
        case KING: return "King";
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