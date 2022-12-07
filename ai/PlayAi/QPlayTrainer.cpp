//
// Created by brent on 3/11/22.
//

#include "QPlayTrainer.h"
#include "../../data/FaultsToJson.h"


QPlayTrainer::QPlayTrainer(double alpha){
    _qPlayAI = new QPlayAI(alpha);
    MoveBot* mover = new MoveBot(nullptr);
    _player = new Player(mover, _qPlayAI, new ActBot());
    mover->setPlayer(_player);
}

QPlayTrainer::~QPlayTrainer(){
    delete _player->getMover();
    delete _player->getActor();
    delete _player;
    delete _qPlayAI;
}

void QPlayTrainer::execute(int iterations) {
    NeverFinishBot bot1 = NeverFinishBot();
    NeverFinishBot bot2 = NeverFinishBot();
    NeverFinishBot bot3 = NeverFinishBot();

    for(unsigned int i = 1; i <= iterations; i++){
        // create a game and add the bots
        Game game = Game();
        game.addPlayer(&bot1);
        game.addPlayer(&bot2);
        game.addPlayer(&bot3);
        game.addPlayer(_player);

        // play the game
        game.playGame();
        _faultHist.push_back(_qPlayAI->faults());

        // ask the AI how many mistakes were made
        std::cout << "Game " << i << " | F: " << _qPlayAI->faults() << " | S: " << game.getGameStepCount() << std::endl;

        // reset faults for next game
        _qPlayAI->clean();
    }

    faultVectorToJsonFile(_faultHist);


}
