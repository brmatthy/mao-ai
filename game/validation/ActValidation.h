//
// Created by brent on 9/10/22.
//

#ifndef MAO_AI_ACTVALIDATION_H
#define MAO_AI_ACTVALIDATION_H

#include <vector>
#include <unordered_set>
#include "../action/Action.h"

bool performedCorrectAct(const std::vector<Action>& played, const Action& action);

std::unordered_set<Act> getActsForCard(const std::vector<Action>& played, const ImmutableCard* newCard);

void chnar(std::unordered_set<Act>& acts, const std::vector<Action>& played, const ImmutableCard* newCard);

void bong(std::unordered_set<Act>& acts, const std::vector<Action>& played, const ImmutableCard* newCard);

#endif //MAO_AI_ACTVALIDATION_H
