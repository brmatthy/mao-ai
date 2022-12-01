//
// Created by brent on 2/11/22.
//

#ifndef MAO_AI_QACTTRAINER_H
#define MAO_AI_QACTTRAINER_H


#include "../../player/Player.h"
#include "QActAI.h"
#include "../util/Algorithm.h"

class QActTrainer: Algorithm {
private:
    Player* _player;
    QActAI* _qActAi;

public:
    QActTrainer(double alpha);
    ~QActTrainer();

    void execute(int iterations) override;
};


#endif //MAO_AI_QACTTRAINER_H
