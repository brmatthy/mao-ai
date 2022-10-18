//
// Created by brent on 15/10/22.
//

#include "bot.h"
#include "../game/validation/PlayValidation.h"
#include "../game/validation/ActValidation.h"

int bot::getGoodCardIndex() {
    std::deque<Action> played = _game->getPlayed();
    const ImmutableCard* lastCard = played.at(getTopCardReversedIndex(played)).getCard();
    for(int i = 0; i < _cards.size(); i++){
        if(playedCorrectCard(lastCard, _cards.at(i))){
            return i;
        }
    }
    return -1;
}


const ImmutableCard *bot::play() {
    int i = getGoodCardIndex();
    const ImmutableCard* card;
    if(i == -1){ // should not occure
        // use last el as default
        i += _cards.size();
    }
    card = _cards.at(i);
    _cards.erase(_cards.begin() + i);
    return card;
}

const std::unordered_multiset<Act> bot::act(const std::deque<Action> &played, const ImmutableCard *played_card) {
    std::unordered_multiset<Act> acts;
    getCorrectActs(acts, played, played_card);
    return acts;
}

bool bot::myTurn() {
    return _game->isAtTurn(this);
}

bool bot::wantsCard() {
    return getGoodCardIndex() == -1;
}

void bot::acceptCorrection(const Correction &correction) {
    // bot is always correct
}


