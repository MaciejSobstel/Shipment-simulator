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
    double distance;
    float cost;
public:
    Delivery_method(float input_distance);
    void set_distance(float new_distance);
    float get_distance() const;
    void set_cost(float new_cost);
    float get_cost() const;
    float calculate_cost(float base_price, float multiplier) const;
};

class Parcel_locker : public Delivery_method
{
public:
    Parcel_locker(float input_distance);
};

class Delivery_man : public Delivery_method
{
public:
    Delivery_man(float input_distance);
};

class Mailbox : public Delivery_method
{
public:
    Mailbox(float input_distance);
};
