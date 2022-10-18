//
// Created by mats on 16/10/22.
//

#ifndef MAO_AI_LAYCARDSIMULATOR_H
#define MAO_AI_LAYCARDSIMULATOR_H

#include "../util/GeneticSimulator.h"
#include "../util/NeuralNetwork.h"

class LayCardSimulator: public GeneticSimulator {
public:
    /**
    * Creat a Simulator to simulate games
    * @param network the network from which to get the AI data
    */
    LayCardSimulator(NeuralNetwork* network);

    /**
     * Destroy this simulator
     */
    ~LayCardSimulator();

    /**
     * Simulate a game for a single AI, and do the correct corrections
     * @param ai the ai for which to simulate.
     */
    virtual void simulate(GeneticAi* ai);
};


#endif //MAO_AI_LAYCARDSIMULATOR_H
