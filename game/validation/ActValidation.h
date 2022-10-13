//
// Created by brent on 9/10/22.
//

#ifndef MAO_AI_ACTVALIDATION_H
#define MAO_AI_ACTVALIDATION_H

#include <deque>
#include "../action/Action.h"


void getCorrectActs(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard);

bool compareMultisets(const std::unordered_multiset<Act>& correctActs, const std::unordered_multiset<Act>& acts);

void getActsForDraw(std::unordered_multiset<Act>& acts, const std::deque<Action>& played);

void getActsForCard(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard);

void chnar(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard);

void bong(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard);

void spades(std::unordered_multiset<Act>& acts, const ImmutableCard* newCard);

void pleasantDay(std::unordered_multiset<Act>& acts, const std::deque<Action>& played, const ImmutableCard* newCard);

#endif //MAO_AI_ACTVALIDATION_H
