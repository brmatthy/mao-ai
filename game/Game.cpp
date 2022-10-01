//
// Created by brent on 1/10/22.
//

#include "Game.h"

ImmutableCard& Game::drawNewCard() {
    ImmutableCard* card = pile.front();
    pile.pop();
    return *card;
}

void Game::step() {
    for(Player* p : players){

    }
    // ask each player if he wants to move

    // if the player wants to move let him drawCard(...) or play() and act()

    // show all the made moves of the other players and let each player correctLastMove()

}
