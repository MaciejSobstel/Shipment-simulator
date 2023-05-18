#include <iostream>
#include <map>
#include "shipment.cpp"
#include "delivery_method.cpp"

class Game{
    int round_count;
    int package_num;
    int letter_num;

public:
    Game() : round_count(1), package_num(1), letter_num(1){}
    void setRoundCount(int count) { round_count = count; }
    int getRoundCount() const { return round_count; }
    void countRoundUp() { round_count = round_count + 1;}
    void setPackageNum(int num) { package_num = num; }
    int getPackageNum() const { return package_num; }
    void countPackageNumUp() { package_num = package_num + 1;}
    void setLetterNum(int num) { letter_num = num; }
    int getLetterNum() const { return letter_num; }
    void countLetterNumUp() { letter_num = letter_num + 1;};
    bool isDeliveryTypeSame(Shipment shipment, Delivery_method del_method) const;
    std::string RandomiseDeliveryType() const;
    City& RandomiseCity(City* cities[], int numCities) const;
    float RandomiseWeight();
    std::string generateLetterName();
    std::string generatePackageName();
    Shipment generateShipment(City* cities[], int numCities);
};