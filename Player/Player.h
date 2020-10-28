//
// Created by Chris Fleming - 26416322
//

#ifndef COMP_345_A1_PLAYER_H
#define COMP_345_A1_PLAYER_H

#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Order.h"
#include "Cards.h"
#include "map.h"

using namespace std;

class Territory;

class Player{



private:
    vector<Territory*> territories;
    vector<Territory*> defendList;
    vector<Territory*> attackList;
    Hand* hand;
    OrderList* orderList;
    string name;


public:
    Player();   //constructor
    Player(string name, vector<Territory*> t);   //parameterized constructor
    Player(string name);   //parameterized constructor
    ~Player();  //destructor
    Player(const Player&);  //copy constructor



    vector<Territory*> getTerritories() const;  //getters
    Hand* getHand();
    OrderList* getOrder();
    string getName() const;


    void setHand(Hand);  //setter

    void addTerritory(Territory* newTerritory);
    void removeTerritory(Territory* removedTerritory);
    vector<Territory*>  toDefend(Territory &t);
    vector<Territory*> toAttack(Territory &t);
    void issueOrder(Order* order);

    Player& operator=(const Player&);  //assignment operator overloading
    friend ostream& operator<<(ostream &os, Player& p);



};




#endif //COMP_345_A1_PLAYER_H
