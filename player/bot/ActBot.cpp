//
// Created by brent on 18/10/22.
//

#include "ActBot.h"
#include "../../game/validation/ActValidation.h"

const std::unordered_set<Act> ActBot::act(const std::deque<Action> &played, const ImmutableCard *played_card) {
    std::unordered_set<Act> acts;
    getCorrectActs(acts, played, played_card);
    return acts;
}

void ActBot::acceptCorrection(CorrectionStatus status) {
    // don't handle corrections, we are always incrementFaults
}
