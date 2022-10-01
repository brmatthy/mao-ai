//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_GAME_H
#define MAO_AI_GAME_H

#include <queue>
#include <stack>
#include "../player/Player.h"


class Game {
private:
    std::vector<Player*> players;
    std::queue<ImmutableCard*> pile;
    std::stack<Action> played;

    ImmutableCard& drawNewCard();

public:

    /**
     * Simulates one turn of the game
     */
    void step();



};


#endif //MAO_AI_GAME_H
