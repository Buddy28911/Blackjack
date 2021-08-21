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
// Card Class
// The card class represents a playing card. Each instance of the class represents a playing card with a suit, face, and value
Card::Card()
{
    // Initializes a Card class object with the default constructor.
    // The default attributes is the ace of spades
    suit = "Spades";
    face = "Ace";
    val = 11;
}

Card::Card(string _suit, string _face, int _val)
{
    // Constructs an instance of the Card class using the given args
    suit = _suit;
    face = _face;
    val = _val;
}

string Card::getSuit()
{
    // Returns the suit of the card as a std::string
    return suit;
}

string Card::getFace()
{
    // Returns the face of the card as a std::string
    return face;
}

int Card::getVal()
{
    // Returns the val of the card as an int
    return val;
}

Card::operator string() const
{
    // Override the string() operator to return the data encapsulated in the Card class as a std::string
    return face + " of " + suit + ".";
}

//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
// Deck Class
// Deck class is an object that represents a deck of cards. The deck contains an array, the52Cards,
// which holds 52 card objects. The Deck class also has a vector, shuffledVec, that contains the
// indices for each card.

void Deck::buildDeck()
{
    // Helper function for the Deck() constructor
    // Creates 52 card objects, representing the complete deck, and adds each card to
    // the the52Cards array

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

void Deck::shuffle()
{
    // Shuffles the deck. Specifically this function adds 52 ints [0-51] to the shuffledVec
    // then shuffles the vector. The ints in the vector represent the indices of the 52 cards

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

Card Deck::dealCard()
{
    // Returns the card on the top of the deck

    Card next_card = the52Cards[shuffledVec.back()];
    shuffledVec.pop_back();
    return next_card;
}
//------------------------------------------------------------------------------------------