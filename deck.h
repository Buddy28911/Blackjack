/**
 * Blackjack in C++
 * deck.h
 * Author: Danny Noe
 * Description: deck.h contains two classes.
 *      Card class: represents a playing card
 *      Deck class: represents a standard deck of 52 playing cards
 */

#ifndef __DECK_H__
#define __DECK_H__

#include <string>
#include <array>
#include <vector>
using std::string;

//------------------------------------------------------------------------------------------
// Card Class
/**
 * Card Class
 *  The card class represents a playing card. Each instance of the class represents a playing
 *  card with a suit, face, and value
 */
class Card
{
private:
    string suit;
    string face;
    int val;

public:
    Card();
    Card(string _suit, string _face, int _val);
    string getSuit(void);
    string getFace(void);
    int getVal(void);
    operator string() const;
};

//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
/**
 * Deck Class
 *  Deck class is an object that represents a deck of cards. The deck contains an array, the52Cards,
 *  which holds 52 card objects. The Deck class also has a vector, shuffledVec, that contains the
 *  indices for each card.
 */
class Deck
{
private:
    std::array<Card, 52> the52Cards;
    std::vector<int> shuffledVec;
    void buildDeck();

public:
    Deck();
    void shuffle();
    Card dealCard();
};

//------------------------------------------------------------------------------------------
#endif