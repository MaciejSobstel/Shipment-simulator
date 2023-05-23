#include <iostream>
#include <cmath>

#include "shipment.h"
#include "container.cpp"

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

bool Shipment::isCitySame(const City& obj) const{
    return &destination == &obj;
}

void Shipment::set_delivery_type(string new_del_type){
    delivery_type = new_del_type;
}

string Shipment::get_delivery_type() const{
    return delivery_type;
}

void Shipment::print() const{
    string name = get_name();
    string destin = get_destination().get_name();
    string del_type = get_delivery_type();
    float cos = get_cost();
    float ex = get_expenses();
    cout << "Name: " << name << endl;
    cout << "   Destination: " << destin << endl;
    cout << "   Delivery type: " << del_type << endl;
    cout << "   Cost: " << cos << " per km" << endl;
    cout << "   Expenses: " << ex << " per km" << endl;
}

Letter::Letter(string input_name, City& destin, string del_type)
    : Shipment(input_name, destin, del_type)
{
    set_cost(5.54982623);
    set_expenses(1.0);
}

Package::Package(string input_name, City& destin, string del_type, float package_weight)
    : Shipment(input_name, destin, del_type)
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