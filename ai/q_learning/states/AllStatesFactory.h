//
// Created by brent on 23/10/22.
//

#ifndef MAO_AI_ALLSTATESFACTORY_H
#define MAO_AI_ALLSTATESFACTORY_H

#include <vector>
#include "NCards.h"

std::vector<NCards> getAllNCards(int n);

std::vector<NCards> getAllNCardsNotNull(int n);

void addKLengthRec(std::vector<NCards>& states,
                   std::vector<ImmutableCard>& cardset,
                   std::vector<ImmutableCard>& prefix, int n);

#endif //MAO_AI_ALLSTATESFACTORY_H
