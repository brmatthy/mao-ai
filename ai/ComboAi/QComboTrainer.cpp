// Created by mats on 09/12/22.

#include "QComboTrainer.h"
#include "../../player/bot/neverfinish/NeverFinishBot.h"
#include "../../data/FaultsToJson.h"
#include "../../player/bot/Bot.h"

QComboTrainer::QComboTrainer(double alpha, size_t numberOfPlayers):
    _moveai(new QMoveAi(alpha, numberOfPlayers)),
    _playai(new QPlayAI(1)),
    _actai(new QActAI(2, alpha)),
    _numberOfPlayers(numberOfPlayers)
{
    _player = new Player(_moveai, _playai, _actai);
}

QComboTrainer::~QComboTrainer()
{
    delete _player;
    delete _moveai;
    delete _playai;
    delete _actai;
}

void QComboTrainer::execute(int iterations)
{
    if(_moveai == nullptr || _playai == nullptr || _actai == nullptr)
    {
        return;
    }
    auto bots = std::vector<Player*>();
    for (size_t i = 0; i < (_numberOfPlayers-1); ++i)
    {
        auto* bot = new Bot();
        bots.push_back(bot);
    }

    for(unsigned int i = 1; i <= iterations; i++){
        // create a game and add the bots
        auto game = Game(_print);
        game.addPlayer(_player);
        if(_print){
            std::cout << "The AI is: " << _player << std::endl;
        }
        for (Player* bot : bots)
        {
            game.addPlayer(bot);
        }

        // play the game
        game.playGame();
        _faultHist.push_back(_player->getGamesWon());
        // _faultHist.push_back(_moveai->faults() + _playai->faults() + _actai->faults());
        // std::cout << "G: " << i << " | M: " << _moveai->faults() << " | P: " << _playai->faults() << " | A: " << _actai->faults() << std::endl;

        _moveai->clean();
        _playai->clean();
        _actai->clean();
    }

    for (Player* bot : bots)
    {
        delete bot;
    }

    faultVectorToJsonFile(_faultHist);
    _faultHist.clear();
}

void QComboTrainer::setPrintState(bool print) {
    _print = print;
}
