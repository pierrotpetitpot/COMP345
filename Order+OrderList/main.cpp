//
//  main.cpp
//  assignment1
//
//  Created by Pierre  Tran  on 2020-09-27.
//

#include <iostream>
#include "Order.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    Deploy aDeploy;
    Advance anAdvance;
    Bomb aBomb;
    Blockade aBlockade;
    Airlift anAirlift;
    Negotiate aNegotiate;
    
 
    
    cout << "\n\nALL EXECUTE FUNCTIONS \n";
    aDeploy.Execute();
    anAdvance.Execute();
    aBomb.Execute();
    aBlockade.Execute();
    anAirlift.Execute();
    aNegotiate.Execute();


    cout << "\n\nORDER THAT HAS AN INVALID TYPE \n";
    aNegotiate.SetType("invalid type");
    aNegotiate.Execute();
    
    cout<<"\n\nINSTREAM OPERATOR\n";
    Order anOrder3;
    anOrder3.SetType("Deploy");
    cout << "anOrder3's type: " << anOrder3 << "\n";

    cout<<"\n\nASSIGNMENT OPERATOR\n";
    Order anOrder1;
    Order anOrder2;
    anOrder1.SetType("Negotiate");
    anOrder2 = anOrder1;
    cout<< "anOrder1's type: " << anOrder1 ;
    cout << "anOrder2's type: "<<anOrder2 << "\n";
    
    
    cout<<"\n\nPUSHING ORDERS IN ORDERLIST\n";
    OrderList listOfOrders;
    listOfOrders.Push(&anOrder1);
    listOfOrders.Push(&anOrder2);
    listOfOrders.Push(&anOrder3);
    
    
    cout<<"\n\nMOVING ORDERS IN ORDERLIST\n";
    listOfOrders.Move(0, 2);
    listOfOrders.Print();
    
    cout<<"\n\nDELETING ORDERS IN ORDERLIST\n";
    listOfOrders.Delete(1);
    listOfOrders.Print();

    
    
    return 0;
    
}
