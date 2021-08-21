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
    
    std::cout << "You have " << player1.getChips() << " chips." << std::endl;
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
    int hasAce = 0;
    for (std::vector<Card>::iterator it = player1.playerHand.begin(); it != player1.playerHand.end(); it++) {
        playerScore += it->getVal();
        if (it->getVal() == 11) {
            hasAce++;
        }
    }

    if (playerScore > 21 && hasAce) {
        playerScore = playerScore - (hasAce * 10);
    }

    // Dealer score
    dealerScore = 0;
    hasAce = 0;

    for (std::vector<Card>::iterator it = gameDealer.dealerHand.begin(); it != gameDealer.dealerHand.end(); it++) {
        dealerScore += it->getVal();
        if (it->getVal() == 11) {
            hasAce++;
        }
    }

    if (dealerScore > 21 && hasAce) {
        dealerScore = dealerScore - (hasAce * 10);
    }

    return;
}

void Blackjack::playerTurn() {
    
    while (playerScore < 21) {
        string input;
        std::cout << "Hit or Stay? (case sensitive)" << std::endl;
        std::cin >> input;

        while (input != "Hit" && input != "Stay") {
            std::cout << "Please enter 'Hit' or 'Stay' (case sensitive)" << std::endl;
            std::cin >> input;
        }

        if (input == "Stay") {
            break;
        }
        else {
            player1.updateHand(gameDealer.dealCard());
            calculateScore();
            std::cout << string(player1) << " Score: " << playerScore << std::endl;
        }
    }
    return;
}

void Blackjack::dealerTurn() {

    while (dealerScore < 17) {
        std::cout << "Dealer hits" << std::endl;
        gameDealer.updateHand(gameDealer.dealCard());
        calculateScore();
        std::cout << string(gameDealer) << " Score: " << dealerScore << std::endl;
    }
}

void Blackjack::finishRound() {

    if (playerScore == 21) {
        if (playerScore == dealerScore) {
            // tie
            player1.updateChips(pot);
            scoreBoard[2] += 1;
            std::cout << "Tie! :|" << std::endl;
        }
        else {
            // win
            player1.updateChips(pot*2);
            scoreBoard[0] += 1;
            std::cout << "Win! :)" << std::endl;
        }
    }
    else if (playerScore > 21) {
        // loss
        scoreBoard[1] += 1;
        std::cout << "Loss! :'c" << std::endl;
    }
    else if (playerScore > dealerScore) {
        // win
        player1.updateChips(pot*2);
        scoreBoard[0] += 1;
        std::cout << "Win! :)" << std::endl;
    }
    else if (playerScore == dealerScore) {
        // tie
        player1.updateChips(pot);
        scoreBoard[2] += 1;
        std::cout << "Tie! :|" << std::endl;
    }
    else {
        // loss
        scoreBoard[1] += 1;
        std::cout << "Loss! :'c" << std::endl;
    }

    return;
}

void Blackjack::round() {
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
    playerTurn();

    // Dealer turn
    dealerTurn();

    // Deal pot / update scoreboard 
    finishRound();
}

void Blackjack::reset(){
    
    gameDealer.shuffle(); // Shuffle the deck

    while (!player1.playerHand.empty()){
        player1.playerHand.pop_back();
    }

    while (!gameDealer.dealerHand.empty()){
        gameDealer.dealerHand.pop_back();
    }
}

void Blackjack::playGame() {

    round();
    std::cout << "Win: " << scoreBoard[0] << " Loss: " << scoreBoard[1] << " Tie: " << scoreBoard[2] << std::endl;

    while (player1.getChips() > 0) {
        reset();
        round();
        std::cout << "Win: " << scoreBoard[0] << " Loss: " << scoreBoard[1] << " Tie: " << scoreBoard[2] << std::endl;
    }
    return;
}

//------------------------------------------------------------------------------------------
