// Created by brent on 1/10/22.

#include <iostream>
#include "ai/ActAi/QActTrainer.h"
#include "ai/PlayAi/QPlayTrainer.h"
#include "ai/MoveAi/QMoveTrainer.h"
#include "ai/ComboAi/QComboTrainer.h"

int main(){
    auto trainer = QPlayTrainer(0.1);
    trainer.execute(10000);
}


