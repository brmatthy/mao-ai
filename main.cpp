//
// Created by brent on 1/10/22.
//



#include <iostream>

#include "ai/LayCardSimulator.h"

#include "util/GeneticAi.h"
#include "util/GeneticAlgorithm.h"
#include "util/NeuralNetwork.h"
#include "player/Bot.h"
#include "ai/util/GeneticAi.h"
#include "ai/util/GeneticAlgorithm.h"
#include "ai/util/NeuralNetwork.h"


int main(){
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
        const ImmutableCard* card = action.getCard();
        std::cout << action.getPlayer() << ": ";
        if(card == nullptr){
            std::cout << "draw card" << std::endl;
        }else{
            std::cout << *card << std::endl;
        }
    }

}