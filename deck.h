#ifndef __DECK_H__
#define __DECK_H__

#include <string>
#include <array>
#include <vector>
using std::string;

//------------------------------------------------------------------------------------------
// Card Class
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
// Deck Class
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