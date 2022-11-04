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

    std::cout << "Starting simulation" << std::endl;

    //CREATE
    int size = 500;
    auto* network = new NeuralNetwork(52, 64, 64, 52);
    auto** ais = new GeneticAi*[size];
    for(int i = 0; i < size; ++i)
    {
        ais[i] = new GeneticAi(static_cast<int>(network->getCompleteSize()));
    }
    // auto* simulator = new StaticLayCardSimulator(network);
    auto* simulator = new GameLayCardSimulator(network);
    auto* algorithm = new GeneticAlgorithm(ais, size, simulator);

    // SIMULATION
    algorithm->execute(1000);
    ais[0]->clean();
    simulator->simulate(ais[0]);
    std::cout << "FINAL ai faults: " << ais[0]->faults() << std::endl;
    std::cout << *ais[0] << std::endl;

    // DELETE
    delete algorithm;
    delete simulator;
    for(int i = 0; i < size; ++i) {
        delete ais[i];
    }
}
