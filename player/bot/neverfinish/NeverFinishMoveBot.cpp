//
// Created by brent on 1/11/22.
//

#include "NeverFinishMoveBot.h"

NeverFinishMoveBot::NeverFinishMoveBot(Player *player) : _player(player){

}

bool NeverFinishMoveBot::atTurn() {
    return _player->getGame()->isAtTurn(_player) && _player->cardCount() < 3;
}

void NeverFinishMoveBot::acceptCorrection(CorrectionStatus status) {}
