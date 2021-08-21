// By Danny Noe
#include <iostream>
#include "deck.h"
#include "players.h"
#include <vector>

int main() {
    
    std::cout << "Welcome to Blackjack!" << std::endl;

    Card ace_of_spade = Card();
    std::cout << string(ace_of_spade) << std::endl;
    
    Card king_of_hearts = Card("Heart", "King", 10);
    std::cout << string(king_of_hearts) << std::endl;
    
    Deck deck1 = Deck();

    // Test Code
    std::cout << "Randomly drawing the whole deck" << std::endl << std::endl;
    for (int i = 0; i < 52; i++) {
        std::cout << string(deck1.dealCard()) << std::endl;
    }

    deck1.shuffle();
    std::cout << "Randomly drawing the whole deck" << std::endl << std::endl;
    for (int i = 0; i < 52; i++) {
        std::cout << string(deck1.dealCard()) << std::endl;
    }

    Dealer dealer = Dealer();
    std::cout << string(dealer) << std::endl;


    std::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::vector<Card> myCardVec;
    myCardVec.push_back(Card("Clubs", "King", 10));
    myCardVec.push_back(Card("Clubs", "Jack", 10));
    myCardVec.push_back(Card("Clubs", "3", 3));
    myCardVec.push_back(Card("Clubs", "5", 5));
    myCardVec.push_back(Card("Clubs", "2", 2));

    std::cout << "myvector contains:";
    for (std::vector<Card>::iterator it = myCardVec.begin() ; it != myCardVec.end(); ++it)
        std::cout << ' ' << string(*it);
    std::cout << '\n';

    Player player1 = Player();
    std::cout << string(player1) << std::endl;
    player1.updateHand(Card("Hearts", "4", 4));
    std::cout << string(player1) << std::endl;

    return 0;
}