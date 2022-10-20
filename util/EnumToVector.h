//
// Created by brent on 20/10/22.
//

#ifndef MAO_AI_ENUMTOVECTOR_H
#define MAO_AI_ENUMTOVECTOR_H


#include <vector>
#include "../game/action/Act.h"
#include "../game/card/CardDetail.h"

class EnumToVector {
private:
    static const std::vector<Act> _actVector;
    static const std::vector<CardType> _cardTypeVector;
    static const std::vector<CardNumber> _cardNumberVector;

public:
    static const std::vector<Act> &getActVector();

    static const std::vector<CardType> &getCardTypeVector();

    static const std::vector<CardNumber> &getCardNumberVector();
};


#endif //MAO_AI_ENUMTOVECTOR_H
