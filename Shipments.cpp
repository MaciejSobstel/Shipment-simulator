#include <iostream>
#include <cmath>
#include "classes.h"

using namespace std;

void Shipment::set_cost(float new_cost){
    cost = std::round(new_cost * 100) / 100;
}

float Shipment::get_cost() const{
    return cost;
}

Letter::Letter(){
    set_cost(5.54982623);
}

Package::Package(float package_weight){
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

Delivery_method::Delivery_method(float input_distance){
    set_distance(input_distance);
}

void Delivery_method::set_distance(float new_distance){
    distance = std::round(new_distance * 100) / 100;
}

float Delivery_method::get_distance() const{
    return distance;
}

void Delivery_method::set_cost(float new_cost){
    cost = std::round(new_cost * 100) / 100;
}

float Delivery_method::get_cost() const{
    return cost;
}

float Delivery_method::calculate_cost(float base_price, float multiplier) const{
    float current_distance = get_distance();
    float new_cost = base_price + (current_distance / multiplier);
    return new_cost;
}

Parcel_locker::Parcel_locker(float input_distance)
    : Delivery_method(input_distance)
{
    float new_cost = calculate_cost(20.0, 5.0);
    set_cost(new_cost);
}

Delivery_man::Delivery_man(float input_distance)
    : Delivery_method(input_distance)
{
    float new_cost = calculate_cost(40.0, 5.0);
    set_cost(new_cost);
}

Mailbox::Mailbox(float input_distance)
    : Delivery_method(input_distance)
{
    float new_cost = calculate_cost(30.0, 5.0);
    set_cost(new_cost);
}
