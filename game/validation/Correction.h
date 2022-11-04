//
// Created by brent on 5/10/22.
//

#ifndef MAO_AI_CORRECTION_H
#define MAO_AI_CORRECTION_H


#include "CorrectionStatus.h"
#include "../action/Action.h"

class Action;

class Correction {
private:

    CorrectionStatus _status;
    /**
     * Contains the incrementFaults action. This will only be not nullptr when status is INVALID_ACT
     */
    const Action* _action;

public:
    Correction(CorrectionStatus status, const Action* action);

};


#endif //MAO_AI_CORRECTION_H
