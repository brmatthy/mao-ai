//
// Created by brent on 3/11/22.
//

#ifndef MAO_AI_QPLAYAI_H
#define MAO_AI_QPLAYAI_H


#include "../q_learning/Qmodel.h"
#include "../../game/card/ImmutableCard.h"
#include "../../player/interfaces/PlayInterface.h"
#include "../../game/validation/ActValidation.h"

class QPlayAI: public PlayInterface {
private:
    Qmodel<ImmutableCard, ImmutableCard> _qmodel;
    ImmutableCard _lastState;
    ImmutableCard _lastAct;
public:
    void acceptCorrection(CorrectionStatus status) override;

    int play(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) override;

    bool wantsCard(const std::deque<Action> &played, std::vector<const ImmutableCard *> &playerCards) override;

};


#endif //MAO_AI_QPLAYAI_H


