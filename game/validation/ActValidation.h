//
// Created by brent on 9/10/22.
//

#ifndef MAO_AI_ACTVALIDATION_H
#define MAO_AI_ACTVALIDATION_H

#include <deque>
#include "../action/Action.h"

bool performedCorrectAct(const std::deque<Action>& played, const Action& action);

std::unordered_multiset<Act> getActsForDraw(const std::deque<Action>& played);

std::unordered_multiset<Act> getActsForCard(const std::deque<Action>& played, const ImmutableCard* newCard);

void chnar(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard);

void bong(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard);

void spades(std::unordered_multiset<Act>& acts, const ImmutableCard* newCard);

void pleasantDay(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard);

#endif //MAO_AI_ACTVALIDATION_H
