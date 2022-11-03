//
// Created by brent on 22/10/22.
//

#include <stdexcept>
#include "Act.h"

CorrectionStatus toCorrectionStatus(Act act){
    switch(act){
        case Act::GNARR: return CorrectionStatus::CHNAR;
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

const char* actToString(Act act){
    switch(act){
        case Act::GNARR: return "CHNAR";
        case Act::BONG: return "BONG";
        case Act::BONG_2: return "BONG_2";
        case Act::BONG_3: return "BONG_3";
        case Act::BONG_4: return "BONG_4";
        case Act::HAVE_A_PLEASANT_DAY: return "HAVE_A_PLEASANT_DAY";
        case Act::THANK_YOU: return "THANK_YOU";
        case Act::MAO: return "MAO";
        case Act::WAVE: return "WAVE";
        case Act::HEARTS: return "HEARTS";
        case Act::CLOVERS: return "CLOVERS";
        case Act::DIAMONDS: return "DIAMONDS";
        case Act::SPADES: return "SPADES";
        case Act::ACE: return "ACE";
        case Act::TWO: return "TWO";
        case Act::THREE: return "THREE";
        case Act::FOUR: return "FOUR";
        case Act::FIVE: return "FIVE";
        case Act::SIX: return "SIX";
        case Act::SEVEN: return "SEVEN";
        case Act::EIGHT: return "EIGHT";
        case Act::NINE: return "NINE";
        case Act::TEN: return "TEN";
        case Act::JACK: return "JACK";
        case Act::QUEEN: return "QUEEN";
        case Act::KING: return "KING";
        case Act::LONG_LIVE_THE_QUEEN: return "LONG_LIVE_THE_QUEEN";
        case Act::LONG_LIVE_THE_QUEEN_2: return "LONG_LIVE_THE_QUEEN_2";
        case Act::LONG_LIVE_THE_QUEEN_3: return "LONG_LIVE_THE_QUEEN_3";
        case Act::LONG_LIVE_THE_QUEEN_4: return "LONG_LIVE_THE_QUEEN_4";
        case Act::LONG_LIVE_THE_KING: return "LONG_LIVE_THE_KING";
        case Act::LONG_LIVE_THE_KING_2: return "LONG_LIVE_THE_KING_2";
        case Act::LONG_LIVE_THE_KING_3: return "LONG_LIVE_THE_KING_3";
        case Act::LONG_LIVE_THE_KING_4: return "LONG_LIVE_THE_KING_4";
        default: throw std::invalid_argument("No such Act");
    }
}

Act toAct(CorrectionStatus status){
    switch(status){
        case CorrectionStatus::CHNAR: return Act::GNARR;
        case CorrectionStatus::BONG: return Act::BONG;
        case CorrectionStatus::BONG_2: return Act::BONG_2;
        case CorrectionStatus::BONG_3: return Act::BONG_3;
        case CorrectionStatus::BONG_4: return Act::BONG_4;
        case CorrectionStatus::HAVE_A_PLEASANT_DAY: return Act::HAVE_A_PLEASANT_DAY;
        case CorrectionStatus::THANK_YOU: return Act::THANK_YOU;
        case CorrectionStatus::MAO: return Act::MAO;
        case CorrectionStatus::WAVE: return Act::WAVE;
        case CorrectionStatus::HEARTS: return Act::HEARTS;
        case CorrectionStatus::CLOVERS: return Act::CLOVERS;
        case CorrectionStatus::DIAMONDS: return Act::DIAMONDS;
        case CorrectionStatus::SPADES: return Act::SPADES;
        case CorrectionStatus::ACE: return Act::ACE;
        case CorrectionStatus::TWO: return Act::TWO;
        case CorrectionStatus::THREE: return Act::THREE;
        case CorrectionStatus::FOUR: return Act::FOUR;
        case CorrectionStatus::FIVE: return Act::FIVE;
        case CorrectionStatus::SIX: return Act::SIX;
        case CorrectionStatus::SEVEN: return Act::SEVEN;
        case CorrectionStatus::EIGHT: return Act::EIGHT;
        case CorrectionStatus::NINE: return Act::NINE;
        case CorrectionStatus::TEN: return Act::TEN;
        case CorrectionStatus::JACK: return Act::JACK;
        case CorrectionStatus::QUEEN: return Act::QUEEN;
        case CorrectionStatus::KING: return Act::KING;
        case CorrectionStatus::LONG_LIVE_THE_QUEEN: return Act::LONG_LIVE_THE_QUEEN;
        case CorrectionStatus::LONG_LIVE_THE_QUEEN_2: return Act::LONG_LIVE_THE_QUEEN_2;
        case CorrectionStatus::LONG_LIVE_THE_QUEEN_3: return Act::LONG_LIVE_THE_QUEEN_3;
        case CorrectionStatus::LONG_LIVE_THE_QUEEN_4: return Act::LONG_LIVE_THE_QUEEN_4;
        case CorrectionStatus::LONG_LIVE_THE_KING: return Act::LONG_LIVE_THE_KING;
        case CorrectionStatus::LONG_LIVE_THE_KING_2: return Act::LONG_LIVE_THE_KING_2;
        case CorrectionStatus::LONG_LIVE_THE_KING_3: return Act::LONG_LIVE_THE_KING_3;
        case CorrectionStatus::LONG_LIVE_THE_KING_4: return Act::LONG_LIVE_THE_KING_4;
        default: throw std::invalid_argument("No such Act");
    }
}

