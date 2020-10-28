//
//  Order.cpp
//  assignment1
//
//  Created by Pierre  Tran  on 2020-09-27.
//

//TODO: SUB CLASS
//TODO: ORDERLIST
//TODO: MAIN FUNCTION



#include "Order.hpp"
#include <cstdint>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


//BASE CLASS ORDER
string Order::GetType(){
    
    string* pointer = this->type;
    string type = *pointer;
    
    return type;
    
}

void Order::SetType(string type){
    
    this->type = &type;
}

bool Order::Validate(){ //returns true if it is valid
    bool validation = false;
    string type = this->GetType();

    if (find(types.begin(), types.end(), type ) != types.end())
        validation = true;

    return validation;
}


void Order::Execute(){ //base class
    string type = this->GetType();

    if(!(this->Validate())) //Validate() //returns false if object is not valid
      cout << "This order is not valid" << "\n";

    else{

        if(type.compare(types.at(0)) == 0)
            cout << "Deploy order\n";
        else if(type.compare(types.at(1)) == 0)
            cout << "Advance order\n";
        else if(type.compare(types.at(2)) == 0)
            cout << "Bomb order\n";
        else if(type.compare(types.at(3)) == 0)
            cout << "Blockade order\n";
        else if(type.compare(types.at(4)) == 0)
            cout << "Airlift order\n";
        else if(type.compare(types.at(5)) == 0)
            cout << "Negotiate order\n";
    }

}



Order::Order(){ //default constructor
    type = new string("");
}



Order::~Order(){ //destructor
    
   // delete type;
    type = NULL;
    
}


Order::Order(const Order& anOrder){ //copy constructor
    
    type = new string;
    
    *type = *anOrder.type;
    
}




Order& Order::operator=(const Order& toAssign)
{
    if (this != &toAssign)
    {
        type = toAssign.type;
    }
    return *this;
}


 ostream& operator << (ostream &output, Order anOrder){
    
     output << "This order's type is " + anOrder.GetType() + "\n";
    
    return output;
    
}

//DEPLOY FUNCTIONS

bool Deploy::Validate(){ //Validate of Deploy class
        
    string thisType = "Deploy";
    string type = this->GetType();
    
    bool validation = false;
    
    if (thisType.compare(type) == 0)
        validation = true;
    
    return validation;
}


void Deploy::Execute(){ //Deploy class
    
    if(!(this->Validate())) //Validate() //returns false if object is not valid
        cout << "This order is not valid" << "\n";
    
    else{
            cout << "Deploy order\n";
    }
}

Deploy::Deploy(){
    
    SetType("Deploy");
    
}

Deploy::~Deploy(){ //destructor
    
    //delete type;
    type = NULL;
    
}

Deploy::Deploy(const Deploy& aDeploy){ //copy constructor
    
    type = new string;
    
    *type = *aDeploy.type;
    
}

Deploy& Deploy::operator=(const Deploy& toAssign)
{
    if (this != &toAssign)
    {
        type = toAssign.type;
    }
    return *this;
}


 ostream& operator << (ostream &output,  Deploy aDeploy){

     output << "This order's type is " + aDeploy.GetType() + "\n";

    return output;

}


//ADVANCE FUNCTIONS

bool Advance::Validate(){ //Validate of Advance class
        
    string thisType = "Advance";
    string type = this->GetType();
    
    bool validation = false;
    
    if (thisType.compare(type) == 0)
        validation = true;
    
    return validation;
}


void Advance::Execute(){ //Deploy class
    
    if(!(this->Validate())) //Validate() //returns false if object is not valid
        cout << "This order is not valid" << "\n";
    
    else{
            cout << "Advance order\n";
    }
}

Advance::Advance(){
    
    SetType("Advance");
    
}

Advance::~Advance(){ //destructor
    
    //delete type;
    type = NULL;
    
}

Advance::Advance(const Advance& anAdvance){ //copy constructor
    
    type = new string;
    
    *type = *anAdvance.type;
    
}

Advance& Advance::operator=(const Advance& toAssign)
{
    if (this != &toAssign)
    {
        type = toAssign.type;
    }
    return *this;
}



 ostream& operator << (ostream &output, Advance anAdvance){
    
     output << "This order's type is " + anAdvance.GetType() + "\n";
    
    return output;
    
}

//BOMB FUNCTIONS
bool Bomb::Validate(){ //Validate of Advance class
        
    string thisType = "Bomb";
    string type = this->GetType();
    
    bool validation = false;
    
    if (thisType.compare(type) == 0)
        validation = true;
    
    return validation;
}


void Bomb::Execute(){ //
    
    if(!(this->Validate())) //Validate() //returns false if object is not valid
        cout << "This order is not valid" << "\n";
    
    else{
            cout << "Bomb order\n";
    }
}

Bomb::Bomb(){
    
    SetType("Bomb");
    
}

Bomb::~Bomb(){ //destructor
    
    //delete type;
    type = NULL;
    
}

Bomb::Bomb(const Bomb& aBomb){ //copy constructor
    
    type = new string;
    
    *type = *aBomb.type;
    
}

Bomb& Bomb::operator=(const Bomb& toAssign)
{
    if (this != &toAssign)
    {
        type = toAssign.type;
    }
    return *this;
}



 ostream& operator << (ostream &output, Bomb aBomb){
    
     output << "This order's type is " + aBomb.GetType() + "\n";
    
    return output;
    
}

//Blockade FUNCTIONS
bool Blockade::Validate(){
        
    string thisType = "Blockade";
    string type = this->GetType();
    
    bool validation = false;
    
    if (thisType.compare(type) == 0)
        validation = true;
    
    return validation;
}


void Blockade::Execute(){ //
    
    if(!(this->Validate())) //Validate() //returns false if object is not valid
        cout << "This order is not valid" << "\n";
    
    else{
            cout << "Blockade order\n";
    }
}

Blockade::Blockade(){
    
    SetType("Blockade");
    
}

Blockade::~Blockade(){ //destructor
    
    //delete type;
    type = NULL;
    
}

Blockade::Blockade(const Blockade& aBlockade){ //copy constructor
    
    type = new string;
    
    *type = *aBlockade.type;
    
}

Blockade& Blockade::operator=(const Blockade& toAssign)
{
    if (this != &toAssign)
    {
        type = toAssign.type;
    }
    return *this;
}



 ostream& operator << (ostream &output, Blockade aBlockade){
    
     output << "This order's type is " + aBlockade.GetType() + "\n";
    
    return output;
    
}

//Airlift FUNCTIONS
bool Airlift::Validate(){
        
    string thisType = "Airlift";
    string type = this->GetType();
    
    bool validation = false;
    
    if (thisType.compare(type) == 0)
        validation = true;
    
    return validation;
}


void Airlift::Execute(){ //
    
    if(!(this->Validate())) //Validate() //returns false if object is not valid
        cout << "This order is not valid" << "\n";
    
    else{
            cout << "Airlift order\n";
    }
}

Airlift::Airlift(){
    
    SetType("Airlift");
    
}

Airlift::~Airlift(){ //destructor
    
    //delete type;
    type = NULL;
    
}

Airlift::Airlift(const Airlift& anAirlift){ //copy constructor
    
    type = new string;
    
    *type = *anAirlift.type;
    
}

Airlift& Airlift::operator=(const Airlift& toAssign)
{
    if (this != &toAssign)
    {
        type = toAssign.type;
    }
    return *this;
}



 ostream& operator << (ostream &output, Airlift anAirlift){
    
     output << "This order's type is " + anAirlift.GetType() + "\n";
    
    return output;
    
}


//NEGOTIATE FUNCTIONS
bool Negotiate::Validate(){
        
    string thisType = "Negotiate";
    string type = this->GetType();
    
    bool validation = false;
    
    if (thisType.compare(type) == 0)
        validation = true;
    
    return validation;
}


void Negotiate::Execute(){ //
    
    if(!(this->Validate())) //Validate() //returns false if object is not valid
        cout << "This order is not valid" << "\n";
    
    else{
            cout << "Negotiate order\n";
    }
}

Negotiate::Negotiate(){
    
    SetType("Negotiate");
    
}

Negotiate::~Negotiate(){ //destructor
    
    //delete type;
    type = NULL;
    
}

Negotiate::Negotiate(const Negotiate& aNegotiate){ //copy constructor
    
    type = new string;
    
    *type = *aNegotiate.type;
    
}

Negotiate& Negotiate::operator=(const Negotiate& toAssign)
{
    if (this != &toAssign)
    {
        type = toAssign.type;
    }
    return *this;
}



 ostream& operator << (ostream &output, Negotiate aNegotiate){
    
     output << "This order's type is " + aNegotiate.GetType() + "\n";
    
    return output;
    
}




//ORDERLIST FUCNTIONS
void OrderList::Push(Order* orderPtr){
  //  cout<<"Pushing: " << *(orderPtr->type);
    cout<<"Pushing: " << orderPtr->GetType() << "\n";
    ListOfOrders.push_back(orderPtr);
    
}

void OrderList::Move(int index1, int index2){

    cout<<"Swapping objects at position " << index1 << " and at position " << index2 << " \n";
    iter_swap(ListOfOrders.begin() + index1, ListOfOrders.begin() + index2);


}

void OrderList::Delete(int index){
    cout<< "Deleting order at position " << index << "\n";
    ListOfOrders.erase(ListOfOrders.begin()+index);
}

void OrderList::Print(){
    
    
    for(int i = 0 ; i < ListOfOrders.size(); i++){
        
        cout << ListOfOrders.at(i)->GetType() << "\n";
        
        
    }
    
}




