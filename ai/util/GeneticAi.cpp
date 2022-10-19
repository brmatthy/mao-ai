//
// Created by mats on 12/10/22.
//

#include <random>
#include "GeneticAi.h"

GeneticAi::GeneticAi(int size):
    _weights(new double[size]),
    _size(size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-1, 1); //TODO VERSLAG: -1 was een 0, dit gaf altijd output true
    for(int i = 0; i < _size; i++)
    {
        _weights[i] = dist(gen);
    }
}

GeneticAi::GeneticAi(double* weights, int size):
    _weights(weights),
    _size(size)
{}

GeneticAi::~GeneticAi()
{
    delete[] _weights;
}

void GeneticAi::clean()
{
    _faults = 0;
}

void GeneticAi::correct(const Correction& correction)
{
    _faults++;
}

int GeneticAi::faults() const
{
    return _faults;
}

GeneticAi* GeneticAi::crossover(const GeneticAi& other)
{
    if(other._size != _size)
    {
        return nullptr;
    }
    auto* new_weights = new double[_size];
    for(int i = 0; i < _size; i++)
    {
        if(i < _size / 2)
        {
            new_weights[i] = _weights[i];
        }
        else
        {
            new_weights[i] = other._weights[i];
        }
    }
    return new GeneticAi(new_weights, _size);
}

int GeneticAi::getSize() const
{
    return _size;
}

double *GeneticAi::getWeights()
{
    return _weights;
}

void GeneticAi::mutate()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, _size-1);
    int index1 = dist(gen);
    int index2 = dist(gen);
    double temp = _weights[index1];
    _weights[index1] = _weights[index2];
    _weights[index2] = temp;
}

std::ostream& operator<<(std::ostream& out, const GeneticAi& ai)
{
    out << "[ ";
    for(int i = 0; i < ai._size; i++)
    {
        if(i != 0) out << ", ";
        out << "\"" << ai._weights[i] << "\"";
    }
    out << "]";
    return out;
}
