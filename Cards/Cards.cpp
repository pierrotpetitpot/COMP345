// Author Ebraheem Al Shapi
// Solution Risk
// Project: Cards
// Created at 1:34 AM 19/10/2020
// Date: 02/11/2020   8:59 AM
// File Name: Cards.cpp

#include "Cards.h"
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

CardType spyCard = CardType::spy;
CardType bombCard = CardType::bomb;
CardType reinforcementCard = CardType::reinforcement;
CardType blockadeCard = CardType::blockade;
CardType airliftCard = CardType::airlift;
CardType diplomacyCard = CardType::diplomacy;

unsigned int Card::nextCardID = 1;
unsigned static int step = 1;

Card::Card()
{
	cout << "\t" << this->cardID << ".Card()... " << endl;
	this->cardType = {&spyCard};
	cardID = nextCardID++;
}

Card::~Card()
{
	cout << "\t" << this->cardID << " .~Card()..." << endl;
	step++;
	//delete cardType;
	cardType = nullptr;
}

Card::Card(const Card& card)
{
	cout << "Card(const Card& card)..." << endl;
	cardID = nextCardID;
	cardType = {card.cardType};
}

Card::Card(CardType& armyType)
{
	cout << "\t" << nextCardID << " .Card(CardType armyType)..." << endl;
	this->cardType = &armyType;
	cardID = nextCardID++;
}

CardType& Card::getCardType() const
{
	return *cardType;
}

void Card::setCardType(CardType& armytype)
{
	*cardType = armytype;
}

int Card::getCardID() const
{
	return cardID;
}

void Card::play(Hand& hand, Deck& deck)
{
	cout << step << " .play(Hand& hand ,Deck& deck, CardType& type)... " << endl;
	step++;
	vector<Card*>::iterator cardID = hand.getHandCards().begin();

	for (int i = 1; i < hand.getHandCards().size(); i++)
	{
		if ((*cardID)->getCardType() == this->getCardType())
		{
			break;
		}
		++cardID;
	}

	if (this->getCardType() == (*cardID)->getCardType())
	{
		Card* selected = *cardID;
		//front(): A reference to the first element in the list container.
		//Card* selected = hand.getHandCards().front();
		//Card* selected = hand.getHandCards().back();
		//end(): An iterator to the element past the end of the sequence.
		cout << step << " .Removing the card in the player hand." << endl;
		step++;
		hand.getHandCards().erase(cardID);
		cout << step << " .Placing the card back in the deck." << endl;
		step++;
		deck.getDeckCards()->insert(deck.getDeckCards()->end(), &*selected);
	}
	else
	{
		cout << "Player doesn't have this type of cards" << endl;
	}
}


void Deck::generateCard(int numberOfCounteries)
{
	cout << step << " .generateCard()... " << endl;
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
	if ((remainder) > 0)
	{
		while (remainder != 0)
		{
			cardTypeSize[remainder]++;
			remainder--;
		}
	}

	//Creating the cards
	for (int i = 0; i < numberOfCounteries; i++)
	{
		int randType = rand() % 6;


		//Selecting the type that has enough allocations
		while (cardTypeSize[randType] == 0)
		{
			if (randType == 5)
			{
				randType = 0;
			}
			else
			{
				randType++;
			}
		}


		//creating card based on the selected type
		if (randType == 0)
		{
			deckCards->push_back(new Card(spyCard));
		}
		else if (randType == 1)
		{
			deckCards->push_back(new Card(bombCard));
		}
		else if (randType == 2)
		{
			deckCards->push_back(new Card(reinforcementCard));
		}
		else if (randType == 3)
		{
			deckCards->push_back(new Card(blockadeCard));
		}
		else if (randType == 4)
		{
			deckCards->push_back(new Card(airliftCard));
		}
		else if (randType == 5)
		{
			deckCards->push_back(new Card(diplomacyCard));
		}

		//decreasing the capacity of allocations of that random type
		cardTypeSize[randType]--;
	}
}

Deck::Deck()
{
}

Deck::~Deck()
{
	cout << step << " .~Deck()..." << endl;
	step++;

	for (auto& card : *deckCards)
	{
		delete card;
		card = nullptr;
	}
	deckCards->clear(); //will remove the "placeholder memory
	deckCards = nullptr;
}

Deck::Deck(int numberOfCounteries)
{
	deckCards = new vector<Card*>;
	srand(static_cast<unsigned>(time(nullptr)));
	cout << step << " .Deck(int numberOfCounteries)..." << endl;
	step++;
	generateCard(numberOfCounteries);
}

Deck::Deck(Deck& numberOfCounteries)
{
	cout << "Deck::Deck(Deck&)" << endl;
}

Card* Deck::draw()
{
	cout << step << " .draw(list<Card*> handCards)..." << endl;
	step++;
	int random = (rand() % deckCards->size()) + 1;
	vector<Card*>::iterator cardID = deckCards->begin();

	for (int i = 1; i < random; i++)
	{
		++cardID;
	}

	Card* selected = *cardID;
	cout << step << " .Removing " << *selected << " from the cards deck." << endl;
	step++;
	deckCards->erase(cardID);

	return &*selected;
}

void Deck::draw(Hand& hand)
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
	cout << step << " .~Hand()..." << endl;
	step++;

	for (int i = 0; i < handCards.size(); i++)
	{
		delete handCards.at(i);
		handCards[i] = nullptr;
	}
	handCards.clear(); //will remove the "placeholder memory
}

vector<Card*>& Hand::getHandCards()
{
	return handCards;
}

vector<Card*> Hand::getHandCards() const
{
	return handCards;
}

void Hand::setHandCards(vector<Card*>& handCards)
{
	this->handCards = handCards;
}


vector<Card*>* Deck::getDeckCards()
{
	return deckCards;
}

void Deck::setDeckCards(vector<Card*>& deckCards)
{
	this->deckCards = &deckCards;
}

ostream& operator<<(ostream& strm, const Card& card)
{
	strm << "(CardID:" << card.getCardID() << ", " << "Card Type:" << card.getCardType() << ")";
	return strm;
}

ostream& operator<<(ostream& strm, const Deck& deck)
{
	// TODO: insert return statement here
	for (auto& card : *(deck.deckCards))
	{
		strm << *card << '\n';
	}
	return strm;
}

ostream& operator<<(ostream& strm, const Hand hand)
{
	// TODO: insert return statement here
	for (auto const& i : hand.getHandCards())
	{
		strm << i << " ";
	}
	strm << endl;
	return strm;
}


std::ostream& operator<<(std::ostream& out, const CardType value)
{
	static std::map<CardType, std::string> strings;
	if (strings.size() == 0)
	{
#define INSERT_ELEMENT(p) strings[p] = #p
		INSERT_ELEMENT(CardType::spy);
		INSERT_ELEMENT(CardType::bomb);
		INSERT_ELEMENT(CardType::reinforcement);
		INSERT_ELEMENT(CardType::airlift);
		INSERT_ELEMENT(CardType::diplomacy);
		INSERT_ELEMENT(CardType::blockade);
#undef INSERT_ELEMENT
	}

	return out << strings[value];
}
