//
// Created by brent on 1/10/22.
//

#include "Player.h"

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
