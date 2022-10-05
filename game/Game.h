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
    std::vector<Action> temp_played;

    int currentPlayer = 0;
    int direction = 1;

    ImmutableCard& drawNewCard();
    /**
     * Move the temp actions to the played stack
     */
    void flushTempActions();

    void switchDirection();
    void nextRoot();

public:

    /**
     * Simulates one turn of the game
     */
    void step();

    Player& getCurrentPlayer();


};




#endif //MAO_AI_GAME_H
