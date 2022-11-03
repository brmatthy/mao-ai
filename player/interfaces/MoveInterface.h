//
// Created by brent on 18/10/22.
//

#ifndef MAO_AI_MOVEINTERFACE_H
#define MAO_AI_MOVEINTERFACE_H


#include "CorrectionAccepter.h"

class MoveInterface : public CorrectionAccepter {
public:
    virtual ~MoveInterface() = default;
    /**
     * Returns whether or not the player is at turn according to the mover
     * @return `true` if the player is at turn, `false` otherwise
     */
    virtual bool atTurn() = 0;
};


#endif //MAO_AI_MOVEINTERFACE_H
