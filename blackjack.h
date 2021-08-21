#ifndef __BLACKJACK_H__
#define __BLACKJACK_H__

#include "players.h"
#include <string>
#include <array>
using std::string;

//------------------------------------------------------------------------------------------
// Card Class
class Blackjack {
    private:
        Player player1;
        Dealer gameDealer;
        std::array<int, 3> scoreBoard;
    public:
        Blackjack();
        std::array<int, 3> getScore();
};

//------------------------------------------------------------------------------------------


#endif