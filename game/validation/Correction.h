//
// Created by brent on 5/10/22.
//

#ifndef MAO_AI_CORRECTION_H
#define MAO_AI_CORRECTION_H


#include "CorrectionStatus.h"
#include "../action/Action.h"

class Correction {
private:

    CorrectionStatus _status;
    const Action* _action;
    std::vector<Act> _correctActs;

public:
    Correction(CorrectionStatus status, const Action* action, std::vector<Act> correctActs);

};


#endif //MAO_AI_CORRECTION_H
