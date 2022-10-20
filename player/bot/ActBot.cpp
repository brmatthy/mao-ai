//
// Created by brent on 18/10/22.
//

#include "ActBot.h"
#include "../../game/validation/ActValidation.h"

const std::unordered_multiset<Act> ActBot::act(const std::deque<Action> &played, const ImmutableCard *played_card) {
    std::unordered_multiset<Act> acts;
    getCorrectActs(acts, played, played_card);
    return acts;
}

void ActBot::acceptCorrection(const Correction &correction) {
    // don't handle corrections, we are always correct
}
