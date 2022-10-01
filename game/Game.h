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
    std::vector<Player> players;
    std::queue<ImmutableCard> pile;
    std::stack<ImmutableCard> played;

    ImmutableCard drawNewCard();
    void playNewCard(ImmutableCard card);
public:



};


#endif //MAO_AI_GAME_H
