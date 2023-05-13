#include <map>
#include "classes.h"

class Container{
    std::map <std::string, Shipment> shipments;
public:
    void add_shipment(Shipment shipment);
    void remove_shipment(Shipment shipment);
    std::map<std::string, Shipment> get_shipments() const;
};

class Headquarters: Container{
    float balance;
    void set_balance(float new_balance)          { balance = new_balance; };
    void addjust_balance(float gain)             { set_balance(get_balance() + gain);};
public:
    Headquarters(float input_balance);
    void send_shipment(City destination);
    float get_balance() const {return balance;};
};

class City: Container{
    float distance;
    std::string name;
public:
    City(std::string n, float dist): name(n), distance(dist) {};
    float get_distance() const {return distance;};
};