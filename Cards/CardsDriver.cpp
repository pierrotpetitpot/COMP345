// Author Ebraheem Al Shapi
// Solution Risk
// Project: Cards
// Created at 1:34 AM 19/10/2020
// Date: 02/11/2020   8:59 AM
// File Name: CardsDriver.cpp

#include "Cards.h"


int main()
{

	Deck deck(50);

	cout << "Size of the deck:" << deck.getDeckCards()->size() << endl;
	Hand hand;

	deck.draw(hand);
	cout << "Size of the deck after drawing:" << deck.getDeckCards()->size() << endl;
	cout << "Number of cards with the hand:" << hand.getHandCards().size() << endl;

	Card* selected = hand.getHandCards().front();

	selected->play(hand, deck);
	cout << "Size of the deck after playing:" << deck.getDeckCards()->size() << endl;
	cout << "Number of cards with the hand after playing:" << hand.getHandCards().size() << endl;


	return 0;
}
