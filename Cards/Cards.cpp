//
//  Cards.h
//  assignment1
//
//  Created by Ebraheem Al Shapi.
//




#include "Cards.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;

CardType spyCard = CardType::spy;
CardType bombCard = CardType::bomb;
CardType reinforcementCard = CardType::reinforcement;
CardType blockadeCard = CardType::blockade;
CardType airliftCard = CardType::airlift;
CardType diplomacyCard = CardType::diplomacy;

std::ostream& operator<<(std::ostream& out, const CardType value) {
	static std::map<CardType, std::string> strings;
	if (strings.size() == 0) {
#define INSERT_ELEMENT(p) strings[p] = #p
		INSERT_ELEMENT(spy);
		INSERT_ELEMENT(bomb);
		INSERT_ELEMENT(reinforcement);
		INSERT_ELEMENT(blockade);
		INSERT_ELEMENT(airlift);
		INSERT_ELEMENT(diplomacy);
#undef INSERT_ELEMENT
	}

	return out << strings[value];
}

unsigned int Card::nextCardID = 1;
unsigned static int step = 1;

Card::Card()
{
	cout << "\t" << nextCardID << ".Card()... " << endl;
	this->cardType = { spyCard };
	cardID = nextCardID++;
}

Card::~Card()
{
}

//Card::Card(const Card& card)
//{
//	cout << "Card(const Card& card)..." << endl;
//	cardID = nextCardID;
//	cardType = { card.cardType };
//}

Card::Card(CardType armyType)
{
	cout << "\t" << nextCardID << " .Card(CardType armyType)..." << endl;
	this->cardType = armyType;
	cardID = nextCardID++;
}

CardType Card::getArmyType() const
{
	return this->cardType;
}

void Card::setArmyType(CardType& armytype)
{
	cardType = armytype;
}

int Card::getCardID() const
{
	return cardID;
}

void Card::play(Hand& hand ,Deck& deck)
{
	cout << step << " .play(Hand& hand ,Deck& deck, CardType& type)... " << endl;
	step++;
	/*list<Card*>::iterator cardID = hand.getHandCards().begin();

	for (int i = 1; i < hand.getHandCards().size(); i++) {
		if ((*cardID)->getArmyType() == type) {
			break;
		}
		cardID++;
	}

	Card* selected = *cardID;*/

	//front(): A reference to the first element in the list container.
	Card* selected = hand.getHandCards().front();
	//end(): An iterator to the element past the end of the sequence.
	cout << step << " .Removing the card in the player hand." << endl;
	step++;
	hand.getHandCards().erase(hand.getHandCards().end());
	cout << step << " .Placing the card back in the deck." << endl;
	step++;
	deck.getDeckCards().insert(deck.getDeckCards().end(), &*selected);
}





void Deck::generateCard(int numberOfCounteries)
{
	cout << step << " .generateCard()... "<<endl;
	step++;
	//destributing the cards equally among the six categories
	array<int, 6> cardTypeSize;
	cardTypeSize[0] = numberOfCounteries / 6;
	cardTypeSize[1] = numberOfCounteries / 6;
	cardTypeSize[2] = numberOfCounteries / 6;
	cardTypeSize[3] = numberOfCounteries / 6;
	cardTypeSize[4] = numberOfCounteries / 6;
	cardTypeSize[5] = numberOfCounteries / 6;

	//Keeping the remainder
	int remainder = numberOfCounteries % 6;

	// Randomly increasing the allocation of cards of random type based on the value of the remainder
	if ((remainder) > 0) {
		while (remainder != 0) {
			cardTypeSize[remainder]++;
			remainder--;
		}
	}

	//Creating the cards
	for (int i = 0; i < numberOfCounteries; i++)
	{
		int randType = rand() % 6;


		//Selecting the type that has enough allocations
		while (cardTypeSize[randType] == 0) {
			if (randType == 5) {
				randType = 0;
			}
			else {
				randType++;
			}
		}

		//creating card based on the selected type
		if (randType == 0) {
			allCards.push_back(Card(CardType::spy));
		}
		else if (randType == 1) {
			allCards.push_back(Card(CardType::bomb));
		}
		else if (randType == 2) {
			allCards.push_back(Card(CardType::reinforcement));
		}
		else if (randType == 3) {
			allCards.push_back(Card(CardType::blockade));
		}
		else if (randType == 4) {
			allCards.push_back(Card(CardType::airlift));
		}
		else if (randType == 5) {
			allCards.push_back(Card(CardType::diplomacy));
		}

		//decreasing the capacity of allocations of that random type
		cardTypeSize[randType]--;

	}

	// creating a list with the addresses of cards in allCards
	for (list<Card>::iterator it = allCards.begin(); it != allCards.end(); ++it) {
		Card* cardPtr = &*it;
		//deckCards.push_front(cardPtr);
		list<Card*>::iterator currentCard = deckCards.insert(deckCards.end(), cardPtr);
	}
}

Deck::Deck()
{
}

Deck::~Deck()
{
}

Deck::Deck(int numberOfCounteries)
{
	cout << step << " .Deck(int numberOfCounteries)..." <<endl;
	step++;
	generateCard(numberOfCounteries);
}

Card* Deck::draw()
{
	cout << step << " .draw(list<Card*> handCards)..." << endl;
	step++;
	int random = (rand() % deckCards.size()) + 1;
	list<Card*>::iterator cardID = deckCards.begin();

	for (int i = 1; i < random; i++) {
		cardID++;
	}

	Card* selected = *cardID;
	cout << step << " .Removing " << *selected << " from the card in the player hand." << endl;
	step++;
	deckCards.erase(cardID);
	cout << step << " .Removing " << *selected << " from the card in the player hand." << endl;

	return &*selected;
}

void Deck::draw(Hand &hand)
{
	Card* selected = draw();
	cout << step << " .Placing the card in the player hand." << endl;
	step++;
	hand.getHandCards().insert(hand.getHandCards().end(), selected);
}


Hand::Hand()
{
	cout << step << " .Hand()..." << endl;
	step++;
}

Hand::~Hand()
{
}

list<Card*>& Hand::getHandCards()
{
	return handCards;
}

void Hand::setHandCards(list<Card*> handCards)
{
	this->handCards = handCards;
}


list<Card> Deck::getAllCards() const
{
	return allCards;
}

void Deck::setAllCards(list<Card> allCards)
{
	this->allCards = allCards;
}

list<Card*>& Deck::getDeckCards() 
{
	return deckCards;
}

void Deck::setDeckCards(list<Card*> deckCards)
{
	this->deckCards = deckCards;
}

ostream& operator<<(ostream& strm, const Card& card)
{
	strm << "(CardID:" << card.getCardID() << ", " << "Card Type:" << card.cardType <<")";
	return strm;
	
}

ostream& operator<<(ostream& strm, const Deck& deck)
{
	// TODO: insert return statement here
	strm;
	return strm;
}

ostream& operator<<(ostream& strm,Hand hand)
{
	// TODO: insert return statement here
	for (auto const& i : hand.getHandCards()) {
		strm << i << " ";
	}
	return strm;
}

