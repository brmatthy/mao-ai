// Created by mats on 31/10/22.

#include "GameLayCardSimulator.h"
#include "../../game/Game.h"
#include "../../player/bot/neverfinish/NeverFinishBot.h"
#include "NeuralNetworkPlayAi.h"
#include "../../player/bot/MoveBot.h"
#include "../../player/bot/ActBot.h"

GameLayCardSimulator::GameLayCardSimulator(NeuralNetwork* network): NeuralNetworkSimulator(network) {}

void GameLayCardSimulator::simulate(NeuralNetworkAi* ai)
{
    //add players/ai to game
    auto bot1 = NeverFinishBot();
    auto bot2 = NeverFinishBot();
    auto playai = NeuralNetworkPlayAi(_network, ai);
    auto actbot = ActBot();
    auto movebot = MoveBot(nullptr);
    auto aiplayer = Player(&movebot, &playai, &actbot);
    movebot.setPlayer(&aiplayer);
    auto game = Game();
    game.addPlayer(&bot1);
    game.addPlayer(&bot2);
    game.addPlayer(&aiplayer);
    //play the game
    const int maxMoves = 500;
    game.playLimitedGame(maxMoves);
}
