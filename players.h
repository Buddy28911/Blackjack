/**
 * Blackjack in C++
 * players.h
 * Author: Danny Noe
 * Description: players.h contains two classes.
 *      Dealer class: represents the dealer in blackjack
 *      Player class: represents a player in blackjack
 */

#ifndef __PLAYERS_H__
#define __PLAYERS_H__

#include "deck.h"
#include <string>
#include <vector>

using std::string;

//------------------------------------------------------------------------------------------
/**
 * Dealer Class
 *  Dealer class represents the dealer in blackjack
 */
class Dealer
{
private:
    Deck game_deck;

public:
    std::vector<Card> dealerHand;
    Dealer();
    Card dealCard();
    void updateHand(Card new_card);
    void shuffle();
    operator string() const;
};
//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
/**
 * Player Class
 *  the class represents a player in blackjack
 */
class Player
{
private:
    int chips;

public:
    std::vector<Card> playerHand;
    Player();
    int getChips();
    void updateChips(int difference);
    void updateHand(Card new_card);
    operator string() const;
};
//------------------------------------------------------------------------------------------
#endif