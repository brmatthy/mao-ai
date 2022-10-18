//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_CARDDETAIL_H
#define MAO_AI_CARDDETAIL_H

#include "../action/Act.h"

/**
 * All possible card types
 */
enum CardType{
    HEARTS,
    CLOVERS,
    DIAMONDS,
    SPADES
};

const char* CardTypeToString(CardType ct);

Act toAct(CardType ct);

/**
 * All possible card numbers or figures
 */
enum CardNumber{
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

const char* CardNumberToString(CardNumber cn);

Act toAct(CardNumber ct);

#endif //MAO_AI_CARDDETAIL_H
