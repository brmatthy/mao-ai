//
// Created by brent on 1/10/22.
//

#ifndef MAO_AI_PLAYER_H
#define MAO_AI_PLAYER_H

#include <vector>
#include <deque>
#include <unordered_set>
#include "../game/card/ImmutableCard.h"
#include "../game/action/Action.h"
#include "../game/action/Act.h"
#include "../game/validation/Correction.h"
#include "../game/Game.h"
#include "interfaces/ActInterface.h"
#include "interfaces/MoveInterface.h"
#include "interfaces/PlayInterface.h"

class Action;
class Correction;
class Game;
class MoveInterface;
class PlayInterface;
class ActInterface;

/**
 * This is an abstract base class for any player.
 */
class Player {
private:
    std::vector<const ImmutableCard*> _cards;
    const Game* _game;
protected:
    MoveInterface* _mover;
    PlayInterface* _cardPlayer;
    ActInterface* _actor;

public:

    /**
     * Create a player with it's aid classes. The aid classes are given to the player, and the player is not responsible
     * for it' deletions
     * @param mover The class which determines if the player will move or not
     * @param cardPlayer The class which determines if the player draw or play a card, and what card to play
     * @param actor The class which determines what acts the player will do
     */
    Player( MoveInterface* mover, PlayInterface* cardPlayer, ActInterface* actor);
    virtual ~Player() = default;

    /**
     * Let the player play a card, remove the pointer from the card vector
     * This function will only be called if the player thinks he can make
     * a correct move. (when the wantsCard() function returns `false`)
     * @return A reference to the card, cannot be nullptr
     */
    const ImmutableCard* play();

    /**
     * Let the player do an action after playing a card
     * If the card is nullptr than it means you just drew a card instead of playing
     * @return The acts
     */
    const std::unordered_set<Act> act(const std::deque<Action>& played, const ImmutableCard* played_card);

    /**
     * Ask the player if he thinks it's his turn
     * @return `True` if the player thinks it's his turn, `false` otherwise
     */
    bool myTurn();

    /**
     * Ask the player if he wants to draw a card
     * @return `True` if the player wants to draw a card, `false` otherwise
     */
    bool wantsCard();

    /**
     * If the player played out of turn or made an error in it's action, he receives a Correction
     * This function takes a Correction, and handles it.
     * @param correction The Correction
     */
     //TODO: fix docs
    void acceptCorrection(const std::unordered_set<CorrectionStatus>& corrections);

    /**
     * Let the player draw a card. The card will be added to the player's card collection
     * @param card The drawn card
     */
    void drawCard(const ImmutableCard* card);

    /**
     * Check if the player has no cards left
     * @return `true` if the player has no cards left, `false` otherwise
     */
    bool hasNoCards();

    /**
     * Get the number of cards the player is holding
     * @return The number of cards the player is holding
     */
    int cardCount();

    /**
     * Update the game that this player is playing
     * @param game The game to set
     */
    void setGame(Game* game);

    /**
     * Return a reference to the vector that holds all the current cards of the player
     * @return A reference to the card vector
     */
    std::vector<const ImmutableCard*>& getCards();

    /**
     * Clears the card vector. Cards are stored on the heap, make sure to delete them beforehand
     */
     void clearCards();

     /**
      * Get the game that this player is playing
      * @return The game
      */
     const Game* getGame();
};


#endif //MAO_AI_PLAYER_H
