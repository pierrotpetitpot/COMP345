#include "map.h"
#include "player.h"

//default constructor
Player::Player() {
    name = "none";
}

//one string parameter constructor
Player::Player(string playerName) {
    name = playerName;
}

//copy constructor
Player::Player(const Player* player) {

}

//assignment operator
Player& Player::operator = (const Player& player)
{
    this->name = player.name;
    return *this;
}

//destructor
Player::~Player() {

}

//accessor
string Player::getName() {
    return name;
}

//mutator
void Player::setName(string playerName) {
    name = playerName;
}

//default constructor
Territory::Territory() {
    territoryName = " ";    //Default Territory Name
    continentName = " ";    //Default Continent Name
    territoryOwner = new Player();
    armySize = 0;
}

//copy constructor
Territory::Territory(const Territory* territory) {
    territoryName = territory->territoryName;
    continentName = territory->continentName;
    territoryOwner = territory->territoryOwner;
    armySize = territory->armySize;
}

//four parameters constructor
Territory::Territory(string name, string continent, Player* player, int army) {
    territoryName = name;
    this->continentName = continent;
    territoryOwner = player;
    armySize = army;
}

//assignment operator
Territory& Territory::operator=(const Territory& territory)
{
    this->territoryName = territory.territoryName;
    this->continentName = territory.continentName;
    this->territoryOwner = territory.territoryOwner;
    this->armySize = territory.armySize;
    return *this;
}

//destructor
Territory::~Territory() {
    territoryOwner = NULL;
}

//accessor
string Territory::getterritoryName() {
    return territoryName;
}

//accessor
string Territory::getcontinentName() {
    return continentName;
}

//accessor
Player* Territory::getterritoryOwner() {
    return territoryOwner;
}

//accessor
int Territory::getarmySize() {
    return armySize;
}

//mutator
void Territory::setterritoryName(string territory_name) {
    territoryName = territory_name;
}

//mutator
void Territory::setcontinentName(string continent_name) {
    continentName = continent_name;
}

//mutator
void Territory::setTerritoryOwner(Player* p) {
    territoryOwner = p;
}

//mutator
void Territory::setarmySize(int army_num)  {
    armySize = army_num;
}

//default constructor
Map::Map() {
    this->num_territories = 0;
    this->adjacent_Matrix = nullptr;
}

//copy constructor
Map::Map(const Map *map) {
    this->num_territories = map->num_territories;
    this->adjacent_Matrix = map->adjacent_Matrix;
}

//one int parameter constructor
Map::Map(int num_territories) {
    this->num_territories = num_territories;
    adjacent_Matrix = new bool* [num_territories];
    //initialize the 2D array with false values
    for (int i = 0; i < num_territories; i++) {
        adjacent_Matrix[i] = new bool[num_territories];
        for (int j = 0; j < num_territories; j++)
            adjacent_Matrix[i][j] = false;
    }
}

//assignment operator
Map& Map::operator=(const Map& map)
{
    this->adjacent_Matrix = map.adjacent_Matrix;
    this->num_territories = map.num_territories;
    return *this;
}

//add an edge between two vertices
void Map::addEdge(int i, int j) {
    adjacent_Matrix[i][j] = true;
    adjacent_Matrix[j][i] = true;
}

//remove an edge between two vertices
void Map::removeEdge(int i, int j) {
    adjacent_Matrix[i][j] = false;
    adjacent_Matrix[j][i] = false;
}

//display the Adjacent Matrix
void Map::toString() {
    cout << "    Adjacent Matrix" << endl;
    cout << "    ";
    for (int i = 0; i < num_territories; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < num_territories; i++) {
        cout << i << " : ";
        for (int j = 0; j < num_territories; j++)
            cout << adjacent_Matrix[i][j] << " ";
        cout << "\n";
    }
}

//destructor
Map::~Map() {
    for (int i = 0; i < this->num_territories; i++)
        delete[] adjacent_Matrix[i];
    delete[] adjacent_Matrix;
}

//traverse a graph
void Map::traverse(int i, bool connect[]) {
    connect[i] = true;
    for (int j = 0; j < num_territories; j++) {
        if (adjacent_Matrix[i][j]) {
            if (!connect[j])
                traverse(j, connect);
        }
    }
}

//verify whether a graph is connected.
bool Map::Validate() {
    bool* connect = new bool[num_territories];
    //checking if the territory has been connected
    for (int i = 0; i < num_territories; i++) {
        for (int j = 0; j < num_territories; j++)
            connect[j] = false; //initialize to false if a node is not connected
        traverse(i, connect);
        for (int i = 0; i < num_territories; i++) {
            if (!connect[i]) //if there is a node that is not connected by traversal,then graph is not connected.
                return false;
        }
    }
    return true;
}