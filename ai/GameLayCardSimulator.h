// Created by mats on 31/10/22.

#pragma once

#include "util/Simulator.h"

class GameLayCardSimulator: public Simulator {
public:
    /**
    * Creat a Simulator to simulate games
    * @param network the network from which to get the AI data
    */
    explicit GameLayCardSimulator(NeuralNetwork* network);

    /**
     * Simulate a game for a single AI, and do the correct corrections
     * @param ai the ai for which to simulate.
     */
    void simulate(GeneticAi* ai) final;
};
