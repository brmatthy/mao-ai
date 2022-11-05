//
// Created by brent on 3/11/22.
//

#ifndef MAO_AI_QPLAYTRAINER_H
#define MAO_AI_QPLAYTRAINER_H


#include "../util/Algorithm.h"
#include "../../player/Player.h"
#include "PlayAi.h"
#include "../../player/bot/MoveBot.h"
#include "../../player/bot/ActBot.h"
#include "../../player/bot/neverfinish/NeverFinishBot.h"
#include "../../data/FaultsToJson.h"
#include "SmartQPlayAi.h"

class QPlayTrainer : public Algorithm{
private:
    Player* _player;
    PlayAi* _playAi;
    std::vector<int> _faultHist;

public:
    QPlayTrainer(double alpha);
    ~QPlayTrainer();
    void execute(int iterations) override;
};


#endif //MAO_AI_QPLAYTRAINER_H
