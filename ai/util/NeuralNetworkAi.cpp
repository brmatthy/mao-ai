// Created by mats on 31/10/22.

#include <random>
#include "NeuralNetworkAi.h"

NeuralNetworkAi::NeuralNetworkAi(const int size):
        _weights(new double[size]),
        _size(size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-1, 1);
    for(int i = 0; i < _size; ++i)
    {
        _weights[i] = dist(gen);
    }
}

NeuralNetworkAi::NeuralNetworkAi(double* const weights, int const size):
        _weights(weights),
        _size(size)
{}

NeuralNetworkAi::~NeuralNetworkAi()
{
    delete[] _weights;
}

int NeuralNetworkAi::getSize() const
{
    return _size;
}

double* NeuralNetworkAi::getWeights()
{
    return _weights;
}

std::ostream& operator<<(std::ostream& out, const NeuralNetworkAi& ai)
{
    out << "[ ";
    for(int i = 0; i < ai._size; ++i)
    {
        if(i != 0) {out << ", ";}
        out << "\"" << ai._weights[i] << "\"";
    }
    out << "]";
    return out;
}