//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_IMMUTABLECARD_H
#define MAO_AI_IMMUTABLECARD_H

#include "CardDetail.h"
#include <iostream>
#include <vector>

/**
 * This class represents an immutable card. Jokers not included.
 */
class ImmutableCard {
private:
    /**
     * Representation of the type of the card
     */
    CardType _type;

    /**
     * Representation of the number of the card
     */
    CardNumber _number;

public:
    /**
     * Constructor, creates the card
     * @param mType The type of the card
     * @param mNumber The number of the card
     */
    ImmutableCard(CardType mType, CardNumber mNumber);

    /**
     * Return the type of the card
     * @return The type of the card
     */
    CardType getCardType() const;

    /**
     * Return the number of the card
     * @return The number of the card
     */
    CardNumber getCardNumber() const;

    bool operator==(const ImmutableCard &rhs) const;

    bool operator!=(const ImmutableCard &rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const ImmutableCard& ic);

    static std::vector<ImmutableCard> getAllCards();
};


#endif //MAO_AI_IMMUTABLECARD_H
