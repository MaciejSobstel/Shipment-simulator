#include <iostream>
#include <cmath>
#include "classes.h"

using namespace std;

void Shipment::set_name(string new_name){
    name = new_name;
}

string Shipment::get_name() const {
    return name;
}

void Shipment::set_expenses(float new_expenses){
    expenses = round(new_expenses * 100) / 100;
}

float Shipment::get_expenses() const{
    return expenses;
}

void Shipment::set_cost(float new_cost){
    cost = round(new_cost * 100) / 100;
}

float Shipment::get_cost() const{
    return cost;
}

Letter::Letter(string input_name, City& destin)
    : Shipment(input_name, destin)
{
    set_cost(5.54982623);
    set_expenses(1.0);
}

Package::Package(string input_name, City& destin, float package_weight)
    : Shipment(input_name, destin)
{
    set_weight(package_weight);
    float new_cost = package_weight * 2.5;
    float new_expenses = package_weight * 0.5;
    set_cost(new_cost);
    set_expenses(new_expenses);
}

void Package::set_weight(float new_weight){
    weight = new_weight;
}

float Package::get_weight() const{
    return weight;
}

Delivery_method::Delivery_method(string input_name){
    set_name(input_name);
}

void Delivery_method::set_name(string new_name){
    name = new_name;
}

string Delivery_method::get_name() const {
    return name;
}

void Delivery_method::set_base_price(float new_price){
    base_price = round(new_price * 100) / 100;
}

float Delivery_method::get_base_price() const{
    return base_price;
}

void Delivery_method::set_expenses(float new_expenses){
    expenses = round(new_expenses * 100) / 100;
}

float Delivery_method::get_exepenses() const{
    return expenses;
}

Parcel_locker::Parcel_locker(string input_name)
    : Delivery_method(input_name)
{
    float new_price = 0.5;
    float new_expenses = 0.3;
    set_base_price(new_price);
    set_expenses(new_expenses);

}

Delivery_man::Delivery_man(string input_name)
    : Delivery_method(input_name)
{
    float new_price = 1.0;
    float new_expenses = 0.5;
    set_base_price(new_price);
    set_expenses(new_expenses);
}

Mailbox::Mailbox(string input_name)
    : Delivery_method(input_name)
{
    float new_price = 0.8;
    float new_expenses = 0.4;
    set_base_price(new_price);
    set_expenses(new_expenses);
}


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