#include <iostream>
#include <cmath>
#include <fstream>

#include "shipment.h"

using namespace std;

void Container::add_shipment(Shipment shipment){
    std::string shipment_name = shipment.get_name();
    shipments.insert({shipment_name, shipment});
}

void Container::remove_shipment(string shipment_name){
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

inline std::ostream& operator<<(ostream& os, const City& city){
    os << "\tCITY{\n" << city.distance <<",\n" <<city.name <<",\n";
    for(const auto& kv: city.shipments){
        os << kv.second;
    }
    os << "}" <<endl;
    return os;
}

inline std::istream& operator>>(istream& is, City& city){
    string s;
    is >> s;
    is >> s;
    s.pop_back();
    city.set_distance(std::stof(s));
    is >> s;
    s.pop_back();
    city.set_name(s);
    char c;
    is >> c;
    while (c!='}'){
        is.putback(c);
        Shipment new_shipment;
        is >> new_shipment;
        city.add_shipment(new_shipment);
        is >> c;
    }
    return is;
}

void HQ::print_delivery_methods() const {
    map<string, Delivery_method> del_method_map = get_delivery_methods();
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

void HQ::add_delivery_method(Delivery_method delivery_method){
    string delivery_method_name = delivery_method.get_name();
    delivery_methods.insert({delivery_method_name, delivery_method});
}

void HQ::remove_delivery_method(Delivery_method delivery_method){
    string del_meth_name = delivery_method.get_name();
    delivery_methods.erase(del_meth_name);
}

string HQ::generate_parcel_locker_name(){
    int par_lock_num = getParcelLockerNum();
    string str_num = to_string(par_lock_num);
    countParcelLockerNumUp();
    string result = "Parcel_locker" + str_num;
    return result;
}

string HQ::generate_mailbox_name(){
    int mail_num = getMailboxNum();
    string str_num = to_string(mail_num);
    countMailboxNumUp();
    string result = "Mailbox" + str_num;
    return result;
}

string HQ::generate_delivery_man_name(){
    int dm_num = getDeliveryManNum();
    string str_num = to_string(dm_num);
    countDeliveryManNumUp();
    string result = "Delivery_man" + str_num;
    return result;
}

void HQ::buy_parcel_locker(){
    if(get_balance() < 120){
        cout<<"Not enough money"<<endl;
    }else {
        string name = generate_parcel_locker_name();
        Parcel_locker par_lock(name);
        addjust_balance(-120);
        add_delivery_method(par_lock);
    }
}

void HQ::buy_mailbox(){
    if (get_balance() < 200){
        cout<<"Not enough money"<<endl;
    }
    else {
        string name = generate_mailbox_name();
        Mailbox mail(name);
        addjust_balance(-200);
        add_delivery_method(mail);
    }
}

void HQ::buy_delivery_man(){
    if (get_balance() < 300){
        cout<<"Not enough money"<<endl;
    } else{
        string name = generate_delivery_man_name();
        Delivery_man dm(name);
        addjust_balance(-300);
        add_delivery_method(dm);
    }
}

void HQ::print_balance() const{
    float bal = get_balance();
    cout << "Your current balance: " << bal <<"$" << endl;
}

void HQ::saveState(std::string file="HQSave.txt") const{
    std::ofstream f;
    f.open(file);
    f << *this;
    f.close();
}

void HQ::loadState(std::string file="HQSave.txt"){
    std::ifstream f;
    f.open(file);
    f >> *this;
    f.close();
}

bool HQ::sendDeliveryMethod(string del_met_type) {
    auto it = delivery_methods.begin();
    while (it != delivery_methods.end()) {
        if (it->second.get_delivery_type() == del_met_type) {
            const string name = it->second.get_name();
            working_delivery_methods.insert({name, it->second});
            delivery_methods.erase(it);
            return true;
        }
        ++it;
    }
    return false;
}

void HQ::returnDeliveryMethods(){
    for (const auto& methodPair : working_delivery_methods) {
        const string& name = methodPair.second.get_name();
        delivery_methods.insert({name, methodPair.second});
    }
    working_delivery_methods.clear();
}

inline std::ostream& operator<<(ostream& os, const HQ& hq){
    os << "\tHQ{\n" << hq.get_balance() <<",\n";
    os << hq.getMailboxNum() <<",\n";
    os << hq.getDeliveryManNum() <<",\n";
    os << hq.getParcelLockerNum() <<",\n";
    for(const auto& kv: hq.delivery_methods){
        os << kv.second;
    }
    os << "}" <<endl;
    return os;
}

inline std::istream& operator>>(istream& is, HQ& hq){
    string s;
    is >> s;
    is >> s;
    s.pop_back();
    hq.set_balance(stof(s));
    is >> s;
    s.pop_back();
    hq.setMailboxNum(stoi(s));
    is >> s;
    s.pop_back();
    hq.setDeliveryManNum(stoi(s));
    is >> s;
    s.pop_back();
    hq.setParcelLockerNum(stoi(s));
    char c;
    is >> c;
    while (c!='}'){
        is.putback(c);
        Delivery_method method;
        is >> method;
        hq.add_delivery_method(method);
        is >> c;
    }
    return is;
}

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
    return destination == obj.get_name();
}

void Shipment::set_delivery_type(string new_del_type){
    delivery_type = new_del_type;
}

string Shipment::get_delivery_type() const{
    return delivery_type;
}

void Shipment::print() const{
    string name = get_name();
    string destin = get_destination();
    string del_type = get_delivery_type();
    float cos = get_cost();
    float ex = get_expenses();
    cout << "Name: " << name << endl;
    cout << "   Destination: " << destin << endl;
    cout << "   Delivery type: " << del_type << endl;
    cout << "   Cost: " << cos << " per km" << endl;
    cout << "   Expenses: " << ex << " per km" << endl;
}

inline std::ostream& operator<<(ostream& os, const Shipment& shipment){
    os << "\tSHIPMENT{\n" << shipment.get_destination() <<",\n";
    os << shipment.get_cost() <<",\n";
    os << shipment.get_expenses() <<",\n";
    os << shipment.get_name() <<",\n";
    os << shipment.get_delivery_type() <<",\n";
    os << "}" <<endl;
    return os;
}

inline std::istream& operator>>(istream& is, Shipment& shipment){
    string s;
    is >> s;
    is >> s;
    s.pop_back();
    shipment.set_destination(s);
    is >> s;
    s.pop_back();
    shipment.set_cost(stof(s));
    is >> s;
    s.pop_back();
    shipment.set_expenses(stof(s));
    is >> s;
    s.pop_back();
    shipment.set_name(s);
    is >> s;
    s.pop_back();
    shipment.set_delivery_type(s);
    is >> s;
    return is;
}

Letter::Letter(string input_name, string destin, string del_type)
    : Shipment(input_name, destin, del_type)
{
    set_cost(5.54982623);
    set_expenses(1.0);
}

Package::Package(string input_name, string destin, string del_type, float package_weight)
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