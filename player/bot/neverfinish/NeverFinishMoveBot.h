//
// Created by brent on 1/11/22.
//

#ifndef MAO_AI_NEVERFINISHMOVEBOT_H
#define MAO_AI_NEVERFINISHMOVEBOT_H


#include "../../interfaces/MoveInterface.h"
#include "../../Player.h"

class NeverFinishMoveBot: public MoveInterface {
private:
    Player* _player;
public:
    NeverFinishMoveBot(Player* player);

    bool atTurn() override;

    void acceptCorrection(CorrectionStatus status) override;

};


#endif //MAO_AI_NEVERFINISHMOVEBOT_H
