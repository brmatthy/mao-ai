// Created by mats on 07/12/22.
#include "NeuralNetworkActAi.h"
#include "../../game/validation/ActValidation.h"
#include "../../util/EnumToVector.h"

NeuralNetworkActAi::NeuralNetworkActAi(NeuralNetwork* network, NeuralNetworkAi* ai):
    _network(network),
    _ai(ai)
{}

void NeuralNetworkActAi::acceptCorrection(CorrectionStatus status)
{
    _ai->incrementFaults();
}

const std::unordered_set<Act>
NeuralNetworkActAi::act(const std::deque<Action>& played, const ImmutableCard* playedCard)
{
    if(playedCard == nullptr)
    {
        return std::unordered_set<Act>();
    }
    bool input[52*4];
    for(bool & i : input)
    {
        i = false;
    }
    input[getCardIndex(playedCard)] = true;
    size_t index = 0;
    for(size_t i = 1; i < 4; ++i)
    {
        ImmutableCard const* newcard = nullptr;
        while ((index < played.size()) && (newcard == nullptr))
        {
            newcard = played.at(index).getCard();
            ++index;
        }
        if(newcard != nullptr)
        {
            input[getCardIndex(newcard)+(i*52)] = true;
        }
    }
    _network->calculate(_ai->getWeights(), input);
    const bool* output = _network->getOutputs();

    std::unordered_set<Act> toDo;
    std::vector<Act> actvector = EnumToVector::getActVector();
    for(const Act act : actvector)
    {
        const bool didplay = output[getActIndex(&act)];
        if(didplay)
        {
            toDo.insert(act);
        }
    }
    return toDo;
}
