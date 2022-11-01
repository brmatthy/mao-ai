//
// Created by brent on 18/10/22.
//

#include "SimpleBench.h"
#include "../player/bot/Bot.h"
#include "../ai/q_learning/states/NCards.h"
#include "../ai/q_learning/states/GlobalNstate.h"
#include <vector>

void threeBotsTest(){

    // create bots
    Bot bot1 = Bot();
    Bot bot2 = Bot();
    Bot bot3 = Bot();

    //create game
    Game game = Game();

    // add the bots to the game
    game.addPlayer(&bot1);
    game.addPlayer(&bot2);
    game.addPlayer(&bot3);


    // play the game
    game.playGame();

    // log the action stack
    for(const Action& action: game.getPlayed()){
        std::cout << action;
    }
}
