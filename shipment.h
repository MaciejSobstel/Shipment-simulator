#include <iostream>

using namespace std;

class City;

class Shipment{
    City& destination;
    float cost;
    float expenses;
    std::string name;
    std::string delivery_type;
public:
    Shipment(std::string input_name, City& destin, std::string del_type): destination(destin), name(input_name), delivery_type(del_type) {};
    Shipment(City& destin): destination(destin) {};
    void set_name(std::string new_name);
    std::string get_name() const;
    City& get_destination() const {return destination;}
    void set_expenses(float new_expenses);
    float get_expenses() const;
    void set_cost(float new_cost);
    float get_cost() const;
    bool isCitySame(const City& obj) const;
    void set_delivery_type(std::string new_del_type);
    std::string get_delivery_type() const;
    void print() const;

    inline friend std::ostream& operator<<(ostream& os, const Shipment& shipment);
    inline friend std::istream& operator>>(istream& is, Shipment& shipment);
};

class Letter : public Shipment
{
public:
    Letter(std::string input_name, City& destin, std::string del_type);
};

class Package : public Shipment
{
    float weight;
public:
    Package(std::string input_name, City& destin, std::string del_type, float weight);
    void set_weight(float new_weight);
    float get_weight() const;
};
