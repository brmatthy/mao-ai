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