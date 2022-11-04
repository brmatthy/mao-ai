//
// Created by brent on 2/11/22.
//

#include "QActTrainer.h"
#include "../../player/bot/MoveBot.h"
#include "../../player/bot/PlayBot.h"
#include "../../player/bot/neverfinish/NeverFinishBot.h"

QActTrainer::QActTrainer(double alpha) {
    _qActAi = new QActAI(2,1);
    MoveBot* mover = new MoveBot(nullptr);
    _player = new Player(mover, new PlayBot(), _qActAi);
    mover->setPlayer(_player);
}

QActTrainer::~QActTrainer() {
    delete _player->getMover();
    delete _player->getCardPlayer();
    delete _player;
    delete _qActAi;
}

void QActTrainer::train(unsigned int n) {
    NeverFinishBot bot1 = NeverFinishBot();
    NeverFinishBot bot2 = NeverFinishBot();
    NeverFinishBot bot3 = NeverFinishBot();

    for(unsigned int i = 1; i < n; i++){
        // create a game and add the bots
        Game game = Game();
        game.addPlayer(&bot1);
        game.addPlayer(&bot2);
        game.addPlayer(&bot3);
        game.addPlayer(_player);

        // play the game
        game.playGame();

        // ask the AI how many mistakes were made
        std::cout << "Game " << i << " | F: " << _qActAi->getFaults() << " | S: " << game.getGameStepCount() << std::endl;

        // reset faults for next game
        _qActAi->clearFaults();
    }
}
