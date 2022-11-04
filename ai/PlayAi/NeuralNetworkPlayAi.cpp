// Created by mats on 03/11/22.

#include <algorithm>
#include "NeuralNetworkPlayAi.h"
#include "../../game/validation/ActValidation.h"
#include "../../util/EnumToVector.h"

NeuralNetworkPlayAi::NeuralNetworkPlayAi(NeuralNetwork *network, NeuralNetworkAi *ai):
    _network(network),
    _ai(ai)
{}

std::vector<ImmutableCard> NeuralNetworkPlayAi::calculateFromNetwork(const std::deque<Action> &played)
{
    bool input[52];
    for(bool & i : input)
    {
        i = false;
    }
    const ImmutableCard* lastCard = played.at(played.size() - getTopCardReversedIndex(played)).getCard();
    input[getCardIndex(lastCard)] = true;
    _network->calculate(_ai->getWeights(), input);
    const bool* output = _network->getOutputs();

    std::vector<ImmutableCard> wantsToPlay;
    for(const CardType outtype : EnumToVector::getCardTypeVector())
    {
        for(const CardNumber outnumber : EnumToVector::getCardNumberVector())
        {
            const ImmutableCard played(outtype, outnumber);
            const bool didplay = output[getCardIndex(&played)];
            if(didplay)
            {
                wantsToPlay.push_back(played);
            }
        }
    }
    return wantsToPlay;
}

void NeuralNetworkPlayAi::acceptCorrection(CorrectionStatus status)
{
    _ai->incrementFaults();
}

int NeuralNetworkPlayAi::play(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards)
{
    auto wantsToPlay = calculateFromNetwork(played);
    for (int i = 0; i < playerCards.size(); ++i)
    {
        auto* inhand = playerCards.at(i);
        for (ImmutableCard willPlay : wantsToPlay)
        {
            if ((willPlay.getCardNumber() == inhand->getCardNumber()) && (willPlay.getCardType() == inhand->getCardType()))
            {
                return i;
            }
        }
    }
}

bool NeuralNetworkPlayAi::wantsCard(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards)
{
    auto wantsToPlay = calculateFromNetwork(played);
    bool wantsCard = true;
    for (const ImmutableCard* inhand : playerCards)
    {
        for (ImmutableCard willPlay : wantsToPlay)
        {
            if ((willPlay.getCardNumber() == inhand->getCardNumber()) && (willPlay.getCardType() == inhand->getCardType()))
            {
                wantsCard = false;
                break;
            }
        }
    }
    //small penalty for taking a card to discourage this
    if(wantsCard)
    {
        _ai->incrementFaults();
        _ai->incrementFaults();
    }
    return wantsCard;
}