#include <iostream>
#include <vector>

class Shipment{
    float cost;
    std::string name;
public:
    Shipment(std::string input_name);
    void set_name(std::string new_name);
    std::string get_name() const;
    void set_cost(float new_cost);
    float get_cost() const;
};

class Letter : public Shipment
{
public:
    Letter(std::string input_name);
};

class Package : public Shipment
{
    float weight;
public:
    Package(std::string input_name, float weight);
    void set_weight(float new_weight);
    float get_weight() const;
};

class Delivery_method{
    double distance;
    float cost;
    std::string name;
public:
    Delivery_method(std::string input_name, float input_distance);
    void set_name(std::string new_name);
    std::string get_name() const;
    void set_distance(float new_distance);
    float get_distance() const;
    void set_cost(float new_cost);
    float get_cost() const;
    float calculate_cost(float base_price, float multiplier) const;
};

class Parcel_locker : public Delivery_method
{
public:
    Parcel_locker(std::string input_name, float input_distance);
};

class Delivery_man : public Delivery_method
{
public:
    Delivery_man(std::string input_name, float input_distance);
};

class Mailbox : public Delivery_method
{
public:
    Mailbox(std::string input_name, float input_distance);
};

class Headquarters{
    std::vector<Shipment> shipments;
    float balance;
public:
    Headquarters(float input_balance);
    void add_Shipment(Shipment s);
    std::vector<Shipment> get_Shipments() const;
    void print_Shipments() const;
    void set_balance(float new_balance);
    void add_to_balance(float price);
    float get_balance() const ;
};
