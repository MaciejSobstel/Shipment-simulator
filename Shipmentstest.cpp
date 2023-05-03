#include <iostream>
#include "Shipment.cpp"

using namespace std;

int main(){
    Letter letter1("letter1");
    float l_cost = letter1.get_cost();
    string l_name = letter1.get_name();
    cout << "Letter name: " << l_name << endl;
    cout << "Letter cost: " << l_cost << endl;

    Package pack1("pack1", 6);
    float p_cost = pack1.get_cost();
    string p_name = pack1.get_name();
    cout << "Package name: " << p_name << endl;
    cout << "Package cost: " << p_cost << endl;

    Parcel_locker pl1("pl1", 15.0);
    float pl1_cost = pl1.get_cost();
    string pl1_name = pl1.get_name();
    cout << "Parcel locker name: " << pl1_name << endl;
    cout << "Parcel locker cost: " << pl1_cost << endl;

    Delivery_man m1("Marek", 20.0);
    float m1_cost = m1.get_cost();
    string m1_name = m1.get_name();
    cout << "Delivery man name: " << m1_name << endl;
    cout << "Delivery man cost: " << m1_cost << endl;

    Mailbox mail1("mail1", 25.0);
    float mail1_cost = mail1.get_cost();
    string mail1_name = mail1.get_name();
    cout << "Mailbox name: " << mail1_name << endl;
    cout << "Mailbox cost: " << mail1_cost << endl;

    Headquarters h1(1000.35);
    h1.add_shipment(letter1);
    h1.add_shipment(pack1);
    h1.print_shipments();
    h1.send_shipment(letter1, m1);
    h1.print_shipments();
    float h1_balance = h1.get_balance();
    cout << h1_balance << "$" << endl;
    return 0;
}
