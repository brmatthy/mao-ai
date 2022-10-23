//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_ACT_H
#define MAO_AI_ACT_H


#include "../validation/CorrectionStatus.h"

/**
 * All the possible acts
 */
enum class Act{
    CHNAR,

    BONG,
    BONG_2,
    BONG_3,
    BONG_4,

    HAVE_A_PLEASANT_DAY,
    THANK_YOU,

    MAO,

    WAVE,

    HEARTS,
    CLOVERS,
    DIAMONDS,
    SPADES,

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
    KING,

    LONG_LIVE_THE_QUEEN,
    LONG_LIVE_THE_QUEEN_2,
    LONG_LIVE_THE_QUEEN_3,
    LONG_LIVE_THE_QUEEN_4,

    LONG_LIVE_THE_KING,
    LONG_LIVE_THE_KING_2,
    LONG_LIVE_THE_KING_3,
    LONG_LIVE_THE_KING_4,
};

CorrectionStatus toCorrectionStatus(Act act);



#endif //MAO_AI_ACT_H
