//
// Created by brent on 18/10/22.
//

#include "MoveBot.h"

bool MoveBot::atTurn(int lastPlayer, int secondlastPlayer, ImmutableCard const* lastCard, int myIndex) {
    return _player->getGame()->isAtTurn(_player);
}

void MoveBot::acceptCorrection(CorrectionStatus status) {
    // we are always incrementFaults
}

MoveBot::MoveBot(Player *player): _player(player){

}

void MoveBot::setPlayer(Player *player) {
    _player = player;
}
