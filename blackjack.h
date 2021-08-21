#ifndef __BLACKJACK_H__
#define __BLACKJACK_H__

#include "players.h"
#include <string>
#include <array>
using std::string;

//------------------------------------------------------------------------------------------
// Blackjack Class
class Blackjack {
    private:
        int pot;
        int playerScore;
        int dealerScore;
        std::array<int, 3> scoreBoard; // [Win, Loss, Tie]
    public:
        Player player1;
        Dealer gameDealer;
        Blackjack();
        std::array<int, 3> getScore();
        void playGame();
        void bet();
        void playerTurn();
        void dealerTurn();
        void finishRound();
        void calculateScore();
};

//------------------------------------------------------------------------------------------


#endif