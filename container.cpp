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
    map<string, Delivery_method&> del_method_map = get_delivery_methods();
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

void HQ::add_delivery_method(Delivery_method& delivery_method){
    string delivery_method_name = delivery_method.get_name();
    delivery_methods.insert({delivery_method_name, delivery_method});
}

void HQ::remove_delivery_method(Delivery_method& delivery_method){
    string del_meth_name = delivery_method.get_name();
    delivery_methods.erase(del_meth_name);
}