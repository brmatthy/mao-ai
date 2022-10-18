//
// Created by mats on 12/10/22.
//

#ifndef MAO_AI_GENETICSIMULATOR_H
#define MAO_AI_GENETICSIMULATOR_H

#include "GeneticAi.h"
#include "NeuralNetwork.h"

class GeneticSimulator {
protected:
    NeuralNetwork* _network;
public:
    /**
     * Creat a Simulator to simulate games
     * @param network the network from which to get the AI data
     */
    GeneticSimulator(NeuralNetwork* network);

    /**
     * Destroy this simulator
     */
    ~GeneticSimulator();

    /**
     * Simulate a game for a single AI, and do the correct corrections
     * @param ai the ai for which to simulate.
     */
    virtual void simulate(GeneticAi* ai);
};


#endif //MAO_AI_GENETICSIMULATOR_H
