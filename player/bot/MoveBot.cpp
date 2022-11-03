//
// Created by brent on 18/10/22.
//

#include "MoveBot.h"

bool MoveBot::atTurn() {
    return _player->getGame()->isAtTurn(_player);
}

void MoveBot::acceptCorrection(CorrectionStatus status) {
    // we are always correct
}

MoveBot::MoveBot(Player *player): _player(player){

}
