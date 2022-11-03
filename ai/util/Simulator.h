//
// Created by mats on 12/10/22.
//

#ifndef MAO_AI_SIMULATOR_H
#define MAO_AI_SIMULATOR_H

#include "GeneticAi.h"
#include "NeuralNetwork.h"

class Simulator {
protected:
    NeuralNetwork *_network;
public:
    /**
     * Creat a Simulator to simulate games
     * @param network the network from which to get the AI data
     */
    explicit Simulator(NeuralNetwork *network) : _network(network) {}

    virtual ~Simulator() = default;

    /**
     * Simulate a game for a single AI, and do the incrementFaults corrections
     * @param ai the ai for which to simulate.
     */
    virtual void simulate(GeneticAi *ai) = 0;
};


#endif //MAO_AI_SIMULATOR_H
