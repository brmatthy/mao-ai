//
// Created by brent on 18/10/22.
//

#ifndef MAO_AI_PLAYBOT_H
#define MAO_AI_PLAYBOT_H


#include "../interfaces/PlayInterface.h"

class PlayBot : public PlayInterface{
private:
    static int getGoodCardIndex(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards);
public:
    int play(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) override;

    bool wantsCard(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) override;

    void acceptCorrection(const Correction &correction) override;

};


#endif //MAO_AI_PLAYBOT_H
