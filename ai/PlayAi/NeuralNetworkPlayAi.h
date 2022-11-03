// Created by mats on 03/11/22.

#pragma once

#include <deque>
#include "../util/NeuralNetworkAi.h"
#include "../util/NeuralNetwork.h"
#include "../../game/action/Action.h"
#include "../../game/card/ImmutableCard.h"
#include "../../player/interfaces/PlayInterface.h"

class NeuralNetworkPlayAi: public PlayInterface{
private:
    NeuralNetwork* _network;
    NeuralNetworkAi* _ai;
    /**
     * Helper function to calculate the network based on the stack of played cards
     * @param played The stack
     * @return a vector of the cards that could be played
     */
    std::vector<ImmutableCard> calculateFromNetwork(const std::deque<Action> &played);
public:
    /**
     * Creates a Neural Network player
     * @param network the network on which to calculate the moves
     * @param ai the ai from which to get the data.
     * !!! Make sure the sizes of the parameters are correct (input en output 52)
     */
    NeuralNetworkPlayAi(NeuralNetwork* network, NeuralNetworkAi* ai);

    /**
     * Destructor
     */
    ~NeuralNetworkPlayAi() override = default;

    /**
     * OVERRIDES FROM PLAYINTERFACE
     */

    void acceptCorrection(CorrectionStatus status) override;

    int play(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) override;

    bool wantsCard(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) override;
};
