//
// Created by brent on 15/10/22.
//

#include "Bot.h"
#include "ActBot.h"
#include "MoveBot.h"
#include "PlayBot.h"

Bot::Bot() : Player(new MoveBot(this), new PlayBot(), new ActBot()) {}

Bot::~Bot() {
    delete _mover;
    delete _cardPlayer;
    delete _actor;
}

void Bot::acceptCorrection(const std::unordered_set<CorrectionStatus> &correction) {
    // we are always correct
}





