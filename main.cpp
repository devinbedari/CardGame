#include <iostream>
#include "Deck.h"

using namespace std;

int main() {
	Deck newDeck(1);
	newDeck.shuffleDeck();
	Card dealtCard = newDeck.dealCard();
	cout << "Card: ";
	newDeck.printCard(dealtCard);
	cout << endl;
	return 0;
}