//
// Created by brent on 18/10/22.
//

#include "PlayBot.h"
#include "../../game/validation/ActValidation.h"
#include "../../game/validation/PlayValidation.h"


int PlayBot::getGoodCardIndex(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) {
    const ImmutableCard* lastCard = played.at(played.size() - getTopCardReversedIndex(played)).getCard();
    for(int i = 0; i < playerCards.size(); i++){
        if(playedCorrectCard(lastCard, playerCards.at(i))){
            return i;
        }
    }
    return -1;
}

int PlayBot::play(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) {
    int i = getGoodCardIndex(played, playerCards);
    if(i == -1){ // should not occure
        // use last el as default
        i += playerCards.size();
    }
    return i;
}

bool PlayBot::wantsCard(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) {
    return getGoodCardIndex(played, playerCards) == -1;
}

void PlayBot::acceptCorrection(CorrectionStatus status) {
    // always correct
}
