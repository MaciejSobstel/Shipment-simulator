#include <iostream>
#include <map>
#include "shipment.cpp"

class Game{
    int round_count;
    int package_num;
    int letter_num;
    std::map<std::string, City&> cities;
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
    void add_city(City& city);
    void remove_city(City& city);
    void print_cities() const;
    std::map<std::string, City&> get_cities() const { return cities; }
    bool isDeliveryTypeSame(Shipment shipment, Delivery_method del_method) const;
    std::string RandomiseDeliveryType() const;
    City& RandomiseCity() const;
    float RandomiseWeight();
    std::string generateLetterName();
    std::string generatePackageName();
    Shipment generateShipment();
    void genShipmentInCity();
    Delivery_method getDelMethod(HQ& hq, std::string del_method) const;
    Shipment getShipment(HQ& hq, std::string shipment) const;
    float calCost(std::string shipment, std::string del_met, City city, HQ& hq) const;
    float calExpenses(std::string shipment, std::string del_met, City city, HQ& hq) const;
    void retreivePackage(City& city, string del_method, HQ& hq);
    
    // void loadState(std::string file="GameSave.txt");

    inline friend std::ostream& operator<<(ostream& os, const Game& game);
    inline friend std::istream& operator>>(istream& is, Game& game);
};