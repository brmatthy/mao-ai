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

void Game::switchDirection() {
    switch(this->direction){
        case 1: this->direction = -1;
        default: this->direction = 1;
    }
}

void Game::nextRoot() {
    this->currentPlayer += this->direction;
    if(this->currentPlayer < 0){
        this->currentPlayer = this->players.size() - 1;
    }else if(this->currentPlayer >= this->players.size()){
        this->currentPlayer = 0;
    }
}


void Game::step() {
    for(int i = 0; i < this->players.size(); i++){
        Player* p = this->players.at(i);
        // ask each player if he wants to move
        if(p->myTurn()){
            // let the player draw a card if he wants
            if(p->wantsCard()){
                p->drawCard(drawNewCard());
            }
            // if the player is not at turn correct him and continue
            if(this->currentPlayer != i){
                p->drawCard(drawNewCard());
                // TODO: actually pass correction
                p->acceptCorrection(nullptr);
                continue;
            }
            // Now the player wants to move and is at turn, let him move,
            // if he thinks he can move
            if(!p->wantsCard()){
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

Player &Game::getCurrentPlayer() {
    return *players.at(this->currentPlayer);
}





