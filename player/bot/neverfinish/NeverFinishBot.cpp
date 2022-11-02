//
// Created by brent on 1/11/22.
//

#include "NeverFinishBot.h"


NeverFinishBot::NeverFinishBot(): Player(new NeverFinishMoveBot(this), new PlayBot(), new ActBot()){}

NeverFinishBot::~NeverFinishBot(){
    delete _mover;
    delete _cardPlayer;
    delete _actor;
}