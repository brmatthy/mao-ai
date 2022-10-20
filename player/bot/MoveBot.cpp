//
// Created by brent on 18/10/22.
//

#include "MoveBot.h"

bool MoveBot::atTurn() {
    return _player->getGame()->isAtTurn(_player);
}

void MoveBot::acceptCorrection(const Correction &correction) {
    // we are always correct
}

MoveBot::MoveBot(Player *player): _player(player){

}
