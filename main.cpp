// Created by brent on 1/10/22.

#include <iostream>
#include "ai/ActAi/QActTrainer.h"
#include "ai/PlayAi/QPlayTrainer.h"
#include "ai/MoveAi/QMoveTrainer.h"

int main(){
    auto trainer = QMoveTrainer(0.1, 4);
    trainer.execute(100);
}

