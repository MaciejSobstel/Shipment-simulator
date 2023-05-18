#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include "game.h"

using namespace std;

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

City& Game::RandomiseCity(City* cities[], int numCities) const{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, numCities - 1);
    int randomIndex = dist(gen);
    return *cities[randomIndex];
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

Shipment Game::generateShipment(City* cities[], int numCities){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, 1);

    int randomNumber = distribution(gen);
    City& destin = RandomiseCity(cities, numCities);
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