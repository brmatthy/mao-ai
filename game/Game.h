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
    std::vector<Player*> _players;
    std::queue<ImmutableCard*> _pile;
    std::stack<Action> _played;
    std::vector<Action> _temp_played;

    int _currentPlayer = 0;
    int _direction = 1;

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
};




#endif //MAO_AI_GAME_H
