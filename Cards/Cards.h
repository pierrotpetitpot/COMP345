//
//  Cards.h
//  assignment1
//
//  Created by Ebraheem Al Shapi.
//





#pragma once
#include <array>
#include <list> 
#include <string>
#include <iostream>
using namespace std;

enum CardType { spy, 
                bomb, 
                reinforcement, 
                blockade, 
                airlift, 
                diplomacy};

ostream& operator<<(std::ostream& out, const CardType value);

class Hand;
class Deck;

class Card {
private:
    static unsigned int nextCardID;
    unsigned int cardID;
    CardType cardType;

public:
    Card();
    ~Card();
    //Card(const Card &card);
    Card(CardType armyType);
    CardType getArmyType() const;
    void setArmyType(CardType &armytype);
    int getCardID() const;
    void play(Hand& hand,Deck& deck);
    friend ostream& operator<<(ostream& strm, const Card& card);
};

class Deck{
private:
    list<Card> allCards;
    list<Card*> deckCards;
    void generateCard(int numberOfCounteries);
public:
    Deck();
    ~Deck();
    Deck(int numberOfCounteries);
    Card* draw();
    void draw(Hand& hands);
    friend ostream& operator<<(ostream& strm, const Deck& deck);
    list<Card> getAllCards() const;
    void setAllCards(list<Card> allCards);
    list<Card*>& getDeckCards();
    void setDeckCards(list<Card*> deckCards);
};


class Hand {
private:
    list<Card*> handCards;
public:
    Hand();
    ~Hand();
    friend ostream& operator<<(ostream& strm, const Hand hand);
    list<Card*>& getHandCards();
    void setHandCards(list<Card*> handCards);

};