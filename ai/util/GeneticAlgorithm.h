//
// Created by mats on 12/10/22.
//

#ifndef MAO_AI_GENETICALGORITHM_H
#define MAO_AI_GENETICALGORITHM_H

#include "GeneticAi.h"
#include "NeuralNetwork.h"
#include "NeuralNetworkSimulator.h"
#include "Algorithm.h"

class GeneticAlgorithm: public Algorithm {
private:
    GeneticAi** _ais;
    int _aiSize;
    NeuralNetworkSimulator* _simulator;
    int _best = 52*52;
    int _avg = 52*52;
public:
    /**
     * Initialize a genetic algorithm
     * @param startAis starting Ai list
     * @param network the network on which the AIs will be checked
     * @param simulator the simulator to run an iteration
     */
    GeneticAlgorithm(GeneticAi** startAis, int aiSize, NeuralNetworkSimulator* simulator);

    /**
     * Deletes a Genetic Algorithm and all its data
     */
    ~GeneticAlgorithm() override = default;

    /**
     * Simulate n generations of the network
     * @param iterations number of generations
     */
    void execute(int iterations) override;

    /**
     * Print the current algorithm state (best and average)
     * @param out the output stream to write to.
     */
    void print(std::ostream& out) const;
};


#endif //MAO_AI_GENETICALGORITHM_H
