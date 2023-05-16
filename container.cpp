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
    cout << "Here's what we have in storage:\n";
    for (auto it = ship_map.begin(); it != ship_map.end(); ++it) {
        cout << it->first << endl;
    }
    cout << endl;
}

void HQ::send_shipment(Shipment ship){
    remove_shipment(ship);
}