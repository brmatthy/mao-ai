//
// Created by mats on 12/10/22.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>
#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(GeneticAi** startAis, int aiSize, GeneticSimulator* simulator)
{
    _ais = startAis;
    _aiSize = aiSize;
    _simulator = simulator;
    _avg = 52*52;
    _best = 52*52;
}

GeneticAlgorithm::~GeneticAlgorithm()
{
    // everything created at construction no need for deletion
}

void GeneticAlgorithm::simulate(int iterations)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 10);
    std::ofstream file ("geneticAI");
    for(int generation = 1; generation <= iterations; generation++)
    {
        // simulate every AI
        int newavg = 0;
        for(int i = 0; i < _aiSize; i++)
        {
            _simulator->simulate(_ais[i]);
            newavg += _ais[i]->faults();
        }
        newavg = newavg / _aiSize;
        //Sort array based on faults
        std::sort(_ais, _ais + _aiSize,[] (GeneticAi *lhs, GeneticAi *rhs) {
                     return lhs->faults() < rhs->faults();
        });
        for(int i = _aiSize / 2; i < _aiSize; i++)
        {
            //delete the worst ais
            delete _ais[i];
            //crossover
            _ais[i] = _ais[dist(gen)]->crossover(_ais[dist(gen)]);
            //mutate
            _ais[i]->mutate();
        }

        // Change state
        int newbest = _ais[0]->faults();
        bool changed = false;
        if(newbest < _best)
        {
            _best = newbest;
            changed = true;
        }
        if(newavg < _avg)
        {
            _avg = newavg;
            changed = true;
        }

        for(int i = 0; i < _aiSize; i++)
        {
            // clean the ais
            _ais[i]->clean();
        }

        //PRINT
        print(file);
        if(changed)
        {
            std::cout << "Generation: " << generation << " | ";
            print(std::cout);
        }
    }
}

void GeneticAlgorithm::print(std::ostream& out) const
{
    out << _best << " faults" <<  " | " << _avg << " avg." << std::endl;
}