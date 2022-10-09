//
// Created by mats on 09/10/22.
//

#include "NeuralNetwork.h"
#include <math.h>

NeuralNetwork::NeuralNetwork(int inputsize, int hiddensize, int hiddenlayersize, int outputsize)
{
    _inputsize = inputsize;
    _hiddensize = hiddensize;
    _hiddenlayersize = hiddenlayersize;
    _outputsize = outputsize;
    _outputs = new bool[_outputsize];
}

NeuralNetwork::~NeuralNetwork()
{
    delete[] _outputs;
}

void NeuralNetwork::calculate(const double* weights, const bool* inputs)
{
    //calculate hidden nodes (sigmoid)
    double* hidden = new double[_hiddensize];
    double sigma = 0;
    int weights_index = 0;
    for(int i = 0; i < _hiddensize; i++)
    {
        int layer = i / _hiddenlayersize;
        double value = 0;
        if(layer == 0)
        {
            //based on input
            for(int j = 0; j < _inputsize; j++)
            {
                value += inputs[j]*weights[weights_index] - sigma;
                weights_index++;
            }
        }
        else
        {
            //based on previous layer
            for(int j = 0; j < _hiddenlayersize; j++)
            {
                value += hidden[i-_hiddenlayersize+j]*weights[weights_index] - sigma;
                weights_index++;
            }
        }
        //sigmoid
        hidden[i] = 1.0 / 1.0 + exp(-value);
    }
    //calculate output (perceptron)
    for(int i = 0; i < _outputsize; i++)
    {
        //perceptron based on last layer
        double value = 0;
        for(int j = 0; j < _hiddenlayersize; j++)
        {
            value += hidden[_hiddensize-_hiddenlayersize+j]*weights[weights_index] - sigma;
            weights_index++;
        }
        _outputs[i] = value > 0;
    }
}

bool* NeuralNetwork::getOutputs()
{
    return _outputs;
}
