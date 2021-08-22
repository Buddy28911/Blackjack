/**
 * Blackjack in C++
 * players.h
 * Author: Danny Noe
 * Description: players.h contains two classes.
 *      Dealer class: represents the dealer in blackjack
 *      Player class: represents a player in blackjack
 */

#include "players.h"
#include "deck.h"
#include <string>
#include <vector>

using std::string;

//------------------------------------------------------------------------------------------
/**
 * Dealer Class
 *  Dealer class represents the dealer in blackjack
 */

/**
 * Initalizes the Dealer class by creating a game_deck (Deck object)
 */
Dealer::Dealer()
{
    game_deck = Deck();
    return;
}

/**
 * Override the string operator to represent the Dealer as a string.
 * Only the dealer's top card is included in the str.
 * @param[out] str, string describing the dealer's top card
 */
Dealer::operator string() const
{
    return "Dealer's top card " + string(dealerHand.front());
}

/**
 * Deals the top card from the Deck
 * @param[out] Card, the card drawn from the deck
 */
Card Dealer::dealCard()
{
    return game_deck.dealCard();
}

/**
 * Adds a card to the dealer's hand
 * @param[in] new_card, the card to be added to the hand
 */
void Dealer::updateHand(Card new_card)
{
    dealerHand.push_back(new_card);
}

/**
 * Shuffles the deck
 */
void Dealer::shuffle()
{
    game_deck.shuffle();
}

//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
/**
 * Player Class
 *  the class represents a player in blackjack
 */

/**
 * Initializes the player class by giving them 100 chips
 */
Player::Player()
{
    chips = 100; // Player starts with $100 in chips
}

/**
 * Overrides the string() method to display the Player class
 * @param[out] str, string describing the player's hand
 */
Player::operator string() const
{
    string out = "Your hand: ";
    for (std::vector<Card>::const_iterator it = playerHand.begin(); it != playerHand.end(); ++it)
    {
        out += string(*it) + " ";
    }
    return out;
}

/**
 * Returns the chips in the player has
 * @param[out] int, num of chips in player's hand
 */
int Player::getChips()
{
    return chips;
}

/**
 * Updates the number of chips in the player has
 * @param[in] difference, the difference in chips to be added
 */
void Player::updateChips(int difference)
{
    chips = chips + difference;
}

/**
 * Adds a card to the player's hand
 * @param[in] new_card, the card to be added to the hand
 */
void Player::updateHand(Card new_card)
{
    playerHand.push_back(new_card);
}

//------------------------------------------------------------------------------------------