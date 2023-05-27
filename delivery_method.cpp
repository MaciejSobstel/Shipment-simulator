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