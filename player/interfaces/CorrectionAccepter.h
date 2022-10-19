//
// Created by brent on 19/10/22.
//

#ifndef MAO_AI_CORRECTIONACCEPTER_H
#define MAO_AI_CORRECTIONACCEPTER_H

class Correction;

class CorrectionAccepter {
public:
    virtual ~CorrectionAccepter() = default;
    /**
     * Handle the correction that the player received, this may or may not be useful
     * @param correction The Correction
     */
    virtual void acceptCorrection(const Correction &correction) = 0;
};


#endif //MAO_AI_CORRECTIONACCEPTER_H
