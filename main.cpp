// Created by brent on 1/10/22.

#include <iostream>
#include "ai/ActAi/QActTrainer.h"
#include "ai/playai/QPlayTrainer.h"

#include "ai/StaticLayCardSimulator.h"
#include "ai/util/GeneticAi.h"
#include "ai/util/GeneticAlgorithm.h"
#include "ai/util/NeuralNetwork.h"
#include "ai/GameLayCardSimulator.h"

int main(){
    auto trainer = QActTrainer(0.1);
    trainer.execute(1000);
}

