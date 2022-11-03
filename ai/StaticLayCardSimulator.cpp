// Created by mats on 16/10/22.

#include "StaticLayCardSimulator.h"
#include "../game/validation/PlayValidation.h"
#include "../util/EnumToVector.h"

StaticLayCardSimulator::StaticLayCardSimulator(NeuralNetwork* network): Simulator(network) {}

void StaticLayCardSimulator::simulate(GeneticAi* ai)
{
    int index = 0;
    bool input[52];
    for(bool & i : input)
    {
        i = false;
    }
    for(CardType type : EnumToVector::getCardTypeVector())
    {
        for(CardNumber number : EnumToVector::getCardNumberVector())
        {
            input[index] = true;
            _network->calculate(ai->getWeights(), input);
            bool* output = _network->getOutputs();
            input[index] = false;
            int outindex = 0;
            for(CardType outtype : EnumToVector::getCardTypeVector())
            {
                for(CardNumber outnumber : EnumToVector::getCardNumberVector())
                {
                    ImmutableCard card(type, number);
                    ImmutableCard played(outtype, outnumber);
                    bool didplay = output[outindex];
                    bool mustplay = playedCorrectCard(&card, &played);
                    if(didplay != mustplay)
                    {
                        ai->incrementFaults();
                    }
                    outindex++;
                }
            }
            index++;
        }
    }
}