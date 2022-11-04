//
// Created by brent on 3/11/22.
//

#ifndef MAO_AI_QPLAYAI_H
#define MAO_AI_QPLAYAI_H


#include "../q_learning/Qmodel.h"
#include "../../game/card/ImmutableCard.h"
#include "../../player/interfaces/PlayInterface.h"
#include "../../game/validation/ActValidation.h"
#include "../util/Ai.h"

class QPlayAI: public PlayInterface, public Ai{
private:
    Qmodel<ImmutableCard, ImmutableCard> _qmodel;
    ImmutableCard _lastState = ImmutableCard(CardType::NONE, CardNumber::NONE);
    ImmutableCard _lastAct = ImmutableCard(CardType::NONE, CardNumber::NONE);
public:
    QPlayAI(double alpha);

    void acceptCorrection(CorrectionStatus status) override;

    int play(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) override;

    bool wantsCard(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) override;

};


#endif //MAO_AI_QPLAYAI_H


