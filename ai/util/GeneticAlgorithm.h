//
// Created by mats on 12/10/22.
//

#ifndef MAO_AI_GENETICALGORITHM_H
#define MAO_AI_GENETICALGORITHM_H

#include "GeneticAi.h"
#include "NeuralNetwork.h"
#include "Simulator.h"
#include "Algorithm.h"

class GeneticAlgorithm: public Algorithm {
private:
    GeneticAi** _ais;
    int _aiSize;
    Simulator* _simulator;
    int _best;
    int _avg;
public:
    /**
     * Initialize a genetic algoritm
     * @param startAis starting Ai list
     * @param network the network on which the AIs will be checked
     * @param simulator the simulator to run an iteration
     */
    GeneticAlgorithm(GeneticAi** startAis, int aiSize, Simulator* simulator);

    /**
     * Deletes a Genetic Algorithm and all its data
     */
    virtual ~GeneticAlgorithm() = default;

    /**
     * Simulate n generations of the network
     * @param generations number of iterations
     */
    void execute(int generations) final;

    /**
     * Print the current algorithm state (best and average)
     * @param out the output stream to write to.
     */
    void print(std::ostream& out) const;
};


#endif //MAO_AI_GENETICALGORITHM_H
