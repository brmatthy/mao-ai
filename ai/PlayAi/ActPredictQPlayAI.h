//
// Created by brent on 9/11/22.
//

#ifndef MAO_AI_ACTPREDICTQPLAYAI_H
#define MAO_AI_ACTPREDICTQPLAYAI_H


#include "StateActPredictQPlayAI.h"

class ActPredictQPlayAI: public StateActPredictQPlayAI{
protected:
    void generalUpdate(double reward) override;
public:
    ActPredictQPlayAI(double alpha);
};


#endif //MAO_AI_ACTPREDICTQPLAYAI_H
