// Created by mats on 31/10/22.

#pragma once

#include <ostream>
#include "Ai.h"

class NeuralNetworkAi: public Ai{
protected:
    double* _weights;
    int _size;
public:
    /**
     * Create a new Ai, weights are set randomly
     * @param size the size of the weights array
     */
    explicit NeuralNetworkAi(const int size);

    /**
     * Create a new AI with starting weights
     * @param weights starting weights (do not need to delete)
     * @param size the weights size
     */
    NeuralNetworkAi(double* weights, int size);

    /**
     * Delete the NeuralNetworkAi
     */
    ~NeuralNetworkAi();

    /**
      * Get the Ai weights
      * @return the weights as a double array
      */
    double* getWeights();

    /**
     * Get the Ai weight size
     * @return the ai weight size
     */
    int getSize() const;

    /**
      * Prints the AI state (weights) as a string representing the weights array
      * @param out the output stream to write to.
      * @param ai the ai to write.
      * @return an output stream to continue the chain.
      */
    friend std::ostream& operator<<(std::ostream& out, const NeuralNetworkAi& ai);
};
