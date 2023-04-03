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
