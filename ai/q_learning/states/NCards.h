//
// Created by brent on 23/10/22.
//

#ifndef MAO_AI_NCARDS_H
#define MAO_AI_NCARDS_H


#include <vector>
#include <ostream>
#include "../../../game/card/CardDetail.h"
#include "../../../game/card/ImmutableCard.h"

class NCards {
private:
    std::vector<CardType> _types;
    std::vector<CardNumber> _numbers;

public:
    /**
     * Create a state of N following cards
     * @param cards The N following cards
     */
    NCards(const std::vector<const ImmutableCard*>& cards);

    /**
     * Add a card to the back of the state (top card)
     * @param card
     */
    void addCard(const ImmutableCard* card);

    /**
     * Add a card to the back of the state (top card)
     * @param type The type of the card
     * @param number The number of the card
     */
    void addCard(CardType type, CardNumber number);

    /**
     * Add a card to the front of the state (bottom card)
     * @param card
     */
    void addBottomCard(const ImmutableCard* card);

    bool operator==(const NCards &rhs) const;

    bool operator!=(const NCards &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const NCards &cards);
};


#endif //MAO_AI_NCARDS_H
