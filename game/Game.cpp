// Created by brent on 1/10/22.

#include "Game.h"
#include "validation/Correction.h"
#include "validation/PlayValidation.h"
#include "validation/ActValidation.h"
#include "../util/EnumToVector.h"
#include "../util/Color.h"
#include <algorithm>
#include <random>

Game::Game(bool print) : _print(print){
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

Game::Game(): Game(false) {}

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
            if(_print){
                std::cout << "The game has ended due to a lack of cards" << std::endl << std::endl;
            }
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
    auto faults = compareMultisets(correctActs, acts);
    if(!faults.empty()){
        drawNewCard(p);
        p->acceptCorrection(faults);
    }
    if(_print){
        std::cout << action;
        if(!faults.empty()){
            std::cout << Color::red << " <- { ";
            for (Act act: acts) {
                std::cout << actToString(act) << " ";
            }
            std::cout << "}" << Color::def;
        }
        std::cout << std::endl;
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
        Action const* lastAction = &_played.at(_played.size() - 1);
        Action const* secondlastAction = nullptr;
        if(_played.size() > 1)
        {
            secondlastAction = &_played.at(_played.size() - 2);
        }
        if(_currentPlayer == i){ // player at turn
            // hand cards until player realizes it's his turn
            while ((!p->myTurn(lastAction, secondlastAction)) && _gameIsNotFinished)
            {
                drawNewCard(p);
                p->acceptCorrection({CorrectionStatus::NOT_PLAYED_AT_TURN});
                if(_print){
                    std::cout << p << ":" << Color::red << "Didn't play at turn" << Color::def << std::endl;
                }
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
                    // played a incrementFaults card
                    if(playedCorrectCard(_played.at(_played.size() - getTopCardReversedIndex(_played)).getCard(), card)){
                        actionActCorrection(p,card);
                        if(card->getCardNumber() == CardNumber::TEN){
                            switchDirection();
                        }
                        // check if player has won the game
                        if(p->hasNoCards()){
                            if(_print){
                                std::cout << "The game was won by: " << p << std::endl << std::endl;
                            }
                            p->incrementGamesWon();
                            _gameIsNotFinished = false;
                        }
                        hasActed = true;
                    }else { // played a wrong card
                        if(_print){
                            std::cout << p << ":" << Color::red << " WRONG CARD " << *card << Color::def << std::endl;
                        }
                        // give wrong card back to player
                        p->drawCard(card);
                        // punish with extra card
                        drawNewCard(p);
                        // create and tell the correction to the player
                        p->acceptCorrection({CorrectionStatus::INVALID_CARD});
                    }
                }
            }
        }else{ // player not at turn
            if(p->myTurn(lastAction, secondlastAction)){
                if(_print){
                    std::cout << p << ":" << Color::red << " MOVED OUT TURN" << Color::def << std::endl;
                }
                CorrectionStatus status;
                if(p->wantsCard()){ // drew card out of turn
                    drawNewCard(p);
                    status = CorrectionStatus::DREW_CARD_OUT_OF_TURN;
                }else{ // wanted to play out of turn
                    status = CorrectionStatus::PLAYED_OUT_OF_TURN;
                }
                // Tell the player it is not his turn
                drawNewCard(p);
                p->acceptCorrection({status});
            }
        }
    }
    // update the index of the current player
    nextRoot();
}

void Game::playGame()
{
    playLimitedGame(-1);
}

void Game::playLimitedGame(const int moves)
{
    if(_gameIsNotFinished)
    {
        // give the players cards
        for(Player* p : _players)
        {
            for(int i = 0; i < 3; ++i)
            {
                drawNewCard(p);
            }
        }
        // put 1 card on the _played stack
        auto action = Action(getTopCard(), {}, nullptr);
        pushAction(action);
        if(_print){
            std::cout << "Start card: " << *action.getCard() << std::endl;
        }

        while (_gameIsNotFinished)
        {
            step();
            ++_gameStepCount;
            if((moves != -1) && (_gameStepCount > moves))
            {
                _gameIsNotFinished = false;
            }
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

unsigned int Game::getGameStepCount() const {
    return _gameStepCount;
}

int Game::getPlayerIndex(Player const* player) const
{
    auto it = std::find(_players.begin(), _players.end(), player);
    return (int)(it - _players.begin());
}

int Game::getCurrentPlayerIndex() const
{
    return _currentPlayer;
}

int Game::getCurrentDirection() const
{
    return _direction;
}

void Game::setPrintState(bool print) {
    _print = print;
}

