#include "blackjack.h"
#include "players.h"
#include "blackjack.h"
#include <iostream>
#include <string>
#include <array>
using std::string;

//------------------------------------------------------------------------------------------
// Blackjack Class

Blackjack::Blackjack() {
    player1 = Player();
    gameDealer = Dealer();
    pot = 0;
    playerScore = 0;
    dealerScore = 0;

    for (int i = 0; i < 3; i++) {
        scoreBoard[i] = 0;
    }

    return;
}

std::array<int, 3> Blackjack::getScore(){
    return scoreBoard;
}

void Blackjack::bet() {
    

    std::cout << "Enter bet amount. Minimum 1 " << std::endl;
    int betAmount;
    std::cin >> betAmount;

    while (betAmount > player1.getChips()) {
        std::cout << "Insufficient chips. Enter a smaller bet. " << std::endl;
        int betAmount;
        std::cin >> betAmount;
    }

    while (betAmount < 1) {
        std::cout << "Insufficient bet. Enter a bet greater than 0. " << std::endl;
        int betAmount;
        std::cin >> betAmount;
    }

    pot = betAmount;
    player1.updateChips(-1 * betAmount); 

    return;
}

void Blackjack::calculateScore() {

    // Player score
    playerScore = 0;
    bool hasAce = false;
    for (std::vector<Card>::iterator it = player1.playerHand.begin(); it != player1.playerHand.end(); it++) {
        playerScore += it->getVal();
        if (it->getVal() == 11) {
            hasAce = true;
        }
    }

    if (playerScore > 21 && hasAce) {
        playerScore -= 10;
    }

    // Dealer score
    dealerScore = 0;
    hasAce = false;

    for (std::vector<Card>::iterator it = gameDealer.dealerHand.begin(); it != gameDealer.dealerHand.end(); it++) {
        dealerScore += it->getVal();
        if (it->getVal() == 11) {
            hasAce = true;
        }
    }

    if (dealerScore > 21 && hasAce) {
        dealerScore -= 10;
    }

    return;
}

void Blackjack::playerTurn() {
    return;
}

void Blackjack::playGame() {

    // Bet
    bet();

    // Fill player's hand
    player1.updateHand(gameDealer.dealCard());
    player1.updateHand(gameDealer.dealCard());

    // Fill dealer's hand
    gameDealer.updateHand(gameDealer.dealCard());
    gameDealer.updateHand(gameDealer.dealCard());

    // Calculate score
    calculateScore();

    // Display hands
    std::cout << string(gameDealer) << " Score: " << dealerScore << std::endl;
    std::cout << string(player1) << " Score: " << playerScore << std::endl;

    // Player turn

    // Dealer turn

    // Deal pot / update scoreboard 

    return;
}

//------------------------------------------------------------------------------------------
