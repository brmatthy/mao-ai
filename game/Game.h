//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_GAME_H
#define MAO_AI_GAME_H

#include <queue>
#include "../player/Player.h"


class Game {
private:
    std::vector<Player*> _players;
    std::queue<const ImmutableCard*> _pile;
    std::vector<Action> _played;

    int _currentPlayer = 0;
    int _direction = 1;

    const ImmutableCard* drawNewCard();
    void switchDirection();
    void nextRoot();

public:

    /**
     * Simulates one turn of the game
     */
    void step();
};




#endif //MAO_AI_GAME_H
