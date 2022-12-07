//
// Created by brent on 3/11/22.
//

#include "QPlayTrainer.h"
#include "QPlayAI.h"


QPlayTrainer::QPlayTrainer(double alpha){
    _playAi = new QPlayAI(alpha);
    MoveBot* mover = new MoveBot(nullptr);
    _player = new Player(mover, _playAi, new ActBot());
    mover->setPlayer(_player);
}

QPlayTrainer::~QPlayTrainer(){
    delete _player->getMover();
    delete _player->getActor();
    delete _player;
    delete _playAi;
}

void QPlayTrainer::execute(int iterations) {
    auto bot1 = NeverFinishBot();
    auto bot2 = NeverFinishBot();
    auto bot3 = NeverFinishBot();

    for(unsigned int i = 1; i <= iterations; i++){
        // create a game and add the bots
        Game game = Game();
        game.addPlayer(&bot1);
        game.addPlayer(&bot2);
        game.addPlayer(&bot3);
        game.addPlayer(_player);

        // play the game
        game.playGame();
        _faultHist.push_back(_playAi->faults());

        // ask the AI how many mistakes were made
        // std::cout << "Game " << i << " | F: " << _playAi->faults() << " | S: " << game.getGameStepCount() << std::endl;

        // reset faults for next game
        _playAi->clean();
    }

    faultVectorToJsonFile(_faultHist);


}
