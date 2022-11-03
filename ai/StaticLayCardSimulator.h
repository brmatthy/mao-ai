// Created by mats on 16/10/22.

#pragma once

#include "util/Simulator.h"
#include "util/NeuralNetwork.h"

class StaticLayCardSimulator: public Simulator {
public:
    /**
    * Creat a Simulator to simulate games
    * @param network the network from which to get the AI data
    */
    explicit StaticLayCardSimulator(NeuralNetwork* network);

    /**
     * Simulate a game for a single AI, and do the incrementFaults corrections
     * @param ai the ai for which to simulate.
     */
    void simulate(GeneticAi* ai) final;
};
