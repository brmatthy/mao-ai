//
// Created by brent on 7/12/22.
//

#ifndef MAO_AI_COMBINEDQPLAYAI_H
#define MAO_AI_COMBINEDQPLAYAI_H

#include "StateActPredictQPlayAI.h"

class CombinedQPlayAI: public StateActPredictQPlayAI {
private:
    double _dmax = 1000;
    double _dmin = -1000;
protected:
    void generalUpdate(double reward) override;
public:
    CombinedQPlayAI(double alpha);
};


#endif //MAO_AI_COMBINEDQPLAYAI_H
