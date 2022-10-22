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


