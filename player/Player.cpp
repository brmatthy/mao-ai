//
// Created by brent on 1/10/22.
//

#include "Player.h"

void Player::drawCard(const ImmutableCard* card) {
    cards.push_back(card);
}

bool Player::hasNoCards() {
    return cards.empty();
}

int Player::cardCount() {
    return cards.size();
}
