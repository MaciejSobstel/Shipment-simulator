#include <iostream>
#include "delivery_method.h"
#include <cmath>


using namespace std;

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

float Delivery_method::get_expenses() const{
    return expenses;
}

void Delivery_method::set_delivery_type(string new_del_type){
    delivery_type = new_del_type;
}

string Delivery_method::get_delivery_type() const{
    return delivery_type;
}

void Delivery_method::print() const{
    string name = get_name();
    string del_type = get_delivery_type();
    float cos = get_base_price();
    float ex = get_expenses();
    cout << "Name: " << name << endl;
    cout << "   Delivery type: " << del_type << endl;
    cout << "   Cost: " << cos << " per km" << endl;
    cout << "   Expenses: " << ex << " per km" << endl;
}

Parcel_locker::Parcel_locker(string input_name)
    : Delivery_method(input_name)
{
    float new_price = 0.5;
    float new_expenses = 0.3;
    set_base_price(new_price);
    set_expenses(new_expenses);
    set_delivery_type("Parcel locker");
}

Delivery_man::Delivery_man(string input_name)
    : Delivery_method(input_name)
{
    float new_price = 1.0;
    float new_expenses = 0.5;
    set_base_price(new_price);
    set_expenses(new_expenses);
    set_delivery_type("Delivery man");
}

Mailbox::Mailbox(string input_name)
    : Delivery_method(input_name)
{
    float new_price = 0.8;
    float new_expenses = 0.4;
    set_base_price(new_price);
    set_expenses(new_expenses);
    set_delivery_type("Mailbox");
}