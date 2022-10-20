// Created by mats on 12/10/22.

#include <random>
#include "GeneticAi.h"

GeneticAi::GeneticAi(const int size):
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

GeneticAi::GeneticAi(double* const weights, int const size):
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

void GeneticAi::correct(const Correction&)
{
    ++_faults;
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
    auto* const new_weights = new double[_size];
    const int divider = _size / 2;
    for(int i = 0; i < _size; ++i)
    {
        if(i < divider)
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

void GeneticAi::mutate() {
    const int number_of_mutations = 6;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, _size - 1);
    std::uniform_real_distribution<double> valdist(-1, 1);
    for(int i = 0; i < number_of_mutations; ++i)
    {
        _weights[dist(gen)] = valdist(gen);
    }
}

std::ostream& operator<<(std::ostream& out, const GeneticAi& ai)
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
