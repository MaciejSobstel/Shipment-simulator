#include <string>
#include <map>
#include "locations.h"

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

Headquarters::Headquarters(float input_balance){
    set_balance(input_balance);
}

void Headquarters::send_shipment(City destination){
    // code here:
}