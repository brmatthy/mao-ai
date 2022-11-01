//
// Created by brent on 7/10/22.
//

#ifndef MAO_AI_PLAYVALIDATION_H
#define MAO_AI_PLAYVALIDATION_H

#include "../card/ImmutableCard.h"

bool playedCorrectCard(const ImmutableCard* lastCard, const ImmutableCard* newCard);

#endif //MAO_AI_PLAYVALIDATION_H
