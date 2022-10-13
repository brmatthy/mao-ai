//
// Created by brent on 1/10/22.
//

#include "Game.h"
#include "./validation/CorrectionStatus.h"
#include "validation/Correction.h"
#include "validation/PlayValidation.h"
#include "validation/ActValidation.h"

void Game::drawNewCard(Player* player) {
    if(player->cardCount() < _maxCcards || _maxCcards < 3){
        player->drawCard(getTopCard());
        return;
    }
}

const ImmutableCard* Game::getTopCard() {
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
                drawNewCard(p);
                const Correction correction = Correction(NOT_PLAYED_AT_TURN, nullptr);
                p->acceptCorrection(correction);
            }
            // now player wants to move
            bool hasActed = false;
            while (!hasActed){
                if(p->wantsCard()){
                    drawNewCard(p);
                    // TODO: action card draw + potential acts + correction
                    Action action = {nullptr, {}, p};
                    hasActed = true;
                }else{
                    Action action = p->performAction();
                    if(playedCorrectCard(_played.at(_played.size() - 1).getCard(), action.getCard())){ // played a correct card
                        // TODO: check if act was incorrect
                        hasActed = true;
                    }else { // played a wrong card
                        // give wrong card back to player
                        p->drawCard(action.getCard());
                        // punish with extra card
                        drawNewCard(p);
                    }
                }
            }
        }else{ // player not at turn
            if(p->myTurn()){
                // let the player draw a card if he wants
                if(p->wantsCard()){
                    drawNewCard(p);
                }
                // Tell the player it is not his turn
                drawNewCard(p);
                const Correction correction = Correction(PLAYED_OUT_OF_TURN, nullptr);
                p->acceptCorrection(correction);
            }
        }
    }
}







