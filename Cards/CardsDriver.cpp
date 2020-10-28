//
//  Cards.h
//  assignment1
//
//  Created by Ebraheem Al Shapi.
//




#include "Cards.h"




int main() {
    
    Deck *deck= new Deck(50);
    cout << "Size of the deck:" << deck->getDeckCards().size() << endl;
    Hand *hand= new Hand();

    deck->draw(*hand);
    cout << "Size of the deck after drawing:" << deck->getDeckCards().size() << endl;
    cout << "Number of cards with the hand:" << hand->getHandCards().size() << endl;
    
    Card* selected = hand->getHandCards().front();

    selected->play(*hand, *deck);
    cout << "Size of the deck after playing:" << deck->getDeckCards().size() << endl;
    cout << "Number of cards with the hand after playing:" << hand->getHandCards().size() << endl;


    return 0;
}