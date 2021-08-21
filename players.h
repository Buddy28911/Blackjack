#ifndef __PLAYERS_H__
#define __PLAYERS_H__

#include "deck.h"
#include <string>
#include <vector>

using std::string;

//------------------------------------------------------------------------------------------
// Dealer Class
class Dealer {
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
// Player Class
class Player {
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