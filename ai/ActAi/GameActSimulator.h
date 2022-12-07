// Created by mats on 07/12/22.

#pragma once

#include "../util/NeuralNetworkSimulator.h"

class GameActSimulator: public NeuralNetworkSimulator
{
public:
    /**
    * Creat a NeuralNetworkSimulator to simulate games
    * @param network the network from which to get the AI data
    */
    explicit GameActSimulator(NeuralNetwork* network);

    /**
     * Simulate a game for a single AI, and do the incrementFaults corrections
     * @param ai the ai for which to simulate.
     */
    void simulate(NeuralNetworkAi* ai) final;
};
