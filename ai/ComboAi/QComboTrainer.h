// Created by mats on 09/12/22.

#pragma once

#include "../util/Algorithm.h"
#include "../../player/Player.h"
#include "../MoveAi/QMoveAi.h"
#include "../PlayAi//QPlayAI.h"
#include "../ActAi/QActAI.h"

class QComboTrainer: public Algorithm
{
private:
    Player* _player = nullptr;
    QMoveAi* _moveai = nullptr;
    QPlayAI* _playai = nullptr;
    QActAI* _actai = nullptr;
    size_t _numberOfPlayers = 0;
public:
    QComboTrainer(double alpha, size_t numberOfPlayers);
    ~QComboTrainer();
    void execute(int iterations) override;
};
