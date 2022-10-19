//
// Created by brent on 1/10/22.
//



#include <iostream>

#include "ai/LayCardSimulator.h"
#include "ai/util/GeneticAi.h"
#include "ai/util/GeneticAlgorithm.h"
#include "ai/util/NeuralNetwork.h"

int main(){

    std::cout << "Starting simulation" << std::endl;

    //CREATE
    int size = 100;
    auto* network = new NeuralNetwork(52, 64, 64, 52);
    auto** ais = new GeneticAi*[size];
    for(int i = 0; i < size; i++)
    {
        ais[i] = new GeneticAi(64*52*2);
    }
    auto* simulator = new LayCardSimulator(network);
    auto* algorithm = new GeneticAlgorithm(ais, size, simulator);

    // SIMULATION
    algorithm->execute(100000);
    ais[0]->clean();
    simulator->simulate(ais[0]);
    std::cout << "FINAL ai faults: " << ais[0]->faults() << std::endl;
    ais[0]->print(std::cout);

    // DELETE
    delete algorithm;
    delete simulator;
    for(int i = 0; i < size; i++)
    {
        delete ais[i];
    }
    delete[] ais;
    delete network;
    std::cout << "Done!" << std::endl;
}