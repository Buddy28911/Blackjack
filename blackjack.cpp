#include "blackjack.h"
#include "players.h"
#include "blackjack.h"
#include <string>
#include <array>
using std::string;

Blackjack::Blackjack() {
    player1 = Player();
    gameDealer = Dealer();
    
    for (int i = 0; i < 3; i++) {
        scoreBoard[i] = 0;
    }

    return;
}
std::array<int, 3> Blackjack::getScore(){
    return scoreBoard;
}