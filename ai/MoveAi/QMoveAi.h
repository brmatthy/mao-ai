// Created by mats on 06/12/22.
#pragma once

#include "../q_learning/Qmodel.h"
#include "../../game/card/ImmutableCard.h"
#include "../../player/interfaces/MoveInterface.h"
#include "../util/Ai.h"

class QMoveAi: public MoveInterface, public Ai
{
private:
    Qmodel<int, int> _qmodel;
public:
    QMoveAi(double alpha);

    void acceptCorrection(CorrectionStatus status) override;

    bool atTurn(int lastPlayer, int secondlastPlayer, ImmutableCard const* lastCard, int myIndex) override;
};
