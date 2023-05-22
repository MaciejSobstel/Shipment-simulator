#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include "game.h"

using namespace std;

void Game::add_city(City& city){
    string city_name = city.get_name();
    cities.insert({city_name, city});
}

void Game::remove_city(City& city){
    string city_name = city.get_name();
    cities.erase(city_name);
}

void Game::print_cities() const {
    map<string, City&> cities_map = get_cities();
    int cityCount = 1;
    cout << "Cities:\n";
    for (auto it = cities_map.begin(); it != cities_map.end(); ++it) {
        cout << cityCount << ". " << it->first << endl;
        cityCount++;
    }
    cout << endl;
}

bool Game::isDeliveryTypeSame(Shipment shipment, Delivery_method del_method) const{
    string shipment_del_type = shipment.get_delivery_type();
    string delivery_del_type = del_method.get_delivery_type();
    return shipment_del_type == delivery_del_type;
}

string Game::RandomiseDeliveryType() const{
    string choices[] = { "Mailbox", "Delivery man", "Parcel locker" };

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dist(0, 2);
    int randomIndex = dist(gen);

    return choices[randomIndex];
}

City& Game::RandomiseCity() const{
    map<string, City&> cities_map = get_cities();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, cities_map.size() - 1);
    int randomIndex = dist(gen);
    auto it = cities_map.begin();
    std::advance(it, randomIndex);
    return it->second;
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
    City& destin = RandomiseCity();
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