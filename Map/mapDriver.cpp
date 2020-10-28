#include "Map.h"
#include<iostream>
#include <iomanip> //included this library in order to use set(w) function.

int main() {


    //creating a Map object and adding edges to it

    Map* map1 = new Map(8);
    map1->addEdge(0, 1);
    map1->addEdge(0, 4);
    map1->addEdge(1, 2);
    map1->addEdge(1, 5);
    map1->addEdge(2, 3);
    map1->addEdge(2, 6);
    map1->addEdge(3, 7);

    map1->toString();

    //testing Map object if its a connected graph.
    if (map1->Validate())
        cout << "Map is a connected graph.\n" << endl;
    else
        cout << "Map is not a connected graph.\n" << endl;

    cout << "checking another map for connectivity\n" << endl;

    //test a connected graph
    Map* map2 = new Map(4);
    map2->addEdge(0, 1);
    map2->addEdge(1, 2);
    map2->addEdge(2, 3);
    map2->toString();
    if (map2->Validate())
        cout << "map2 is a connected graph.\n" << endl;
    else
        cout << "map2 is not a connected graph.\n" << endl;

    //testing a graph that is not connected
    Map* map3 =new Map(4);
    map3->addEdge(0, 1);
    map3->addEdge(1, 2);
    map3->toString();
    if (map3->Validate())
        cout << "map3 is a connected graph.\n" << endl;
    else
        cout << "map3 is not a connected graph.\n" << endl;

    //creating Players
    Player* p1 = new Player("Abc");
    Player* p2 = new Player("xyz");

    //creating territories
    Territory* t1 = new Territory("Eastern", "Asia", p1, 15);
    Territory* t2 = new Territory("Western", "North America", p2, 20);
    Territory* t3 = new Territory("Central", "Europe", new Player(), 0);
    Territory* t4 = new Territory("Southern", "Africa", new Player(), 0);
    Territory* t5 = new Territory("Far East", "Oceania", new Player(), 0);
    Territory* t6 = new Territory("Southern West", "South America", new Player(), 0);


    //collect territory objects into an array
    Territory territory_Array[6];
    territory_Array[0] = *t1;
    territory_Array[1] = *t2;
    territory_Array[2] = *t3;
    territory_Array[3] = *t4;
    territory_Array[4] = *t5;
    territory_Array[5] = *t6;


    //display territory information
    cout << "Index" << setw(16) << "Territory"
         << "   " << "     Continent"
         << "    " << "Owner"
         << "       " << "Army" << endl;
    for (int i = 0; i < 6; i++) {
        cout << setw(2) << i
             << setw(18) << territory_Array[i].getterritoryName()
             << setw(15) << territory_Array[i].getcontinentName()
             << setw(12) << territory_Array[i].getterritoryOwner()->getName()
             << setw(12) << territory_Array[i].getarmySize() << endl;
    }

    //calling destructors to avoid memory leak
    delete map1;
    delete map2;
    delete map3;
    delete p1;
    delete p2;
    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete t5;
    delete t6;


}