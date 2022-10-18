//
// Created by brent on 15/10/22.
//

#ifndef MAO_AI_BOT_H
#define MAO_AI_BOT_H

#include "Player.h"

class bot : public Player{
private:
    int getGoodCardIndex();
public:
    const ImmutableCard *play() override;

    const std::unordered_multiset<Act> act(const std::deque<Action> &played, const ImmutableCard *played_card) override;

    bool myTurn() override;

    bool wantsCard() override;

    void acceptCorrection(const Correction &correction) override;

};


#endif //MAO_AI_BOT_H


