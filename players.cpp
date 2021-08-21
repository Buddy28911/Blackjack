#include "players.h"
#include "deck.h"
#include <string>
#include <vector>

using std::string;

//------------------------------------------------------------------------------------------
// Dealer Class
Dealer::Dealer()
{
    game_deck = Deck();
    // dealerHand.push_back(Card());
    // dealerHand.push_back(game_deck.dealCard());
    return;
}

Dealer::operator string() const
{
    return "Dealer's top card " + string(dealerHand.front());
}

Card Dealer::dealCard()
{
    return game_deck.dealCard();
}

void Dealer::updateHand(Card new_card)
{
    dealerHand.push_back(new_card);
}

void Dealer::shuffle()
{
    game_deck.shuffle();
}

//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
// Player Class

Player::Player()
{
    chips = 100; // Player starts with $100 in chips
    // playerHand.push_back(Card());
    // playerHand.push_back(Card("Diamonds", "11", 11));
    // playerHand.push_back(Card("Hearts", "Jack", 10));
}

Player::operator string() const
{
    string out = "Your hand: ";
    for (std::vector<Card>::const_iterator it = playerHand.begin(); it != playerHand.end(); ++it)
    {
        out += string(*it) + " ";
    }
    return out;
}

int Player::getChips()
{
    return chips;
}

void Player::updateChips(int difference)
{
    chips = chips + difference;
}

void Player::updateHand(Card new_card)
{
    playerHand.push_back(new_card);
}
//------------------------------------------------------------------------------------------