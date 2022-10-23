//
// Created by brent on 23/10/22.
//

#ifndef MAO_AI_GLOBALNSTATE_H
#define MAO_AI_GLOBALNSTATE_H


#include "NCards.h"

class GlobalNstate : public NCards{
private:
    bool _lastTurn;

public:
    GlobalNstate(const std::vector<const ImmutableCard *> &cards, bool lastTurn);

    bool operator==(const GlobalNstate &rhs) const;

    bool operator!=(const GlobalNstate &rhs) const;

};


#endif //MAO_AI_GLOBALNSTATE_H
