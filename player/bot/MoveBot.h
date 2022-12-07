//
// Created by brent on 18/10/22.
//

#ifndef MAO_AI_MOVEBOT_H
#define MAO_AI_MOVEBOT_H


#include "../interfaces/MoveInterface.h"
#include "Bot.h"

class MoveBot: public MoveInterface {
private:
    Player* _player;
public:
    MoveBot(Player* player);

    bool atTurn() override;

    void acceptCorrection(CorrectionStatus status) override;

    void setPlayer(Player *player);
};


#endif //MAO_AI_MOVEBOT_H
