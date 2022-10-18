//
// Created by mats on 16/10/22.
//

#include "LayCardSimulator.h"
#include "../game/validation/PlayValidation.h"

LayCardSimulator::LayCardSimulator(NeuralNetwork* network): GeneticSimulator(network) {}

LayCardSimulator::~LayCardSimulator() {}

void LayCardSimulator::simulate(GeneticAi* ai)
{
    Correction correction(INVALID_CARD, nullptr, std::vector<Act>());
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
                    if(output[outindex])
                    {
                        ImmutableCard card(static_cast<CardType>(type), static_cast<CardNumber>(number));
                        ImmutableCard played(static_cast<CardType>(outtype), static_cast<CardNumber>(outnumber));
                        if(!playedCorrectCard(&card, &played))
                        {
                           ai->correct(&correction);
                        }
                    }
                    outindex++;
                }
            }
            index++;
        }
    }
}