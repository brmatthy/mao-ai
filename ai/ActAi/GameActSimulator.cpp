// Created by mats on 07/12/22.

#include "GameActSimulator.h"
#include "../../player/bot/neverfinish/NeverFinishBot.h"
#include "NeuralNetworkActAi.h"
#include "../../player/bot/MoveBot.h"
#include "../../player/bot/PlayBot.h"
#include "../../player/Player.h"

GameActSimulator::GameActSimulator(NeuralNetwork* network): NeuralNetworkSimulator(network) {}

void GameActSimulator::simulate(NeuralNetworkAi* ai)
{
    size_t numberOfGames = 1;
    for(size_t _ = 0; _ < numberOfGames; ++_)
    {
        //add players/ai to game
        auto bot1 = NeverFinishBot();
        auto bot2 = NeverFinishBot();
        auto actai = NeuralNetworkActAi(_network, ai);
        auto playBot = PlayBot();
        auto movebot = MoveBot(nullptr);
        auto aiplayer = Player(&movebot, &playBot, &actai);
        movebot.setPlayer(&aiplayer);
        auto game = Game();
        game.addPlayer(&bot1);
        game.addPlayer(&bot2);
        game.addPlayer(&aiplayer);
        //play the game
        const int maxMoves = 500;
        game.playLimitedGame(maxMoves);
    }
}

