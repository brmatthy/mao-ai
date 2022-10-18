//
// Created by brent on 1/10/22.
//



#include <iostream>
#include "ai/LayCardSimulator.h"
#include "util/GeneticAi.h"
#include "util/GeneticAlgorithm.h"
#include "util/NeuralNetwork.h"

int main(){

    std::cout << "Starting simulation" << std::endl;

    //CREATE
    int size = 100;
    auto* network = new NeuralNetwork(52, 10, 10, 52);
    auto** ais = new GeneticAi*[size];
    for(int i = 0; i < size; i++)
    {
        ais[i] = new GeneticAi(52*10+10*10+52*10);
    }
    LayCardSimulator* simulator = new LayCardSimulator(network);
    GeneticAlgorithm* algorithm = new GeneticAlgorithm(ais, size, simulator);

    // SIMULATION
    algorithm->simulate(100);
    ais[0]->clean();
    simulator->simulate(ais[0]);
    for(int i = 0; i < 52; i++)
    {
        std::cout << network->getOutputs()[i] << std::endl;
    }
    std::cout << "end ai faults: " << ais[0]->faults() << std::endl;

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