// Author Ebraheem Al Shapi
// Solution Risk
// Project: Cards
// Created at 1:34 AM 19/10/2020
// Date: 02/11/2020   8:59 AM
// File Name: Cards.h

#pragma once

//#define _DEBUG
//#ifdef _DEBUG
//#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//#endif


#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class CardType
{
	spy,
	bomb,
	reinforcement,
	blockade,
	airlift,
	diplomacy
};

ostream& operator<<(std::ostream& out, CardType value);

//Forward Declaration
class Hand;
class Deck;

class Card
{
	//Private Members
private:
	static unsigned int nextCardID;
	unsigned int cardID;
	CardType* cardType;

	//Private Methods
private:
	friend ostream& operator<<(ostream& strm, const Card& card);

	//Public Methods
public:
	//Constructors
	Card();
	Card(const Card& card);
	Card(CardType& armyType);

	//Other Functions
	CardType& getCardType() const;
	void setCardType(CardType& armytype);
	int getCardID() const;
	void play(Hand& hand, Deck& deck);

	//Destructors
	~Card();
};

class Deck
{
	//Private Members
private:
	vector<Card*>* deckCards;
	unsigned int* cardID;
	void generateCard(int numberOfCounteries);

	//Public Members
public:

	//Private Methods
private:
	friend ostream& operator<<(ostream& strm, const Deck& deck);

	//Public Methods
public:
	//Constructors
	Deck();
	Deck(int numberOfCounteries);
	Deck(Deck& numberOfCounteries);

	//Other Functions
	Card* draw();
	void draw(Hand& hands);
	vector<Card*>* getDeckCards();
	void setDeckCards(vector<Card*>& deckCards);

	//Destructors
	~Deck();
};


class Hand
{
	//Private Members
private:
	vector<Card*> handCards;

	//Public Members
public:

	//Private Methods
private:
	friend ostream& operator<<(ostream& strm, Hand hand);
public:
	//Constructors
	Hand();

	//Other Functions
	vector<Card*>& getHandCards();
	vector<Card*> getHandCards() const;
	void setHandCards(vector<Card*>& handCards);

	//Destructors
	~Hand();
};
