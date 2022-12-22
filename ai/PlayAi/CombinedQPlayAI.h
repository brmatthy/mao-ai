//
// Created by brent on 7/12/22.
//

#ifndef MAO_AI_COMBINEDQPLAYAI_H
#define MAO_AI_COMBINEDQPLAYAI_H

#include "StateActPredictQPlayAI.h"

class CombinedQPlayAI: public StateActPredictQPlayAI {
private:
    Qmodel<ImmutableCard, ImmutableCard> _remberModel;

protected:
    void generalUpdate(double reward) override;
public:
    CombinedQPlayAI(double alpha);

    bool check(const ImmutableCard &state, const ImmutableCard &action) override;
};


#endif //MAO_AI_COMBINEDQPLAYAI_H
