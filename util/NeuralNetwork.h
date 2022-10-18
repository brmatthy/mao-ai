//
// Created by mats on 09/10/22.
//

#ifndef MAO_AI_NEURALNETWORK_H
#define MAO_AI_NEURALNETWORK_H

/**
 * A Layered Neural Network with many inputs and many outputs.
 * x1...xn -> y1...yn (wx - 0)
 */
class NeuralNetwork {
private:
    int _inputsize;
    int _hiddensize;
    int _hiddenlayersize;
    int _outputsize;

    bool* _outputs;
public:
    /**
     * Create a new Neural Network.
     * @param inputsize defines the amount of input nodes x
     * @param hiddensize defines the amount of hidden nodes
     * @param hiddenlayersize defines the hidden layer size
     * @param outputsize defines the amount of ouput nodes y
     */
    NeuralNetwork(int inputsize, int hiddensize, int hiddenlayersize, int outputsize);

    /**
     * Deletes a Neural Network and all its allocated memory
     */
    ~NeuralNetwork();

    /**
     * Calculate the new output values of the network based on the weights and input values \n
     * !!! size should be correct && weights order also !!!
     * @param weights gives the weight values for which to calculate the network.
     * @param inputs gives the input values for which to calculate the network.
     */
    void calculate(const double* weights, const bool* inputs);

    bool* getOutputs();
};


#endif //MAO_AI_NEURALNETWORK_H
