// Created by mats on 06/12/22.

#include "QMoveAi.h"

#define PUNISHMENT -5
#define REWARD 1

QMoveAi::QMoveAi(double alpha, size_t numberOfPlayers)
{
    auto allStates = std::vector<std::tuple<int, int, ImmutableCard>>();
    auto allActions = std::vector<int>();
    auto allCards = ImmutableCard::getAllCards();
    for (int player = 0; player < numberOfPlayers; ++player)
    {
        allActions.push_back(player);
        for (int secondPlayer = 0; secondPlayer < numberOfPlayers; ++secondPlayer)
        {
            for (ImmutableCard card : allCards)
            {
                auto newtuple = std::tuple<int, int, ImmutableCard>{player, secondPlayer, card};
                allStates.push_back(newtuple);
            }
        }
    }
    _numberOfPlayers = numberOfPlayers;
    _qmodel = new Qmodel<std::tuple<int, int, ImmutableCard> , int>(allStates, allActions, alpha);
}

QMoveAi::~QMoveAi()
{
    delete _qmodel;
}

void QMoveAi::acceptCorrection(CorrectionStatus status)
{
    incrementFaults();
    if(_qmodel == nullptr)
    {
        return;
    }
    _qmodel->valueUpdate(_lastState, _lastAct, PUNISHMENT);
    _lastState = EMPTYSTATE;
}

bool QMoveAi::atTurn(int lastPlayer, int secondlastPlayer, ImmutableCard const* lastCard, int myIndex)
{
    if(_qmodel == nullptr)
    {
        return false;
    }
    incrementTurns();
    // reward if last action was correct
    if(EMPTYSTATE != _lastState){
        _qmodel->valueUpdate(_lastState, _lastAct, REWARD);
    }
    _lastState = std::tuple<int, int, ImmutableCard>(lastPlayer, secondlastPlayer, *lastCard);
    for(int i = 0; i < _numberOfPlayers; ++i){
        _lastAct = i;
        if(_qmodel->doAction(_lastState, _lastAct)){ // check if this players turn
            return i == myIndex;
        }
    }
    // should never occur
    return 0;
}
