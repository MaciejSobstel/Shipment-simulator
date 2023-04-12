#include <iostream>
#include "Shipments.cpp"

using namespace std;

int main(){
    Letter letter1;
    float l_cost = letter1.get_cost();
    cout << "Letter cost: " << l_cost << endl;

    Package pack1(6);
    float p_cost = pack1.get_cost();
    cout << "Package nr.1 cost: " << p_cost << endl;

    Parcel_locker pl1(15.0);
    float pl1_cost = pl1.get_cost();
    cout << "Pracel locker nr.1 cost: " << pl1_cost << endl;

    Delivery_man m1(20.0);
    float m1_cost = m1.get_cost();
    cout << "Delivery man nr.1 cost: " << m1_cost << endl;

    Mailbox mail1(25.0);
    float mail1_cost = mail1.get_cost();
    cout << "Mailbox nr.1 cost: " << mail1_cost << endl;
    return 0;
}
