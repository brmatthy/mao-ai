//
// Created by mats on 12/10/22.
//

#include <iostream>
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
    for(int generation = 1; generation <= iterations; generation++)
    {
        std::cout << "Generation: " << generation << std::endl;
        // simulate every AI
        for(int i = 0; i < _aiSize; i++)
        {
            _simulator->simulate(_ais[i]);
        }
        //TODO
        // sort based on faults
        std::cout << "BEST ai faults: " << _ais[0]->faults() << std::endl;
        for(int i = _aiSize / 2; i < _aiSize; i++)
        {
            //delete the worst ais
            //delete _ais[i];
            //crossover
            //_ais[i] = ;
        }
        for(int i = 0; i < _aiSize; i++)
        {

        }
        // mutate random
        // clean the ais
    }
}