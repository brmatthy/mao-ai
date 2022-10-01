//
// Created by brent on 1/10/22.
//

#include "Game.h"

ImmutableCard& Game::drawNewCard() {
    ImmutableCard* card = pile.front();
    pile.pop();
    return *card;
}


void Game::flushTempActions() {
    for (Action &action: temp_played){
        played.push(action);
    }
    temp_played.clear();
}


void Game::step() {
    for(Player* p : players){
        // ask each player if he wants to move
        if(p->myTurn()){
            // if the player wants to move let him drawCard(...) or performAction()
            if(p->wantsCard()){
                p->drawCard(drawNewCard());
            }else{
                temp_played.push_back(p->performAction());
            }
        }
    }
    // show all the made moves of the other players and let each player correctLastMove()
    for(Player* p: players){
        for(Action a: temp_played){
            if(p->correctLastMove(a)){
                //TODO check if the move was indeed wrong and hand cards
            }
        }
    }
}



