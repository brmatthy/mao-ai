// Created by mats on 06/12/22.

#include "QMoveAi.h"

QMoveAi::QMoveAi(double alpha):
        _qmodel(Qmodel<int , int>({0,1,2}, {0,1,2}, alpha))
{}

void QMoveAi::acceptCorrection(CorrectionStatus status)
{
    return;
}

bool QMoveAi::atTurn(int lastPlayer, int secondlastPlayer, ImmutableCard const* lastCard, int myIndex)
{
    return false;
}
