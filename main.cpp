//
// Created by brent on 1/10/22.
//



#include <iostream>
#include "ai/LayCardSimulator.h"
#include "ai/LayCardAi.h"
#include "util/GeneticAlgorithm.h"
#include "util/NeuralNetwork.h"

int main(){

    std::cout << "Hello world";
    NeuralNetwork* network = new NeuralNetwork(52, 10, 5, 52);
    delete network;
}