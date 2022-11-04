//
// Created by brent on 1/10/22.
//

#include "Player.h"

Player::Player(MoveInterface *mover, PlayInterface *cardPlayer, ActInterface *actor) {
    _mover = mover;
    _cardPlayer = cardPlayer;
    _actor = actor;
}


void Player::drawCard(const ImmutableCard* card) {
    _cards.push_back(card);
}

bool Player::hasNoCards() {
    return _cards.empty();
}

int Player::cardCount() {
    return _cards.size();
}

void Player::setGame(Game *game) {
    _game = game;
}

std::vector<const ImmutableCard *> &Player::getCards() {
    return _cards;
}

void Player::clearCards() {
    _cards.clear();
}

const ImmutableCard *Player::play() {
    int i = _cardPlayer->play(_game->getPlayed(),_cards);
    const ImmutableCard* card = _cards.at(i);
    _cards.erase(_cards.begin() + i);
    return card;
}

const std::unordered_set<Act> Player::act(const std::deque<Action> &played, const ImmutableCard *played_card) {
    return _actor->act(played, played_card);
}

bool Player::myTurn() {
    return _mover->atTurn();
}

bool Player::wantsCard() {
    return _cardPlayer->wantsCard(_game->getPlayed(),_cards);
}

const Game* Player::getGame() {
    return _game;
}

void Player::acceptCorrection(const std::unordered_set<CorrectionStatus> &corrections) {
    for(CorrectionStatus status: corrections){
        if(status == CorrectionStatus::INVALID_CARD){
            _cardPlayer->acceptCorrection(status);
        }else if(
                status == CorrectionStatus::PLAYED_OUT_OF_TURN ||
                status == CorrectionStatus::NOT_PLAYED_AT_TURN ||
                status == CorrectionStatus::DREW_CARD_OUT_OF_TURN
                ){
            _mover->acceptCorrection(status);
        }else{
            _actor->acceptCorrection(status);
        }
    }
}

MoveInterface *Player::getMover() const {
    return _mover;
}

PlayInterface *Player::getCardPlayer() const {
    return _cardPlayer;
}

ActInterface *Player::getActor() const {
    return _actor;
}

