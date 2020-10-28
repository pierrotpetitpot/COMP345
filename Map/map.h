#pragma once
#include <iostream>
#include "player.h"
using namespace std;



//declaration of Territory class
class Territory {
private:
// variables
    string territoryName, continentName;      //the territory and continent name.
    Player* territoryOwner;                  //the owner of a territory
    int armySize;                           //the number of army(ies) in a territory

public:
//constructors
    Territory();                                //default
    Territory(const Territory*);                //copy
    Territory(string, string, Player*, int);    //with four parameters.
    Territory& operator = (const Territory&);   //assignment operator
    ~Territory();                               //destructor
//accessors
    string getterritoryName();
    string getcontinentName();
    Player* getterritoryOwner();
    int getarmySize();
//mutators
    void setterritoryName(string);
    void setcontinentName(string);
    void setTerritoryOwner(Player*);
    void setarmySize(int);

};

//declaration of Map class
class Map {
private:
//variables
    bool** adjacent_Matrix;           //2D boolean Array to represent Adjacent Matrix.
    int num_territories;            //int variable to store number of territories.

public:
 // constructors
    Map();                      //default
    Map(int);                   // with one int parameter.
    Map(const Map*);            //copy constructor
    Map& operator = (const Map&);//assignment operator
    ~Map();                     //destructor
//functions
    void addEdge(int, int);     //add an edge between two territories
    void removeEdge(int, int);  //remove an edge between two territories
    void toString();            //display the Adjacency Matrix
    void traverse(int, bool*);  //traverse the passed graph
    bool Validate();            //verify a graph whether connected or not
};
