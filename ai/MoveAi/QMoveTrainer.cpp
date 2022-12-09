// Created by mats on 06/12/22.

#include "QMoveTrainer.h"
#include "../../player/bot/PlayBot.h"
#include "../../player/bot/ActBot.h"
#include "../../player/bot/neverfinish/NeverFinishBot.h"
#include "../../data/FaultsToJson.h"

QMoveTrainer::QMoveTrainer(double alpha, size_t numberOfPlayers):
    _moveai(new QMoveAi(alpha, numberOfPlayers)),
    _numberOfPlayers(numberOfPlayers)
{
    _player = new Player(_moveai, new PlayBot(), new ActBot());
}

QMoveTrainer::~QMoveTrainer()
{
    if(_player != nullptr)
    {
        delete _player->getCardPlayer();
        delete _player->getActor();
    }
    delete _player;
    delete _moveai;
}

void QMoveTrainer::execute(int iterations)
{
    auto bots = std::vector<NeverFinishBot*>();
    for (size_t i = 0; i < (_numberOfPlayers-1); ++i)
    {
        auto* bot = new NeverFinishBot();
        bots.push_back(bot);
    }

    for(unsigned int i = 1; i <= iterations; i++){
        // create a game and add the bots
        auto game = Game();
        game.addPlayer(_player);
        for (NeverFinishBot* bot : bots)
        {
            game.addPlayer(bot);
        }

        // play the game
        game.playGame();
        _faultHist.push_back(_moveai->faults());

        // print state
        //std::cout << "Game " << i << " | F: " << _playAi->faults() << " | T: " << _playAi->turns() << " | R: " << _playAi->relativeFaults() << std::endl;

        _moveai->clean();
    }

    for (NeverFinishBot* bot : bots)
    {
        delete bot;
    }

    faultVectorToJsonFile(_faultHist);
    _faultHist.clear();
}