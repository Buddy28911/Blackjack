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
        std::vector<Card> dealerHand;
    public:
        Dealer();
        void updateHand(Card new_card);
        operator string() const;
};
//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
// Player Class
class Player {
    private:
        int chips;
        std::vector<Card> playerHand;
    public:
        Player();
        int getChips();
        void updateChips(int difference);
        void updateHand(Card new_card);
        operator string() const;
};
//------------------------------------------------------------------------------------------
#endif