#include <iostream>

class Shipment{
    float cost;
public:
    void set_cost(float new_cost);
    float get_cost() const;
};

class Letter : public Shipment
{
public:
    Letter();
};

class Package : public Shipment
{
    float weight;
public:
    Package(float weight);
    void set_weight(float new_weight);
    float get_weight() const;
};

class Delivery_method{

};
