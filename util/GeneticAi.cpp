//
// Created by mats on 12/10/22.
//

#include <random>
#include "GeneticAi.h"

GeneticAi::GeneticAi(int size)
{
    _size = size;
    _faults = 0;
    _weights = new double[size];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-1, 1); //TODO VERSLAG: -1 was een 0, dit gaf altijd output true
    for(int i = 0; i < _size; i++)
    {
        _weights[i] = dist(gen);
    }
}

GeneticAi::GeneticAi(double* weights, int size)
{
    _size = size;
    _weights = weights;
}

GeneticAi::~GeneticAi()
{
    delete[] _weights;
}

void GeneticAi::clean()
{
    _faults = 0;
}

void GeneticAi::correct(Correction* correction)
{
    _faults++;
}

int GeneticAi::faults()
{
    return _faults;
}

GeneticAi* GeneticAi::crossover(GeneticAi *other)
{
    if(other->_size != this->_size)
    {
        return nullptr;
    }
    double* new_weights = new double[_size];
    for(int i = 0; i < _size; i++)
    {
        if(i < _size / 2)
        {
            new_weights[i] = this->_weights[i];
        }
        else
        {
            new_weights[i] = other->_weights[i];
        }
    }
    return new GeneticAi(new_weights, _size);
}

int GeneticAi::getSize()
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
    std::uniform_int_distribution<> dist(0, _size);
    int index1 = dist(gen);
    int index2 = dist(gen);
    double temp = _weights[index1];
    _weights[index1] = _weights[index2];
    _weights[index2] = temp;
}
