//
// Created by brent on 1/10/22.
//


#include "bench/SimpleBench.h"
#include "ai/q_learning/states/AllStatesFactory.h"
#include "ai/ActAi/QActTrainer.h"


int main(){
    QActTrainer trainer = QActTrainer(1);
    trainer.train(2);
}