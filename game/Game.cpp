//
// Created by brent on 1/10/22.
//

#include "Game.h"
#include "validation/Correction.h"
#include "validation/PlayValidation.h"
#include "validation/ActValidation.h"
#include "../util/EnumToVector.h"
#include <algorithm>
#include <random>



Game::Game() {
    // create all the cards
    for(CardType type : EnumToVector::getCardTypeVector()){
        for(CardNumber number : EnumToVector::getCardNumberVector()){
            const ImmutableCard* card = new ImmutableCard(type, number);
            _pile.push_front(card);
        }
    }
    // shuffle them
    shufflePile();
}

Game::~Game() {

    // delete played cards
    for(const Action& action : _played){
        delete action.getCard();
    }

    // delete unplayed cards
    for(const ImmutableCard* card : _pile){
        delete card;
    }
}

void Game::drawNewCard(Player* player) {
    player->drawCard(getTopCard());
}

const ImmutableCard* Game::getTopCard() {
    const ImmutableCard* card = _pile.back();
    _pile.pop_back();
    if(_pile.empty()){
        flushActionsToPileAndShuffle();
        // if the pile is still empty, then all the cards are with the players: end the game
        if(_pile.empty()){
            _gameIsNotFinished = false;
        }
    }
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
    std::unordered_set<Act> acts = p->act(_played, card);
    std::unordered_set<Act> correctActs;
    getCorrectActs(correctActs, _played, card);
    Action action = {card, correctActs, p};
    if(!compareMultisets(correctActs, acts)){
        drawNewCard(p);
        const Correction correction = Correction(CorrectionStatus::CHNAR, &action);
        p->acceptCorrection(correction);
    }
    pushAction(action);
}

void Game::takeAllCardsFromPlayer(Player *p) {
    for(const ImmutableCard* card: p->getCards()){
        _pile.push_front(card);
    }
    p->clearCards();
}
void Game::flushActionsToPileAndShuffle() {
    // flush cards until only 1 card remains
    int actions_to_leave = getTopCardReversedIndex(_played);
    while (_played.size() > actions_to_leave){
        const ImmutableCard* card = _played.front().getCard();
        if(card != nullptr){
            _pile.push_front(card);
        }
        _played.pop_front();
    }
    shufflePile();

}

void Game::shufflePile() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(_pile.begin(), _pile.end(),g);
}


void Game::step() {
    for(int i = 0; i < _players.size(); i++){
        Player* p = _players.at(i);

        if(_currentPlayer == i){ // player at turn
            // hand cards until player realizes it's his turn
            while (!p->myTurn() && _gameIsNotFinished){
                drawNewCard(p);
                const Correction correction = Correction(CorrectionStatus::NOT_PLAYED_AT_TURN, nullptr);
                p->acceptCorrection(correction);
            }
            // now player wants to move
            bool hasActed = false;
            while (!hasActed && _gameIsNotFinished){
                if(p->wantsCard()){ // draw a card
                    drawNewCard(p);
                    const ImmutableCard* card = nullptr;
                    actionActCorrection(p,card);
                    hasActed = true;
                }else{ // play a card
                    const ImmutableCard* card = p->play();
                    if(playedCorrectCard(_played.at(_played.size() - getTopCardReversedIndex(_played)).getCard(), card)){ // played a correct card
                        actionActCorrection(p,card);
                        if(card->getCardNumber() == CardNumber::TEN){
                            switchDirection();
                        }
                        // check if player has won the game
                        if(p->hasNoCards()){
                            _gameIsNotFinished = false;
                        }
                        hasActed = true;
                    }else { // played a wrong card
                        // give wrong card back to player
                        p->drawCard(card);
                        // punish with extra card
                        drawNewCard(p);
                        // create and tell the correction to the player
                        const Correction correction = Correction(CorrectionStatus::INVALID_CARD, nullptr);
                        p->acceptCorrection(correction);
                    }
                }
            }
        }else{ // player not at turn
            if(p->myTurn()){
                CorrectionStatus status;
                if(p->wantsCard()){ // drew card out of turn
                    drawNewCard(p);
                    status = CorrectionStatus::DREW_CARD_OUT_OF_TURN;
                }else{ // wanted to play out of turn
                    status = CorrectionStatus::PLAYED_OUT_OF_TURN;
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

void Game::playGame() {
    if(_gameIsNotFinished){
        // give the players cards
        for(Player* p : _players){
            for(int i = 0; i < 3; i++){
                drawNewCard(p);
            }
        }
        // put 1 card on the _played stack
        Action action = Action(getTopCard(), {}, nullptr);
        pushAction(action);

        while (_gameIsNotFinished){
            step();
        }

        // get the cards back from the players
        for(Player* p : _players){
            takeAllCardsFromPlayer(p);
        }

    }
}


bool Game::isAtTurn(const Player *player) const {
    return player == _players.at(_currentPlayer);
}

const std::deque<Action> &Game::getPlayed() const {
    return _played;
}

void Game::addPlayer(Player *player) {
    player->setGame(this);
    _players.push_back(player);
}

