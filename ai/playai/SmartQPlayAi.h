//
// Created by brent on 4/11/22.
//

#ifndef MAO_AI_SMARTQPLAYAI_H
#define MAO_AI_SMARTQPLAYAI_H


#include "../../game/card/ImmutableCard.h"
#include "PlayAi.h"
#include "../q_learning/Qmodel.h"
#include "../../game/validation/ActValidation.h"
#include "../../util/EnumToVector.h"

class SmartQPlayAi: public PlayAi{
private:
    Qmodel<ImmutableCard, ImmutableCard> _qmodel;
    ImmutableCard _lastState = ImmutableCard(CardType::NONE, CardNumber::NONE);
    ImmutableCard _lastAct = ImmutableCard(CardType::NONE, CardNumber::NONE);

    void reward();
    void punish();
    void generalUpdate(double reward);
public:
    SmartQPlayAi(double alpha);

    void acceptCorrection(CorrectionStatus status) override;

    int play(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) override;

    bool wantsCard(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) override;

};


#endif //MAO_AI_SMARTQPLAYAI_H
