// Created by mats on 12/10/22.

#pragma once

#include "NeuralNetworkAi.h"

class GeneticAi: public NeuralNetworkAi {
public:
    /**
     * Create a new geneticAi, weights are set randomly
     * @param size the size of the weights array
     */
    explicit GeneticAi(const int size): NeuralNetworkAi(size){};

    /**
     * Create a new genetic AI with starting weights
     * @param weights starting weights (do not need to delete)
     * @param size the weights size
     */
    GeneticAi(double* weights, const int size): NeuralNetworkAi(weights, size){};

    /**
     * Delete the geneticAI
     */
    ~GeneticAi() = default;

    /**
     * Crossover with another AI
     * @param other the other AI to crossover with
     * @return a new GeneticAI
     */
     GeneticAi* crossover(const GeneticAi& other);

     /**
      * Mutate the AI slightly
      */
     void mutate();
};
