/**
 * Blackjack in C++
 * deck.cpp
 * Author: Danny Noe
 * Description: deck.cpp implements the Card and Deck classes
 *      Card class: represents a playing card
 *      Deck class: represents a standard deck of 52 playing cards
 */

#include "deck.h"
#include <string>
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
using std::string;

//------------------------------------------------------------------------------------------
/**
 * Card Class
 *  The card class represents a playing card. Each instance of the class represents a playing
 *  card with a suit, face, and value
 */

/**
 * Default card class constructor. Creates an Ace of Spades
 */
Card::Card()
{
    suit = "Spades";
    face = "Ace";
    val = 11;
}

/**
 * Card constructor creates a card object given the function's arguments
 * @param[in] _suit, string describing the card's suit
 * @param[in] _face, string describing the card's face value (i.e., "1", "Jack")
 * @param[in] _val,  int representing the card's numeric value in Blackjack
 */
Card::Card(string _suit, string _face, int _val)
{
    suit = _suit;
    face = _face;
    val = _val;
}

/**
 * Returns the suit of the card as a std::string
 * @param[out] suit, returns the string denoting the card's suit
 */
string Card::getSuit()
{
    return suit;
}

/**
 * Returns the face of the card as a std::string
 * @param[out] face, returns the string denoting the card's face
 */
string Card::getFace()
{
    return face;
}

/**
 * Returns the val of the card as an int
 * @param[out] face, returns the val of the card as an int
 */
int Card::getVal()
{
    return val;
}

/**
 * Override the string() operator to return the data encapsulated in the Card class as a std::string
 * @param[out] str, returns string representation of the Card
 */
Card::operator string() const
{
    return face + " of " + suit + ".";
}

//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
/**
 * Deck Class
 *  Deck class is an object that represents a deck of cards. The deck contains an array, the52Cards,
 *  which holds 52 card objects. The Deck class also has a vector, shuffledVec, that contains the
 *  indices for each card.
 */

/**
 * Helper function for the Deck() constructor. Populates the the52Cards array with
 * all 52 Card objects. Each object is one of the 52 cards in a standard deck
 * @relatesalso Deck
 */
void Deck::buildDeck()
{
    int cardCounter = 0; // keeps track of the current array index

    for (int i = 0; i < 4; i++)
    {
        // outer for loop assigns the suit of the card
        string suit = "Spades";

        if (i == 1)
        {
            suit = "Hearts";
        }
        else if (i == 2)
        {
            suit = "Clubs";
        }
        else if (i == 3)
        {
            suit = "Diamonds";
        }

        for (int j = 1; j <= 13; j++)
        {
            // Inner for loop dictates the card's face and value
            string face = "Ace";
            int val = 11;

            if (j > 1 && j < 11)
            {
                face = std::to_string(j);
                val = j;
            }
            else if (j == 11)
            {
                face = "Jack";
                val = 10;
            }
            else if (j == 12)
            {
                face = "Queen";
                val = 10;
            }
            else if (j == 13)
            {
                face = "King";
                val = 10;
            }
            the52Cards[cardCounter] = Card(suit, face, val);
            cardCounter += 1;
        }
    }
    return;
}

/**
 * shuffle() function refills and shuffles the deck
 * Specifically this function adds 52 ints [0-51] to the shuffledVec
 * then shuffles the vector. The ints in the vector represent the indices of the 52 cards
 */
void Deck::shuffle()
{
    // Purge old indices on re-shuffle
    while (!shuffledVec.empty())
    {
        shuffledVec.pop_back();
    }

    // Populate the vector
    for (int i = 0; i < 52; i++)
    {
        shuffledVec.push_back(i);
    }

    // Generate seed for random generator
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Shuffle the vector
    std::shuffle(shuffledVec.begin(), shuffledVec.end(), std::default_random_engine(seed));

    return;
}

/**
 * Creates an instance of the Deck class. The deck is populated with the standard 52 cards
 * in a playing deck.
 */
Deck::Deck()
{
    // Deck constructor function. Creates a full 52 card Deck object

    // Build the deck
    buildDeck(); // Helper function populates the deck array with the standard 52 cards

    // Testing code
    for (int i = 0; i < 52; i++)
    {
        std::cout << string(the52Cards[i]) << std::endl;
    }

    // Shuffle the deck
    shuffle();

    return;
}

/**
 * Returns the card on the top of the deck
 * @param[out] next_card, the card object at the top of the deck
 */
Card Deck::dealCard()
{
    //

    Card next_card = the52Cards[shuffledVec.back()];
    shuffledVec.pop_back();
    return next_card;
}

//------------------------------------------------------------------------------------------