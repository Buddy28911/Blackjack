/**
 * Blackjack in C++
 * main.cpp
 * Author: Danny Noe
 * Description: A basic blackjack game that can be played in the terminal/console
 * main.cpp contains the main function for the program.
 */

#include <iostream>
#include "deck.h"
#include "blackjack.h"
#include "players.h"
#include <vector>
#include <string>
using std::string;


/**
 * Main function, creates a blackjack instance and starts the game
 * @return 0 when the program exits sucessfully
 */
int main()
{
 
    std::cout << "Welcome to Blackjack!" << std::endl;

    Blackjack blackJackGame = Blackjack();
    blackJackGame.playGame();

    return 0;
}