//
// Created by brent on 1/10/22.
//

#include "Game.h"
#include "./validation/CorrectionStatus.h"
#include "validation/Correction.h"

const ImmutableCard* Game::drawNewCard() {
    ImmutableCard* card = _pile.front();
    _pile.pop();
    return card;
}


void Game::flushTempActions() {
    for (Action &action: _temp_played){
        _played.push(action);
    }
    _temp_played.clear();
}

void Game::switchDirection() {
    switch(_direction){
        case 1: _direction = -1;
        default: _direction = 1;
    }
}

void Game::nextRoot() {
    _currentPlayer += _direction;
    if(_currentPlayer < 0){
        _currentPlayer = _players.size() - 1;
    }else if(_currentPlayer >= _players.size()){
        _currentPlayer = 0;
    }
}


void Game::step() {
    for(int i = 0; i < _players.size(); i++){
        Player* p = _players.at(i);

        if(_currentPlayer == i){

        }


        // ask each player if he wants to move
        if(p->myTurn()){
            // let the player draw a card if he wants
            if(p->wantsCard()){
                p->drawCard(drawNewCard());
            }
            // if the player is not at turn correct him and continue
            if(_currentPlayer != i){
                p->drawCard(drawNewCard());
                Correction correction = Correction(PLAYED_OUT_OF_TURN, nullptr, nullptr);
                p->acceptCorrection(correction);
                continue;
            }
            // Now the player wants to move and is at turn, let him move,
            // if he thinks he can move
            if(!p->wantsCard()){
                _temp_played.push_back(p->performAction());
            }
        }
    }
}






