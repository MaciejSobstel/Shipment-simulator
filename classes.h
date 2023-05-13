#include <iostream>
#include <map>

class Shipment{
    float cost;
    float expenses;
    std::string name;
public:
    Shipment(std::string input_name);
    void set_name(std::string new_name);
    std::string get_name() const;
    void set_expenses(float new_expenses);
    float get_expenses() const;
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
    float base_price;
    float expenses;
    std::string name;
public:
    Delivery_method(std::string input_name);
    void set_name(std::string new_name);
    std::string get_name() const;
    void set_base_price(float new_price);
    float get_base_price() const;
    void set_expenses(float new_expenses);
    float get_exepenses() const;
};

class Parcel_locker : public Delivery_method
{
public:
    Parcel_locker(std::string input_name);
};

class Delivery_man : public Delivery_method
{
public:
    Delivery_man(std::string input_name);
};

class Mailbox : public Delivery_method
{
public:
    Mailbox(std::string input_name);
};
