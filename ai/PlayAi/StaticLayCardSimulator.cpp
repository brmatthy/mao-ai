// Created by mats on 16/10/22.

#include "StaticLayCardSimulator.h"
#include "../../game/validation/PlayValidation.h"
#include "../../util/EnumToVector.h"

StaticLayCardSimulator::StaticLayCardSimulator(NeuralNetwork* network): NeuralNetworkSimulator(network) {}

void StaticLayCardSimulator::simulate(NeuralNetworkAi* ai)
{
    int index = 0;
    bool input[52];
    for(bool & i : input)
    {
        i = false;
    }
    for(const CardType type : EnumToVector::getCardTypeVector())
    {
        for(const CardNumber number : EnumToVector::getCardNumberVector())
        {
            input[index] = true;
            _network->calculate(ai->getWeights(), input);
            const bool* output = _network->getOutputs();
            input[index] = false;
            int outindex = 0;
            for(const CardType outtype : EnumToVector::getCardTypeVector())
            {
                for(const CardNumber outnumber : EnumToVector::getCardNumberVector())
                {
                    const ImmutableCard card(type, number);
                    const ImmutableCard played(outtype, outnumber);
                    const bool didplay = output[outindex];
                    const bool mustplay = playedCorrectCard(&card, &played);
                    if(didplay != mustplay)
                    {
                        ai->incrementFaults();
                    }
                    ++outindex;
                }
            }
            ++index;
        }
    }
}
