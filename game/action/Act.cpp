//
// Created by brent on 22/10/22.
//

#include <stdexcept>
#include "Act.h"

CorrectionStatus toCorrectionStatus(Act act){
    switch(act){
        case Act::CHNAR: return CorrectionStatus::CHNAR;
        case Act::BONG: return CorrectionStatus::BONG;
        case Act::BONG_2: return CorrectionStatus::BONG_2;
        case Act::BONG_3: return CorrectionStatus::BONG_3;
        case Act::BONG_4: return CorrectionStatus::BONG_4;
        case Act::HAVE_A_PLEASANT_DAY: return CorrectionStatus::HAVE_A_PLEASANT_DAY;
        case Act::THANK_YOU: return CorrectionStatus::THANK_YOU;
        case Act::MAO: return CorrectionStatus::MAO;
        case Act::WAVE: return CorrectionStatus::WAVE;
        case Act::HEARTS: return CorrectionStatus::HEARTS;
        case Act::CLOVERS: return CorrectionStatus::CLOVERS;
        case Act::DIAMONDS: return CorrectionStatus::DIAMONDS;
        case Act::SPADES: return CorrectionStatus::SPADES;
        case Act::ACE: return CorrectionStatus::ACE;
        case Act::TWO: return CorrectionStatus::TWO;
        case Act::THREE: return CorrectionStatus::THREE;
        case Act::FOUR: return CorrectionStatus::FOUR;
        case Act::FIVE: return CorrectionStatus::FIVE;
        case Act::SIX: return CorrectionStatus::SIX;
        case Act::SEVEN: return CorrectionStatus::SEVEN;
        case Act::EIGHT: return CorrectionStatus::EIGHT;
        case Act::NINE: return CorrectionStatus::NINE;
        case Act::TEN: return CorrectionStatus::TEN;
        case Act::JACK: return CorrectionStatus::JACK;
        case Act::QUEEN: return CorrectionStatus::QUEEN;
        case Act::KING: return CorrectionStatus::KING;
        case Act::LONG_LIVE_THE_QUEEN: return CorrectionStatus::LONG_LIVE_THE_QUEEN;
        case Act::LONG_LIVE_THE_QUEEN_2: return CorrectionStatus::LONG_LIVE_THE_QUEEN_2;
        case Act::LONG_LIVE_THE_QUEEN_3: return CorrectionStatus::LONG_LIVE_THE_QUEEN_3;
        case Act::LONG_LIVE_THE_QUEEN_4: return CorrectionStatus::LONG_LIVE_THE_QUEEN_4;
        case Act::LONG_LIVE_THE_KING: return CorrectionStatus::LONG_LIVE_THE_KING;
        case Act::LONG_LIVE_THE_KING_2: return CorrectionStatus::LONG_LIVE_THE_KING_2;
        case Act::LONG_LIVE_THE_KING_3: return CorrectionStatus::LONG_LIVE_THE_KING_3;
        case Act::LONG_LIVE_THE_KING_4: return CorrectionStatus::LONG_LIVE_THE_KING_4;
        default: throw std::invalid_argument("No such Act");
    }
}
