//
// Created by brent on 1/10/22.
//

#include "Game.h"
#include "./validation/CorrectionStatus.h"
#include "validation/Correction.h"

const ImmutableCard* Game::drawNewCard() {
    const ImmutableCard* card = _pile.front();
    _pile.pop();
    return card;
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

        if(_currentPlayer == i){ // player at turn
            // hand cards until player realizes it's his turn
            while (!p->myTurn()){
                p->drawCard(drawNewCard());
                const Correction correction = Correction(NOT_PLAYED_AT_TURN, nullptr, {});
                p->acceptCorrection(correction);
            }
            // now player wants to move
            if(p->wantsCard()){
                p->drawCard(drawNewCard());
            }else{
                // TODO: performaction
                // TODO: check if the action was correct
            }
        }else{ // player not at turn
            if(p->myTurn()){
                // let the player draw a card if he wants
                if(p->wantsCard()){
                    p->drawCard(drawNewCard());
                }
                // Tell the player it is not his turn
                p->drawCard(drawNewCard());
                const Correction correction = Correction(PLAYED_OUT_OF_TURN, nullptr, {});
                p->acceptCorrection(correction);
            }
        }
    }
}






