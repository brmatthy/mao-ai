// Created by mats on 06/12/22.
#pragma once

#include "../util/Algorithm.h"
#include "../../player/Player.h"
#include "QMoveAi.h"

class QMoveTrainer: public Algorithm
{
private:
    Player* _player = nullptr;
    QMoveAi* _playAi = nullptr;
    size_t _numberOfPlayers = 0;
public:
    QMoveTrainer(double alpha, size_t numberOfPlayers);
    ~QMoveTrainer();
    void execute(int iterations) override;
};
