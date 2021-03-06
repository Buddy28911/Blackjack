/**
 * Blackjack in C++
 * blackjack.h
 * Author: Danny Noe
 * Description: blackjack.h contains the blackjack class. 
 *  The Blackjack class encapsulates the data and functions required to play Blackjack.
 */

#ifndef __BLACKJACK_H__
#define __BLACKJACK_H__

#include "players.h"
#include <string>
#include <array>
using std::string;

//------------------------------------------------------------------------------------------
/**
 * Blackjack Class
 * The Blackjack class encapsulates the data and functions required to play Blackjack.
 */
class Blackjack
{
private:
    int pot;
    int playerScore;
    int dealerScore;
    std::array<int, 3> scoreBoard; // [Win, Loss, Tie]

    void round();
    void reset();
    void bet();
    void playerTurn();
    void dealerTurn();
    void finishRound();
    void calculateScore();

public:
    Player player1;
    Dealer gameDealer;
    Blackjack();
    std::array<int, 3> getScore();
    void playGame();
};

//------------------------------------------------------------------------------------------

#endif