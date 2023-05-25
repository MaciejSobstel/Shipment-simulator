#include <iostream>
#include <map>

#include "container.h"

using namespace std;

void Container::add_shipment(Shipment shipment){
    std::string shipment_name = shipment.get_name();
    shipments.insert({shipment_name, shipment});
}

void Container::remove_shipment(Shipment shipment){
    std::string shipment_name = shipment.get_name();
    shipments.erase(shipment_name);
}

std::map<std::string, Shipment> Container::get_shipments() const {
    return shipments;
}

void Container::print_shipments() const {
    map<string, Shipment> ship_map = get_shipments();
    int shipCount = 1;
    cout << "Here's what we have in storage:\n";
    if (ship_map.empty()) {
        cout << "Empty" << endl;
    } else {
        for (auto it = ship_map.begin(); it != ship_map.end(); ++it) {
        const Shipment& shipment = it->second;
        cout << shipCount << ".[";
        shipment.print();
        cout << "]" << endl;
        shipCount++;
        }
    }
    cout << endl;
}

void HQ::send_shipment(Shipment ship){
    remove_shipment(ship);
}

void HQ::print_delivery_methods() const {
    map<string, Delivery_method> del_method_map = get_delivery_methods();
    int delCount = 1;
    cout << "Here are our available delivery methods:\n";
    if (del_method_map.empty()) {
        cout << "Empty" << endl;
    } else {
        for (auto it = del_method_map.begin(); it != del_method_map.end(); ++it) {
        const Delivery_method& del_met = it->second;
        cout << delCount << ".[";
        del_met.print();
        cout << "]" << endl;
        delCount++;
        }
    }
    cout << endl;
}

void HQ::add_delivery_method(Delivery_method delivery_method){
    string delivery_method_name = delivery_method.get_name();
    delivery_methods.insert({delivery_method_name, delivery_method});
}

void HQ::remove_delivery_method(Delivery_method delivery_method){
    string del_meth_name = delivery_method.get_name();
    delivery_methods.erase(del_meth_name);
}

string HQ::generate_parcel_locker_name(){
    int par_lock_num = getParcelLockerNum();
    string str_num = to_string(par_lock_num);
    countParcelLockerNumUp();
    string result = "Parcel locker " + str_num;
    return result;
}

string HQ::generate_mailbox_name(){
    int mail_num = getMailboxNum();
    string str_num = to_string(mail_num);
    countParcelLockerNumUp();
    string result = "Mailbox " + str_num;
    return result;
}

string HQ::generate_delivery_man_name(){
    int dm_num = getDeliveryManNum();
    string str_num = to_string(dm_num);
    countParcelLockerNumUp();
    string result = "Delivery man " + str_num;
    return result;
}

void HQ::buy_parcel_locker(){
    string name = generate_parcel_locker_name();
    Parcel_locker par_lock(name);
    addjust_balance(-120);
    add_delivery_method(par_lock);
}

void HQ::buy_mailbox(){
    string name = generate_mailbox_name();
    Mailbox mail(name);
    addjust_balance(-200);
    add_delivery_method(mail);
}

void HQ::buy_delivery_man(){
    string name = generate_delivery_man_name();
    Delivery_man dm(name);
    addjust_balance(-300);
    add_delivery_method(dm);
}

void HQ::print_balance() const{
    float bal = get_balance();
    cout << "Your current balance: " << bal <<"$" << endl;
}