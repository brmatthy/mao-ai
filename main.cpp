//
// Created by brent on 1/10/22.
//

#include <iostream>
#include "ai/q_learning/states/AllStatesFactory.h"
#include "ai/ActAi/QActTrainer.h"
#include "ai/playai/QPlayTrainer.h"


int main(){
    QPlayTrainer trainer = QPlayTrainer(0.);
    trainer.execute(500);
}