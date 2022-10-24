//
// Created by brent on 23/10/22.
//

#ifndef MAO_AI_ALLSTATESFACTORY_H
#define MAO_AI_ALLSTATESFACTORY_H

#include <vector>
#include "GlobalNstate.h"

std::vector<GlobalNstate> getAllGlobalNstate(int n);

std::vector<GlobalNstate> getAllGlobalNstateNotNull(int n);

void addKLengthRec(std::vector<GlobalNstate>& states,
                   std::vector<ImmutableCard>& cardset,
                   std::vector<ImmutableCard>& prefix, int n);

#endif //MAO_AI_ALLSTATESFACTORY_H
