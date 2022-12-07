// Created by mats on 07/12/22.

#pragma once

#include "../util/NeuralNetworkAi.h"
#include "../util/NeuralNetwork.h"
#include "../../game/action/Action.h"
#include "../../game/card/ImmutableCard.h"
#include "../../player/interfaces/ActInterface.h"


class NeuralNetworkActAi: public ActInterface
{
private:
    NeuralNetwork* _network;
    NeuralNetworkAi* _ai;
public:
    /**
    * Creates a Neural Network player
    * @param network the network on which to calculate the moves
    * @param ai the ai from which to get the data.
    * !!! Make sure the sizes of the parameters are correct (input en output 52)
    */
    NeuralNetworkActAi(NeuralNetwork* network, NeuralNetworkAi* ai);

    /**
     * Destructor
     */
    ~NeuralNetworkActAi() override = default;

    /**
     * OVERRIDES FROM ActInterface
     */
    void acceptCorrection(CorrectionStatus status) override;

    const std::unordered_set<Act> act(const std::deque<Action>& played, const ImmutableCard* played_card) override;
};
