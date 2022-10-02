//
// Created by brent on 1/10/22.
//

#include "Player.h"

void Player::drawCard(ImmutableCard& card) {
    cards.push_back(&card);
}

bool Player::hasNoCards() {
    return cards.empty();
}

Action Player::performAction() {
    return {play(), act(), this};
}
