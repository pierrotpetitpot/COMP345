//
//  Order.hpp
//  assignment1
//
//  Created by Pierre  Tran  on 2020-09-27.
//

#ifndef Order_hpp
#define Order_hpp

#include <stdio.h>
#include "Order.hpp"
#include <cstdint>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;



class Order
{
    public:
        string GetType();
        bool Validate();
        void Execute();
        void SetType(string type);
        Order();
        ~Order();
        Order (const Order& anOrder); //copy constructor
        Order& operator = (const Order& anOrder); //assignment operator
        friend ostream& operator << (ostream& output, Order anOrder);//stream insertion
        
        string* type; //deploy, advance, bomb, Blockade, Airlift or negotiate
        vector<string> types = {"deploy","advance","bomb","Blockade","airlift","negotiate"};
protected:

};



class Deploy : public Order
{
public:
    bool Validate();
    void Execute();
    Deploy();
    ~Deploy();
    Deploy (const Deploy& anOrder); //copy constructor
    Deploy& operator = (const Deploy& aDeploy); //assignment operator
    friend ostream& operator << (ostream& output, Deploy aDeploy);//stream insertion
};

class Advance : public Order
{
public:
    bool Validate();
   void Execute();
    Advance();
    ~Advance();
    Advance (const Advance& anAdvance); //copy constructor
    Advance& operator = (const Advance& anAdvance); //assignment operator
    friend ostream& operator << (ostream& output, Advance anAdvance);//stream insertion
};

class Bomb : public Order
{
public:
   bool Validate();
   void Execute();
    Bomb();
    ~Bomb();
    Bomb (const Bomb& aBomb); //copy constructor
    Bomb& operator = (const Bomb& aBomb); //assignment operator
    friend ostream& operator << (ostream& output, Bomb aBomb);//stream insertion
};

class Blockade : public Order
{
public:
    bool Validate();
    void Execute();
    Blockade();
    ~Blockade();
    Blockade (const Blockade& aBlockade); //copy constructor
    Blockade& operator = (const Blockade& aBlockade); //assignment operator
    friend ostream& operator << (ostream& output, Blockade aBlockade);//stream insertion
    
private:
   // string* type = &types[3] ; //deploy, advance, bomb, Blockade, Airlift or negotiate
};

class Airlift : public Order
{
public:
    bool Validate();
    void Execute();
    Airlift();
    ~Airlift();
    Airlift (const Airlift& anAirlift); //copy constructor
    Airlift& operator = (const Airlift& anAirlift); //assignment operator
    friend ostream& operator << (ostream& output, Airlift anAirlift);//stream insertion
    
private:
  //  string* type = &types[4] ; //deploy, advance, bomb, Blockade, Airlift or negotiate
};

class Negotiate : public Order
{
public:
    bool Validate();
    void Execute();
    Negotiate();
    ~Negotiate();
    Negotiate (const Negotiate& aNegotiate); //copy constructor
    Negotiate& operator = (const Negotiate& aNegotiate); //assignment operator
    friend ostream& operator << (ostream& output, Negotiate aNegotiate);//stream insertion
    
private:
   // string* type = &types[5] ; //deploy, advance, bomb, Blockade, Airlift or negotiate
};



class OrderList{

    public:
        void Move(int index1, int index2);
        void Delete(int index);
        void Push(Order* anOrder);
        void Print();
    private:
    vector<Order*> ListOfOrders;


};



#endif /* Order_hpp */


