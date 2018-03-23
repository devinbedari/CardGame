#include <vector>		// std::vector
#include <algorithm>    // std::random_shuffle
#include <iostream> 	// std::cout
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

#include "Deck.h"		// Deck class

// Random generator function for shuffle method.
int randomInt (int i) {
	return std::rand()%i;
}

// Helper function to compare the value of two cards, ignoring suit.
bool compareCards(Card cardA, Card cardB) {
	return cardA.value < cardB.value;
}

// Helper function to sort according to suit and value.
bool compareCardsSuit(Card cardA, Card cardB) {
	if(cardA.cardSuit == cardB.cardSuit) {
		return cardA.value < cardB.value;
	} else {
		return cardA.cardSuit < cardB.cardSuit;
	}
}

// Generates all thirteen cards from Ace to King of a certain suit, adds them to the shoe.
int Deck::generateCardsSuit(Suit suit) {
	int i;
	for (i = 1; i < 14; i++) {
		Card newCard;
		newCard.value = i;
		newCard.cardSuit = suit;
		this->shoe.push_back(newCard);
	}
	return i - 1;
}

// Converts a suit to a character
char Deck::suitToChar(Card myCard) {
	switch (myCard.cardSuit) {
		case SPADES:
			return 'S';
			break;
		case HEARTS:
			return 'H';
			break;
		case CLUBS:
			return 'C';
			break;
		case DIAMONDS:
			return 'D';
			break;
		default:
			return 'E';
	}
	return 'E';
}

// Converts a value to a card type
char Deck::valueToCard(Card myCard) {
	if (myCard.value == 1) {
		return 'A';
	} else if ((myCard.value > 1) && (myCard.value < 10)) {
		return myCard.value + 48;
	} else if (myCard.value == 10) {
		return 'T'; 
	} else if (myCard.value == 11) {
		return 'J';
	} else if (myCard.value == 12) {
		return 'Q';
	} else {
		return 'K';
	}
	return 'E';
}

// Add a deck to the shoe.
bool Deck::addDeck() {
	bool spadeFlag, heartFlag, clubFlag, diamondFlag;
	spadeFlag = generateCardsSuit(SPADES) == 13;
	heartFlag = generateCardsSuit(HEARTS) == 13;
	clubFlag = generateCardsSuit(CLUBS) == 13;
	diamondFlag = generateCardsSuit(DIAMONDS) == 13;
	return spadeFlag & heartFlag & clubFlag & diamondFlag;
}

// Shuffle the deck using the standard library shuffle algorithm
void Deck::shuffleDeck() {
	// Initialize random number generator seeded to current time
	std::srand ( unsigned ( std::time(0) ) );
	// Shuffle according to the random number
	std::random_shuffle (this->shoe.begin(), this->shoe.end(), randomInt);
}

// Show the cards in the deck
void Deck::showDeck() {
	std::cout << std::endl;
	for (int i = 0; i < this->shoe.size(); i++) {
		std::cout << valueToCard(this->shoe[i]) << suitToChar(this->shoe[i]) << std::endl;
	}
}

bool Deck::sortCards(bool bySuit) {
	if (bySuit) {
		std::sort (this->shoe.begin(), this->shoe.end(), compareCardsSuit);
	} else {
		std::sort (this->shoe.begin(), this->shoe.end(), compareCards);
	}
	
}

Card Deck::dealCard() {
	Card dealtCard = this->shoe.back();
	this->shoe.pop_back();
	this->dealt.push_back(dealtCard);
	return dealtCard;
}

void Deck::printCard(Card myCard) {
	std::cout << this->valueToCard(myCard) << this->suitToChar(myCard); 
}

// Construct an empty deck. Cards have to manually be added with the addDeck function.
Deck::Deck() {
	this->numberOfDecks = 0;
}

// Construct the deck with howManyDecks decks.
Deck::Deck(int howManyDecks) {
	this->numberOfDecks = howManyDecks;
	for (int i = 0; i < numberOfDecks; i++) {
		addDeck();
	}
}