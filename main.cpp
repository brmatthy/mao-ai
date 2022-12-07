// Created by brent on 1/10/22.

#include <iostream>
#include "ai/ActAi/QActTrainer.h"
#include "ai/PlayAi/QPlayTrainer.h"

int main(){
    auto trainer = QPlayTrainer(0.1);
    trainer.execute(1000);
}

