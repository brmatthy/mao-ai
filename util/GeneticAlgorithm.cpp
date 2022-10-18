//
// Created by mats on 12/10/22.
//

#include <iostream>
#include <random>
#include <algorithm>
#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(GeneticAi** startAis, int aiSize, GeneticSimulator* simulator)
{
    _ais = startAis;
    _aiSize = aiSize;
    _simulator = simulator;
}

GeneticAlgorithm::~GeneticAlgorithm()
{
    // everything created at construction no need for deletion
}

void GeneticAlgorithm::simulate(int iterations)
{
    int min = 52*52;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(10, _aiSize-1);
    std::uniform_int_distribution<> disthalve(0, 10);
    for(int generation = 1; generation <= iterations; generation++)
    {
        // simulate every AI
        for(int i = 0; i < _aiSize; i++)
        {
            _simulator->simulate(_ais[i]);
        }
        //Sort array based on faults
        std::sort(_ais, _ais + _aiSize);
        if(_ais[0]->faults() < min)
        {
            min = _ais[0]->faults();
            std::cout << "Generation: " << generation << " | " << min << " faults!" << std::endl;
        }
        for(int i = _aiSize / 2; i < _aiSize; i++)
        {
            //delete the worst ais
            delete _ais[i];
            //crossover
            _ais[i] = _ais[disthalve(gen)]->crossover(_ais[disthalve(gen)]);
        }
        // mutate random
        for(int r = 0; r < 20; r++)
        {
            _ais[dist(gen)]->mutate();
        }
        for(int i = 0; i < _aiSize; i++)
        {
            // clean the ais
            _ais[i]->clean();
        }
    }
}