//
// Created by chris on 10/5/2020.
//

#include "Player.h"
#include "Order.h"
#include "Cards.h"
#include "map.h"
using namespace std;





Player::Player()
{
    hand = new Hand();
    orderList = new OrderList();
    name = "none";

}

Player::Player(string name, vector<Territory*> t)

{
    name = name;
    territories = t;
    hand = new Hand();
    orderList = new OrderList();
}

Player::Player(string name)

{
    name = name;
    hand = new Hand();
    orderList = new OrderList();
}

Player::~Player()
{
    delete hand;
    delete orderList;

}

Player::Player(const Player& other)
{
    hand = new Hand(*other.hand);
    territories = territories;
    orderList = new OrderList(*other.orderList);
    name = other.name;
}



string Player::getName() const {
    return name;
}

vector<Territory*> Player:: getTerritories() const
{
    return territories;
}

Hand* Player::getHand()
{
    return hand;
}

OrderList* Player::getOrder()
{
    return orderList;
}

void Player::setHand(Hand h)
{
    hand = &h;
}


void Player::addTerritory(Territory* newTerritory)
{
    territories.push_back(newTerritory);
}

vector<Territory*> Player::toDefend(Territory &t)
{
    vector<Territory*> defendList;
    defendList.push_back(&t);
    return defendList;
}

vector<Territory*> Player::toAttack(Territory &t)
{
    vector<Territory*> attackList;
    attackList.push_back(&t);
    return attackList;
}

void Player::issueOrder(Order *order)
{
    orderList->Push(order);
}

Player& Player::operator=(const Player& p)
{
    delete hand;
    delete orderList;
    hand = new Hand(*p.hand);
    territories = p.territories;
    name = p.name;
    return *this;
}

ostream& operator<<(ostream &os, Player& p)
{

    os << "Player: " << p.getName() << "\n";
    os << "Hand: " << p.getHand() << "\n";
    return os;

}



