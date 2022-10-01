//
// Created by brent on 1/10/22.
//

#include "Game.h"

ImmutableCard Game::drawNewCard() {
    ImmutableCard card = pile.front();
    pile.pop();
    return card;
}

void Game::playNewCard(ImmutableCard card) {
    played.push(card);
}
