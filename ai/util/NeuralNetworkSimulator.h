// Created by mats on 12/10/22.

#pragma once

#include "Simulator.h"
#include "NeuralNetwork.h"
#include "NeuralNetworkAi.h"

class NeuralNetworkSimulator: public Simulator<NeuralNetworkAi> {
protected:
    NeuralNetwork* _network;
public:
    /**
     * Creat a NeuralNetworkSimulator to simulate games
     * @param network the network from which to get the AI data
     */
    explicit NeuralNetworkSimulator(NeuralNetwork* network): _network(network) {};

    ~NeuralNetworkSimulator() override = default;

    /**
     * Simulate a game for a single AI, and do the correct corrections
     * @param ai the ai for which to simulate.
     */
    void simulate(NeuralNetworkAi* ai) override = 0;
};
