As an alternative, if the candidate doesn’t have a code sample readily available, they may implement and send a program that simulates a basic version of blackjack, per the guidelines below:
Create a simple blackjack game in C++. You can use the following as a rough guidelines for the rules: https://en.wikipedia.org/wiki/Blackjack#Rules_of_play_at_casinos Please use OOP and other skills as needed to implement a program that lets you do the following:
1.           A single player can play a round of blackjack with a dealer. You can use the console for all player interaction.
2.           Player has a fixed number of $100 dollars/chips to start and is asked how much he wants to bet for the round.
3.           Dealer has a shuffled 52 card deck which he uses to deal out cards.
4.           Two initial cards are dealt to both the player and the dealer, player is shown his cards + one of the dealer’s cards.
5.           Player then has the option to hit (deal another card) or stand, unless their current score is 21 (blackjack) or more (bust).
6.           Player score should be tallied and reported after every hit (number cards count as their natural value, face cards count as 10, ace counts as 11 or 1 (1 only if adding 11 to their score would result in a bust).
7.           Once player is done, dealer deals to himself (cards are dealt to dealer until their hand busts or they have a score of 17 or higher).
8.           Final scores (including any blackjacks/busts) should be reported, along with who won the round, or if there was a tie (“push”).
9.           Player’s chip count should be updated accordingly and reported (e.g., if they bet $10, win = +$10, tie = no change, loss = -$10).
 
There’s some other aspects of the game that you don’t need to worry about but we may ask how you would implement them in the next interview, including:
1.           Player also has the option to double down (double the initial bet in exchange for committing to stand after exactly one more card)
2.           Allow for multiple rounds of play until a player is done or runs out of chips
3.           Player also has the option to split if the first two cards have the same value
4.           Allow multiple players to play with the dealer instead of just one player
5.           Multiple decks instead of just one