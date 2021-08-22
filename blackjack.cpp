/**
 * Blackjack in C++
 * blackjack.cpp
 * Author: Danny Noe
 * Description: blackjack.h contains the blackjack class. 
 *  The Blackjack class encapsulates the data and functions required to play Blackjack.
 */

#include "blackjack.h"
#include "players.h"
#include "blackjack.h"
#include <iostream>
#include <string>
#include <array>
using std::string;

//------------------------------------------------------------------------------------------
/**
 * Blackjack Class
 * The Blackjack class encapsulates the data and functions required to play Blackjack.
 */

/**
 * Initializes a Blackjack class object.
 */
Blackjack::Blackjack()
{
    // Create player and dealer
    player1 = Player();
    gameDealer = Dealer();
    // Initialize the pot as empty
    pot = 0;
    // Player and Dealer start with a score of 0
    playerScore = 0;
    dealerScore = 0;

    // Fill the scoreboard with zeros
    for (int i = 0; i < 3; i++)
    {
        scoreBoard[i] = 0;
    }

    return;
}

/**
 * Returns an array containing the current score
 */
std::array<int, 3> Blackjack::getScore()
{
    return scoreBoard;
}

/**
 * Asks the player to enter a valid bet amount
 */
void Blackjack::bet()
{

    std::cout << "You have " << player1.getChips() << " chips." << std::endl;
    std::cout << "Enter bet amount. Minimum 1 " << std::endl;
    int betAmount;
    std::cin >> betAmount;

    // Verify the player can afford their bet
    while (betAmount > player1.getChips())
    {
        std::cout << "Insufficient chips. Enter a smaller bet. " << std::endl;
        int betAmount;
        std::cin >> betAmount;
    }

    // Verify the bet is >0
    while (betAmount < 1)
    {
        std::cout << "Insufficient bet. Enter a bet greater than 0. " << std::endl;
        int betAmount;
        std::cin >> betAmount;
    }

    pot = betAmount;
    // Take the money from player
    player1.updateChips(-1 * betAmount);

    return;
}

/**
 * This function determines the current score of the player and the dealer.
 * Note: this function handles the value of an Ace
 */
void Blackjack::calculateScore()
{

    // Player score
    playerScore = 0;
    int hasAce = 0;

    // Iterate over the players hand and calculate their score
    for (std::vector<Card>::iterator it = player1.playerHand.begin(); it != player1.playerHand.end(); it++)
    {
        playerScore += it->getVal();
        if (it->getVal() == 11)
        {
            hasAce++;
        }
    }

    // If the player has an Ace && their score busts, change each Ace to a value of 1.
    if (playerScore > 21 && hasAce)
    {
        playerScore = playerScore - (hasAce * 10);
    }

    // Dealer score
    dealerScore = 0;
    hasAce = 0;

    // Iterate over the players hand and calculate their score
    for (std::vector<Card>::iterator it = gameDealer.dealerHand.begin(); it != gameDealer.dealerHand.end(); it++)
    {
        dealerScore += it->getVal();
        if (it->getVal() == 11)
        {
            hasAce++;
        }
    }

    // If the player has an Ace && their score busts, change each Ace to a value of 1.
    if (dealerScore > 21 && hasAce)
    {
        dealerScore = dealerScore - (hasAce * 10);
    }

    return;
}

/**
 * Helper function for round(). Function handles the players turn.
 * The player is allowed to Hit until they reach a score of >= 21
 * @relatesalso Blackjack
 */
void Blackjack::playerTurn()
{

    while (playerScore < 21)
    {
        string input;
        std::cout << "Hit or Stay? (case sensitive)" << std::endl;
        std::cin >> input;

        while (input != "Hit" && input != "Stay")
        {
            std::cout << "Please enter 'Hit' or 'Stay' (case sensitive)" << std::endl;
            std::cin >> input;
        }

        if (input == "Stay")
        {
            break;
        }
        else
        {
            player1.updateHand(gameDealer.dealCard());
            calculateScore();
            std::cout << string(player1) << " Score: " << playerScore << std::endl;
        }
    }
    return;
}

/**
 * Helper function for round(). Function handles the dealer's turn.
 * The dealer must draw cards until their score is >= 17
 * @relatesalso Blackjack
 */
void Blackjack::dealerTurn()
{
    while (dealerScore < 17)
    {
        std::cout << "Dealer hits" << std::endl;
        gameDealer.updateHand(gameDealer.dealCard());
        calculateScore();
        std::cout << string(gameDealer) << " Score: " << dealerScore << std::endl;
    }
}

/**
 * Helper function for round(). Finishes the round by determining the winner,
 * updateing the scoreboard, and dealing the pot
 * @relatesalso Blackjack
 */
void Blackjack::finishRound()
{

    if (playerScore == 21)
    {
        if (playerScore == dealerScore)
        {
            // tie
            player1.updateChips(pot);
            scoreBoard[2] += 1;
            std::cout << "Tie! :|" << std::endl;
        }
        else
        {
            // win
            player1.updateChips(pot * 2);
            scoreBoard[0] += 1;
            std::cout << "Win! :)" << std::endl;
        }
    }
    else if (playerScore > 21)
    {
        // loss
        scoreBoard[1] += 1;
        std::cout << "Loss! :'c" << std::endl;
    }
    else if (dealerScore == 21)
    {
        // loss
        scoreBoard[1] += 1;
        std::cout << "Loss! :'c" << std::endl;
    }
    else if (playerScore > dealerScore)
    {
        // win
        player1.updateChips(pot * 2);
        scoreBoard[0] += 1;
        std::cout << "Win! :)" << std::endl;
    }
    else if (playerScore == dealerScore)
    {
        // tie
        player1.updateChips(pot);
        scoreBoard[2] += 1;
        std::cout << "Tie! :|" << std::endl;
    }
    else
    {
        // loss
        scoreBoard[1] += 1;
        std::cout << "Loss! :'c" << std::endl;
    }

    return;
}

/**
 * Helper function for playGame(). The round() function represents a full round of blackjack
 * @relatesalso Blackjack
 */
void Blackjack::round()
{
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
    std::cout << string(gameDealer) << std::endl;
    std::cout << string(player1) << " Score: " << playerScore << std::endl;

    // Player turn
    playerTurn();

    // Dealer turn
    dealerTurn();

    // Deal pot / update scoreboard
    finishRound();
}

/**
 * Helper function for playGame(). This function "resets" the game by
 * emptying the dealer's and player's hands, as well as shuffling the deck
 * @relatesalso Blackjack
 */
void Blackjack::reset()
{

    gameDealer.shuffle(); // Shuffle the deck

    while (!player1.playerHand.empty())
    {
        player1.playerHand.pop_back();
    }

    while (!gameDealer.dealerHand.empty())
    {
        gameDealer.dealerHand.pop_back();
    }
}

/**
 * The 'main' function of the Blackjack class. This function 'runs' the whole blackjack game.
 * A round of blackjack is played. Then the game loops until the player runs out of money.
 */
void Blackjack::playGame()
{

    round();
    std::cout << "Win: " << scoreBoard[0] << " Loss: " << scoreBoard[1] << " Tie: " << scoreBoard[2] << std::endl;

    while (player1.getChips() > 0)
    {
        reset();
        round();
        std::cout << "Win: " << scoreBoard[0] << " Loss: " << scoreBoard[1] << " Tie: " << scoreBoard[2] << std::endl;
    }
    return;
}

//------------------------------------------------------------------------------------------
