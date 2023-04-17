#include <iostream>
#include <cmath>
#include "classes.h"

using namespace std;

Shipment::Shipment(string input_name){
    set_name(input_name);
}

void Shipment::set_name(string new_name){
    name = new_name;
}

string Shipment::get_name() const {
    return name;
}

void Shipment::set_cost(float new_cost){
    cost = round(new_cost * 100) / 100;
}

float Shipment::get_cost() const{
    return cost;
}

Letter::Letter(string input_name)
    : Shipment(input_name)
{
    set_cost(5.54982623);
}

Package::Package(string input_name, float package_weight)
    : Shipment(input_name)
{
    set_weight(package_weight);
    float new_cost = package_weight * 2.5;
    set_cost(new_cost);
}

void Package::set_weight(float new_weight){
    weight = new_weight;
}

float Package::get_weight() const{
    return weight;
}

Delivery_method::Delivery_method(string input_name, float input_distance){
    set_name(input_name);
    set_distance(input_distance);
}

void Delivery_method::set_name(string new_name){
    name = new_name;
}

string Delivery_method::get_name() const {
    return name;
}

void Delivery_method::set_distance(float new_distance){
    distance = std::round(new_distance * 100) / 100;
}

float Delivery_method::get_distance() const{
    return distance;
}

void Delivery_method::set_cost(float new_cost){
    cost = round(new_cost * 100) / 100;
}

float Delivery_method::get_cost() const{
    return cost;
}

float Delivery_method::calculate_cost(float base_price, float multiplier) const{
    float current_distance = get_distance();
    float new_cost = base_price + (current_distance / multiplier);
    return new_cost;
}

Parcel_locker::Parcel_locker(string input_name, float input_distance)
    : Delivery_method(input_name, input_distance)
{
    float new_cost = calculate_cost(20.0, 5.0);
    set_cost(new_cost);
}

Delivery_man::Delivery_man(string input_name, float input_distance)
    : Delivery_method(input_name, input_distance)
{
    float new_cost = calculate_cost(40.0, 5.0);
    set_cost(new_cost);
}

Mailbox::Mailbox(string input_name, float input_distance)
    : Delivery_method(input_name, input_distance)
{
    float new_cost = calculate_cost(30.0, 5.0);
    set_cost(new_cost);
}

Headquarters::Headquarters(float input_balance){
    set_balance(input_balance);
}

void Headquarters::add_Shipment(Shipment shipment){
    shipments.push_back(shipment);
}

vector<Shipment> Headquarters::get_Shipments() const {
    return shipments;
}

void Headquarters::print_Shipments() const {
    vector<Shipment> v = get_Shipments();
    cout << "Here's what we have in storage:\n";
    for (auto x : v) {
        std::cout << x.get_name() << " ";
    }
    std::cout << std::endl;
}

void Headquarters::set_balance(float new_balance){
    balance = new_balance;
}

void Headquarters::add_to_balance(float price){
    float curr_balance = get_balance();
    curr_balance += price;
    balance = curr_balance;
}

float Headquarters::get_balance() const {
    return balance;
}
