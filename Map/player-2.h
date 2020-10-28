#pragma once
#include <iostream>
using namespace std;

//declaration of Player class for map class
class Player {
private:
    string name;                         //player name

public:
    //constructors
    Player();                            //default
    Player(string);                      //with one parameter
    Player(const Player*);               //copy constructor
    Player& operator = (const Player&);  //assignment operator
    ~Player();                           //destructor
//accessor and mutators
    string getName();
    void setName(string);
};
