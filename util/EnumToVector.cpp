//
// Created by brent on 20/10/22.
//

#include "EnumToVector.h"

const std::vector<Act> &EnumToVector::getActVector() {
    return _actVector;
}

const std::vector<CardType> &EnumToVector::getCardTypeVector() {
    return _cardTypeVector;
}

const std::vector<CardNumber> &EnumToVector::getCardNumberVector() {
    return _cardNumberVector;
}

const std::vector<Act> EnumToVector::_actVector({
    Act::CHNAR,
    Act::BONG,
    Act::BONG_2,
    Act::BONG_3,
    Act::BONG_4,
    Act::HAVE_A_PLEASANT_DAY,
    Act::THANK_YOU,
    Act::MAO,
    Act::WAVE,
    Act::HEARTS,
    Act::CLOVERS,
    Act::DIAMONDS,
    Act::SPADES,
    Act::ACE,
    Act::TWO,
    Act::THREE,
    Act::FOUR,
    Act::FIVE,
    Act::SIX,
    Act::SEVEN,
    Act::EIGHT,
    Act::NINE,
    Act::TEN,
    Act::JACK,
    Act::QUEEN,
    Act::KING,
    Act::LONG_LIVE_THE_QUEEN,
    Act::LONG_LIVE_THE_QUEEN_2,
    Act::LONG_LIVE_THE_QUEEN_3,
    Act::LONG_LIVE_THE_QUEEN_4,
    Act::LONG_LIVE_THE_KING,
    Act::LONG_LIVE_THE_KING_2,
    Act::LONG_LIVE_THE_KING_3,
    Act::LONG_LIVE_THE_KING_4,
});

const std::vector<CardType> EnumToVector::_cardTypeVector({
    CardType::HEARTS,
    CardType::CLOVERS,
    CardType::DIAMONDS,
    CardType::SPADES
});

const std::vector<CardNumber> EnumToVector::_cardNumberVector({
    CardNumber::ACE,
    CardNumber::TWO,
    CardNumber::THREE,
    CardNumber::FOUR,
    CardNumber::FIVE,
    CardNumber::SIX,
    CardNumber::SEVEN,
    CardNumber::EIGHT,
    CardNumber::NINE,
    CardNumber::TEN,
    CardNumber::JACK,
    CardNumber::QUEEN,
    CardNumber::KING
});