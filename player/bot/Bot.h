//
// Created by brent on 15/10/22.
//

#ifndef MAO_AI_BOT_H
#define MAO_AI_BOT_H

#include "../Player.h"

class Bot : public Player{
public:
    Bot();
    ~Bot();

    void acceptCorrection(const std::unordered_set<CorrectionStatus>& correction) override;


};


#endif //MAO_AI_BOT_H


