// Created by mats on 06/12/22.
#pragma once

#include <tuple>
#include "../q_learning/Qmodel.h"
#include "../../game/card/ImmutableCard.h"
#include "../../player/interfaces/MoveInterface.h"
#include "../util/Ai.h"

#define EMPTYSTATE std::tuple<int, int, ImmutableCard>{0, 0, ImmutableCard(CardType::NONE, CardNumber::NONE)}

class QMoveAi: public MoveInterface, public Ai
{
private:
    Qmodel<std::tuple<int, int, ImmutableCard>, int>* _qmodel = nullptr;
    std::tuple<int, int, ImmutableCard> _lastState = EMPTYSTATE;
    int _lastAct = -1;
    int _numberOfPlayers = 0;
public:
    QMoveAi(double alpha, size_t numberOfPlayers);
    ~QMoveAi() override;

    void acceptCorrection(CorrectionStatus status) override;

    bool atTurn(int lastPlayer, int secondlastPlayer, ImmutableCard const* lastCard, int myIndex) override;
};
