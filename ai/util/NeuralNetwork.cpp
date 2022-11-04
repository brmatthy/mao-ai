// Created by mats on 09/10/22.

#include "NeuralNetwork.h"
#include <cmath>
#include <iostream>

NeuralNetwork::NeuralNetwork(const int inputsize, const int hiddensize, const int hiddenlayersize,
                             const int outputsize):
        _inputsize(inputsize),
        _hiddensize(hiddensize),
        _hiddenlayersize(hiddenlayersize),
        _outputsize(outputsize),
        _outputs(new bool[outputsize])
{}

NeuralNetwork::~NeuralNetwork()
{
    delete[] _outputs;
}

void NeuralNetwork::calculate(const double* weights, const bool* inputs)
{
    //calculate hidden nodes (sigmoid)
    auto* hidden = new double[_hiddensize];
    double sigma = 0;
    int weightsIndex = 0;
    for (int i = 0; i < _hiddensize; ++i)
    {
        int layer = i / _hiddenlayersize;
        double value = 0;
        if (layer == 0)
        {
            //based on input
            for (int j = 0; j < _inputsize; ++j)
            {
                value += (inputs[j] * weights[weightsIndex]) - sigma;
                ++weightsIndex;
            }
        }
        else
        {
            //based on previous layer
            for (int j = 0; j < _hiddenlayersize; ++j)
            {
                value += (hidden[(i - _hiddenlayersize) + j] * weights[weightsIndex]) - sigma;
                ++weightsIndex;
            }
        }
        //sigmoid : changed (), may impact future ais
        hidden[i] = 1.0 / (1.0 + exp(-value));
    }
    //calculate output (perceptron)
    for (int i = 0; i < _outputsize; ++i)
    {
        //perceptron based on last layer
        double value = 0;
        for (int j = 0; j < _hiddenlayersize; ++j)
        {
            value += (hidden[(_hiddensize - _hiddenlayersize) + j] * weights[weightsIndex]) - sigma;
            ++weightsIndex;
        }
        _outputs[i] = value > 0;
    }
    delete[] hidden;
}

bool* NeuralNetwork::getOutputs()
{
    return _outputs;
}

size_t NeuralNetwork::getCompleteSize() const
{
    size_t total = 0;
    size_t last = _inputsize;
    for (size_t i = _hiddenlayersize; i <= _hiddensize; i += _hiddenlayersize)
    {
        total += last * i;
        last = i;
    }
    total += last * _outputsize;
    return total;
}
