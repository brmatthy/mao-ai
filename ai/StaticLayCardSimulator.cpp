// Created by mats on 16/10/22.

#include "StaticLayCardSimulator.h"
#include "../game/validation/PlayValidation.h"

StaticLayCardSimulator::StaticLayCardSimulator(NeuralNetwork* network): Simulator(network) {}

void StaticLayCardSimulator::simulate(GeneticAi* ai)
{
    int index = 0;
    bool input[52];
    for(bool & i : input)
    {
        i = false;
    }
    for(int type = HEARTS; type <= SPADES; type++)
    {
        for(int number = ACE; number <= KING; number++)
        {
            input[index] = true;
            _network->calculate(ai->getWeights(), input);
            bool* output = _network->getOutputs();
            input[index] = false;
            int outindex = 0;
            for(int outtype = HEARTS; outtype <= SPADES; outtype++)
            {
                for (int outnumber = ACE; outnumber <= KING; outnumber++) 
                {
                    ImmutableCard card(static_cast<CardType>(type), static_cast<CardNumber>(number));
                    ImmutableCard played(static_cast<CardType>(outtype), static_cast<CardNumber>(outnumber));
                    bool didplay = output[outindex];
                    bool mustplay = playedCorrectCard(&card, &played);
                    if(didplay != mustplay)
                    {
                       ai->correct();
                    }
                    outindex++;
                }
            }
            index++;
        }
    }
}