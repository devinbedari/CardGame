// Header file for the card class
#ifndef DECK_H
#define DECK_H

#include <vector>

// Enumerator to hold suit
enum Suit { 
	SPADES,
	HEARTS,
	CLUBS,
	DIAMONDS
};

// Contains card data
struct Card {
	int value;
	Suit cardSuit;
};

// Holds the deck of cards
class Deck {
private:
	// Member variables
	int numberOfDecks;
	std::vector<Card> shoe;
	std::vector<Card> dealt;

	// Helper functions
	int generateCardsSuit(Suit suit);
	char suitToChar(Card myCard);
	char valueToCard(Card myCard);

public:
	Deck();
	Deck(int howManyDecks);
	bool addDeck();
	void shuffleDeck();
	void showDeck();
	void printCard(Card myCard);
	bool sortCards(bool bySuit);
	Card dealCard();
};

#endif