//
// Created by brent on 15/10/22.
//

#include "Bot.h"
#include "../game/validation/PlayValidation.h"
#include "../game/validation/ActValidation.h"

int Bot::getGoodCardIndex() {
    std::deque<Action> played = _game->getPlayed();
    const ImmutableCard* lastCard = played.at(played.size() - getTopCardReversedIndex(played)).getCard();
    for(int i = 0; i < _cards.size(); i++){
        if(playedCorrectCard(lastCard, _cards.at(i))){
            return i;
        }
    }
    return -1;
}


const ImmutableCard *Bot::play() {
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

const std::unordered_multiset<Act> Bot::act(const std::deque<Action> &played, const ImmutableCard *played_card) {
    std::unordered_multiset<Act> acts;
    getCorrectActs(acts, played, played_card);
    return acts;
}

bool Bot::myTurn() {
    return _game->isAtTurn(this);
}

bool Bot::wantsCard() {
    return getGoodCardIndex() == -1;
}

void Bot::acceptCorrection(const Correction &correction) {
    // Bot is always correct
}


