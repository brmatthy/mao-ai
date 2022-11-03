// Created by mats on 31/10/22.

#include "GameLayCardSimulator.h"
#include "../game/Game.h"
#include "../player/bot/Bot.h"
#include "PlayAi/NeuralNetworkPlayAi.h"
#include "../player/bot/MoveBot.h"
#include "../player/bot/ActBot.h"

GameLayCardSimulator::GameLayCardSimulator(NeuralNetwork* network): NeuralNetworkSimulator(network) {}

void GameLayCardSimulator::simulate(NeuralNetworkAi* ai)
{
    Game game;
    //add players/ai to game
    auto bot1 = Bot();
    auto bot2 = Bot();
    auto playai = NeuralNetworkPlayAi(_network, ai);
    Player* aiplayer = new Player(new MoveBot(aiplayer), &playai, new ActBot());
    game.addPlayer(&bot1);
    game.addPlayer(&bot2);
    game.addPlayer(aiplayer);
    //play the game
    game.playGame();
    delete aiplayer;
}
