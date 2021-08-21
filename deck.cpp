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
Card::Card() {
    suit = "Spades";
    face = "Ace";
    val = 11;
}

Card::Card(string _suit, string _face, int _val) {
    suit = _suit;
    face = _face;
    val = _val;
}

string Card::getSuit() {
    return suit;
}

string Card::getFace() {
    return face;
}

int Card::getVal() {
    return val;
}

Card::operator string() const {
    return face + " of " + suit + ". Value " + std::to_string(val);
}

//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
// Deck Class
void Deck::buildDeck() {
    int cardCounter = 0;
    for (int i = 0; i < 4; i++) {
        string suit = "Spades";

        if (i == 1) {
            suit = "Hearts";
        }
        else if (i == 2) {
            suit = "Clubs";
        }
        else if (i == 3) {
            suit = "Diamonds";
        }

        for (int j = 1; j <= 13; j++) {
            string face = "Ace";
            int val = 11;
            
            if (j > 1 && j < 11) {
                face = std::to_string(j);
                val = j;
            }
            else if (j == 11) {
                face = "Jack";
                val = 10;
            }
            else if (j == 12) {
                face = "Queen";
                val = 10;
            }
            else if (j == 13) {
                face = "King";
                val = 10;
            }
            the52Cards[cardCounter] = Card(suit, face, val);
            cardCounter += 1;
        }
    }
    return;
}

void Deck::shuffle() {

    // Populate the vector
    for (int i = 0; i < 52; i++) {
        shuffledVec.push_back(i);
    }

    // Generate seed for random generator
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Shuffle the vector
    std::shuffle (shuffledVec.begin(), shuffledVec.end(), std::default_random_engine(seed));

    return;
}

Deck::Deck() {

    // Build the deck
    buildDeck(); // Helper function populates the deck array with the standard 52 cards

    // Testing code
    for (int i = 0; i < 52; i++) {
        std::cout << string(the52Cards[i]) << std::endl;
    }

    // Shuffle the deck
    shuffle();
    
    return;
}

Card Deck::dealCard() {
    Card next_card = the52Cards[shuffledVec.back()];
    shuffledVec.pop_back();
    return next_card;
}
//------------------------------------------------------------------------------------------