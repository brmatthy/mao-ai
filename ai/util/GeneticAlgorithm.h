//
// Created by mats on 12/10/22.
//

#ifndef MAO_AI_GENETICALGORITHM_H
#define MAO_AI_GENETICALGORITHM_H

#include "GeneticAi.h"
#include "NeuralNetwork.h"
#include "GeneticSimulator.h"

class GeneticAlgorithm {
private:
    GeneticAi** _ais;
    int _aiSize;
    GeneticSimulator* _simulator;
public:
    /**
     * Initialize a genetic algorithm
     * @param startAis starting Ai list
     * @param network the network on which the AIs will be checked
     * @param simulator the simulator to run an iteration
     */
    GeneticAlgorithm(GeneticAi** startAis, int aiSize, GeneticSimulator* simulator);

    /**
     * Deletes a Genetic Algorithm and all its data
     */
    ~GeneticAlgorithm();

    /**
     * Simulate n generations of the network
     * @param iterations number of iterations
     */
    void simulate(int iterations);
};


#endif //MAO_AI_GENETICALGORITHM_H
