//
// Created by brent on 2/11/22.
//

#ifndef MAO_AI_QACTTRAINER_H
#define MAO_AI_QACTTRAINER_H


#include "../../player/Player.h"
#include "QActAI.h"

class QActTrainer {
private:
    Player* _player;
    QActAI* _qActAi;

public:
    QActTrainer(double alpha);
    ~QActTrainer();

    void train(unsigned int n);
};


#endif //MAO_AI_QACTTRAINER_H
