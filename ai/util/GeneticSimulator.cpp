//
// Created by mats on 12/10/22.
//

#include "GeneticSimulator.h"

GeneticSimulator::GeneticSimulator(NeuralNetwork *network)
{
    _network = network;
}

GeneticSimulator::~GeneticSimulator()
{
    //nothing yet
}

void GeneticSimulator::simulate(GeneticAi *ai)
{
    //this simulator does nothing (interface)
}
