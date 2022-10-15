//
// Created by brent on 1/10/22.
//

#include "Game.h"
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
    _direction = _direction == 1 ? -1 : 1;
}

void Game::nextRoot() {
    _currentPlayer += _direction;
    if(_currentPlayer < 0){
        _currentPlayer = _players.size() - 1;
    }else if(_currentPlayer >= _players.size()){
        _currentPlayer = 0;
    }
}

void Game::pushAction(Action& action) {
    _played.push_back(action);
}


void Game::actionActCorrection(Player *p, const ImmutableCard *card) {
    std::unordered_multiset<Act> acts = p->act(_played, card);
    std::unordered_multiset<Act> correctActs;
    getCorrectActs(correctActs, _played, card);
    Action action = {card, correctActs, p};
    if(!compareMultisets(correctActs, acts)){
        drawNewCard(p);
        const Correction correction = Correction(INVALID_ACT, &action);
        p->acceptCorrection(correction);
    }
    pushAction(action);
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
                if(p->wantsCard()){ // draw a card
                    drawNewCard(p);
                    ImmutableCard* card = nullptr;
                    actionActCorrection(p,card);
                    hasActed = true;
                }else{ // play a card
                    const ImmutableCard* card = p->play();
                    if(playedCorrectCard(_played.at(_played.size() - 1).getCard(), card)){ // played a correct card
                        actionActCorrection(p,card);
                        if(card->getCardNumber() == TEN){
                            switchDirection();
                        }
                        hasActed = true;
                    }else { // played a wrong card
                        // give wrong card back to player
                        p->drawCard(card);
                        // punish with extra card
                        drawNewCard(p);
                        // create and tell the correction to the player
                        const Correction correction = Correction(INVALID_CARD, nullptr);
                        p->acceptCorrection(correction);
                    }
                }
            }
        }else{ // player not at turn
            if(p->myTurn()){
                CorrectionStatus status;
                if(p->wantsCard()){ // drew card out of turn
                    drawNewCard(p);
                    status = DREW_CARD_OUT_OF_TURN;
                }else{ // wanted to play out of turn
                    status = PLAYED_OUT_OF_TURN;
                }
                // Tell the player it is not his turn
                drawNewCard(p);
                const Correction correction = {status, nullptr};
                p->acceptCorrection(correction);
            }
        }
    }
    // update the index of the current player
    nextRoot();
}

bool Game::isAtTurn(const Player *player) const {
    return player == _players.at(_currentPlayer);
}

const std::deque<Action> &Game::getPlayed() const {
    return _played;
}









