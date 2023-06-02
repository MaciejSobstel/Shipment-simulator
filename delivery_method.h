#include <iostream>


class Delivery_method{
    float base_price;
    float expenses;
    std::string name;
    std::string delivery_type;
public:
    Delivery_method(std::string input_name);
    void set_name(std::string new_name);
    std::string get_name() const;
    void set_base_price(float new_price);
    float get_base_price() const;
    void set_expenses(float new_expenses);
    float get_expenses() const;
    void set_delivery_type(std::string new_del_type);
    std::string get_delivery_type() const;
    void print() const;
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