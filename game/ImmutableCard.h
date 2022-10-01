//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_IMMUTABLECARD_H
#define MAO_AI_IMMUTABLECARD_H

#include "CardDetail.h"
#include <iostream>

class ImmutableCard {
private:
    const CardType m_type;
    const CardNumber m_number;

public:
    ImmutableCard(CardType mType, CardNumber mNumber);

    CardType getCardType();

    CardNumber getCardNumber();

    friend std::ostream& operator<<(std::ostream& os, const ImmutableCard& ic);
};


#endif //MAO_AI_IMMUTABLECARD_H
