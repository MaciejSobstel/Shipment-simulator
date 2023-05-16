#include <map>
#include <iostream>

class Shipment;

class Container{
protected:
    std::map <std::string, Shipment> shipments;
public:
    Container(): shipments() {}
    void add_shipment(Shipment shipment);
    void remove_shipment(Shipment shipment);
    std::map<std::string, Shipment> get_shipments() const;
    void print_shipments() const;
};

class City : public Container{
    float distance;
    std::string name;
public:
    City(std::string n, float dist): name(n), distance(dist) {};
    float get_distance() const {return distance;};
};

class HQ : public Container{
    float balance;
public:
    HQ(float input_balance): balance(input_balance) {};
    void send_shipment(Shipment ship);
    void set_balance(float new_balance)          { balance = new_balance; };
    void addjust_balance(float gain)             { set_balance(get_balance() + gain);};
    float get_balance() const {return balance;};
};