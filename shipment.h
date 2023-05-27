#include <iostream>

using namespace std;

class City;

class Shipment{
    City& destination;
    float cost;
    float expenses;
    std::string name;
public:
    Shipment(std::string input_name, City& destin): destination(destin), name(input_name) {};
    void set_name(std::string new_name);
    std::string get_name() const;
    void set_expenses(float new_expenses);
    float get_expenses() const;
    void set_cost(float new_cost);
    float get_cost() const;
    bool isCitySame(const City& obj) const;
};

class Letter : public Shipment
{
public:
    Letter(std::string input_name, City& destin);
};

class Package : public Shipment
{
    float weight;
public:
    Package(std::string input_name, City& destin, float weight);
    void set_weight(float new_weight);
    float get_weight() const;
};
