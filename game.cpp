#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <fstream>
#include "game.h"

using namespace std;

void Game::add_city(City city){
    string city_name = city.get_name();
    cities.insert({city_name, city});
}

void Game::remove_city(City city){
    string city_name = city.get_name();
    cities.erase(city_name);
}

City& Game::get_city(string name){
    return cities.at(name);
}

void Game::print_cities() const {
    map<string, City> cities_map = get_cities();
    int cityCount = 1;
    cout << "Cities:\n";
    for (auto it = cities_map.begin(); it != cities_map.end(); ++it) {
        const City& city = it->second;
        float dist = city.get_distance();
        cout << cityCount << ". " << it->first << endl;
        cout << "Distance from HQ: " << dist << "km" << endl;
        cityCount++;
        city.print_shipments();
    }
    cout << endl;
}

bool Game::isDeliveryTypeSame(Shipment shipment, Delivery_method del_method) const{
    string shipment_del_type = shipment.get_delivery_type();
    string delivery_del_type = del_method.get_delivery_type();
    return shipment_del_type == delivery_del_type;
}

string Game::RandomiseDeliveryType() const{
    string choices[] = { "Mailbox", "Delivery_man", "Parcel_locker" };

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dist(0, 2);
    int randomIndex = dist(gen);

    return choices[randomIndex];
}

City& Game::RandomiseCity() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, cities.size() - 1);
    int randomIndex = dist(gen);
    auto it = cities.begin();
    std::advance(it, randomIndex);
    auto key = it->first;
    return cities.at(key);
}

float Game::RandomiseWeight(){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(1.0, 10.0);

    float randomValue = dist(gen);

    randomValue = round(randomValue * 10) / 10.0f;

    return randomValue;
}

string Game::generateLetterName(){
    int letter_num = getLetterNum();
    string str_num = to_string(letter_num);
    countLetterNumUp();
    string result = "letter" + str_num;
    return result;
}

string Game::generatePackageName(){
    int package_num = getPackageNum();
    string str_num = to_string(package_num);
    countPackageNumUp();
    string result = "package" + str_num;
    return result;
}

Shipment Game::generateShipment(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, 1);

    int randomNumber = distribution(gen);
    string destin = RandomiseCity().get_name();
    string del_type = RandomiseDeliveryType();
    if (randomNumber == 0) {
        string name = generateLetterName();
        return Letter(name, destin, del_type);
    } else {
        string name = generatePackageName();
        float weight = RandomiseWeight();
        return Package(name, destin, del_type, weight);
    }
}

void Game::genShipmentInCity(){
    City& city = RandomiseCity();
    Shipment ship = generateShipment();
    city.add_shipment(ship);
}

Delivery_method Game::getDelMethod(HQ& hq, string del_method) const {
    std::map<std::string, Delivery_method> delivery_methods_map = hq.get_delivery_methods();
    for (const auto& methodPair : delivery_methods_map) {
        if (methodPair.first == del_method) {
            return methodPair.second;
        }
    }
    throw runtime_error("Delivery method not found");
}

Shipment Game::getShipment(HQ& hq, string shipment) const{
    std::map<std::string, Shipment> ship_map = hq.get_shipments();
    for (const auto& methodPair : ship_map) {
        if (methodPair.first == shipment) {
            return methodPair.second;
        }
    }
    throw runtime_error("Shipment not found");
}

float Game::calCost(string ship, string str_del_met, City city, HQ& hq) const{
    Shipment shipment = getShipment(hq, ship);
    Delivery_method del_met = getDelMethod(hq, str_del_met);
    float ship_cost = shipment.get_cost();
    float del_cost = del_met.get_base_price();
    float dist = city.get_distance();
    float result = dist * ship_cost * del_cost;
    return result;
}

float Game::calExpenses(string str_ship, string str_del_met, City city, HQ& hq) const{
    Shipment shipment = getShipment(hq, str_ship);
    Delivery_method del_met = getDelMethod(hq, str_del_met);
    float ship_ex = shipment.get_expenses();
    float del_ex = del_met.get_expenses();
    float dist = city.get_distance();
    float result = dist * ship_ex * del_ex;
    return -result;
}

void Game::retreivePackage(string city_name, string str_del_met, HQ& hq){
    Delivery_method del_met = getDelMethod(hq, str_del_met);
    City& city = cities.at(city_name);
    map<string, Shipment> cityShipments = city.get_shipments();
    for (const auto& shipmentPair : cityShipments) {
        Shipment shipment = shipmentPair.second;
        hq.add_shipment(shipment);
    }
    cityShipments.clear();
    city.set_shipments(cityShipments);
}

void Game::sendPackage(string city_name, string del_method, string shipment_name, HQ& hq){
    map<string, Shipment> shipmap = hq.get_shipments();
    hq.remove_shipment(shipment_name);
    Shipment ship = shipmap[shipment_name];
    string destination = ship.get_destination();
    string delivery = ship.get_delivery_type();
    map<string, City> citymap = get_cities();
    float exp = calExpenses(shipment_name, del_method, citymap[city_name], hq);
    hq.addjust_balance(exp);
    if (destination == city_name && delivery == del_method){
        float cos = calCost(shipment_name, del_method, citymap[city_name], hq);
        hq.addjust_balance(cos);
    }else{
        cout<<"You get fined 50$ for sending a package with wrong data";
        hq.addjust_balance(-50);
    }
}

void Game::saveState(std::string file="GameSave.txt") const{
    std::ofstream f;
    f.open(file);
    f << *this;
    f.close();
}

void Game::loadState(std::string file="GameSave.txt"){
    std::ifstream f;
    f.open(file);
    f >> *this;
    f.close();
}

inline std::ostream& operator<<(ostream& os, const Game& game){
    os << "\tGAME{\n" << game.round_count <<",\n" <<game.package_num <<",\n" <<game.letter_num <<",\n";
    for(const auto& kv: game.cities){
        os << kv.second;
    }
    os << "}" <<endl;
    return os;
}

inline std::istream& operator>>(istream& is, Game& game){
    string s;
    is >> s;
    is >> s;
    s.pop_back();
    game.setRoundCount(std::stoi(s));
    is >> s;
    s.pop_back();
    game.setPackageNum(std::stoi(s));
    is >> s;
    s.pop_back();
    game.setLetterNum(std::stoi(s));
    char c;
    is >> c;
    while (c!='}'){
        is.putback(c);
        City new_city;
        is >> new_city;
        game.add_city(new_city);
        is >> c;
    }
    return is;
}