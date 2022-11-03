// Created by mats on 12/10/22.

#include <random>
#include <iostream>
#include "GeneticAi.h"

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
