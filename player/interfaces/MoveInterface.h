//
// Created by brent on 18/10/22.
//

#ifndef MAO_AI_MOVEINTERFACE_H
#define MAO_AI_MOVEINTERFACE_H



#include "../../game/validation/Correction.h"
class Correction;

class MoveInterface {
public:
    /**
     * Returns whether or not the player is at turn according to the mover
     * @return `true` if the player is at turn, `false` otherwise
     */
    virtual bool atTurn() = 0;

    /**
     * Handle the correction that the player received, this may or may not be useful
     * @param correction The Correction
     */
    virtual void acceptCorrection(const Correction &correction) = 0;

};


#endif //MAO_AI_MOVEINTERFACE_H
