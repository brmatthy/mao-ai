// Created by mats on 06/12/22.
#pragma once

#include "../q_learning/Qmodel.h"
#include "../../game/card/ImmutableCard.h"
#include "../../player/interfaces/MoveInterface.h"
#include "../util/Ai.h"

using playIndex = int;

class QMoveAi: public MoveInterface, public Ai
{
private:
    Qmodel<playIndex, playIndex> _qmodel;
public:
    QMoveAi(double alpha);

    void acceptCorrection(CorrectionStatus status) override;

    bool atTurn() override;
};
