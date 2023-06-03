#include <iostream>
#include "delivery_method.cpp"

using namespace std;

class Shipment;

class Container{
protected:
    std::map <std::string, Shipment> shipments;
public:
    Container(): shipments() {}
    void add_shipment(Shipment shipment);
    void remove_shipment(string shipment_name);
    std::map<std::string, Shipment> get_shipments() const;
    void set_shipments(const std::map<std::string, Shipment>& newShipments) {
        shipments = newShipments;
    }
    void print_shipments() const;
};

class City : public Container{
    float distance;
    std::string name;
public:
    City(std::string n, float dist): name(n), distance(dist) {};
    City(){};
    float get_distance() const                  {return distance;}
    void set_distance(float new_distance)       {distance = new_distance;}
    std::string get_name() const                {return name;}
    void set_name(std::string new_name)         {name = new_name;}

    inline friend std::ostream& operator<<(ostream& os, const City& city);
    inline friend std::istream& operator>>(istream& is, City& city);
};

class HQ : public Container{
    float balance;
    std::map<std::string, Delivery_method> delivery_methods;
    std::map<std::string, Delivery_method> working_delivery_methods;
    int mailbox_num;
    int delivery_man_num;
    int parcel_locker_num;

    std::string generate_parcel_locker_name();
    std::string generate_mailbox_name();
    std::string generate_delivery_man_name();
    void countMailboxNumUp()                    { mailbox_num = mailbox_num + 1;}
    void countDeliveryManNumUp()                { delivery_man_num = delivery_man_num + 1;};
    void countParcelLockerNumUp()               { parcel_locker_num = parcel_locker_num + 1;};
public:
    HQ(float input_balance): balance(input_balance), mailbox_num(1), delivery_man_num(1), parcel_locker_num(1){};
    std::map<std::string, Delivery_method> getWorkingDeliveryMethods() const {return  working_delivery_methods;}
    bool sendDeliveryMethod(string del_met_type);
    void returnDeliveryMethods();
    void setMailboxNum(int num)                 { mailbox_num = num; }
    int getMailboxNum() const                   { return mailbox_num; }
    void setDeliveryManNum(int num)             { delivery_man_num = num; }
    int getDeliveryManNum() const               { return delivery_man_num; }
    void setParcelLockerNum(int num)            { parcel_locker_num = num; }
    int getParcelLockerNum() const              { return parcel_locker_num; }
    void set_balance(float new_balance)          { balance = new_balance; }
    void addjust_balance(float gain)             { set_balance(get_balance() + gain);}
    float get_balance() const {return balance;}
    std::map<std::string, Delivery_method> get_delivery_methods() const { return delivery_methods; }
    void print_delivery_methods() const;
    void add_delivery_method(Delivery_method delivery_method);
    void remove_delivery_method(Delivery_method delivery_method);
    void buy_parcel_locker();
    void buy_mailbox();
    void buy_delivery_man();
    void print_balance() const;

    void saveState(std::string file) const;
    void loadState(std::string file);

    inline friend std::ostream& operator<<(ostream& os, const HQ& hq);
    inline friend std::istream& operator>>(istream& is, HQ& hq);
};

class Shipment{
    std::string destination;
    float cost;
    float expenses;
    std::string name;
    std::string delivery_type;
public:
    Shipment(std::string input_name, std::string destin, std::string del_type): destination(destin), name(input_name), delivery_type(del_type) {};
    Shipment() {};
    void set_name(std::string new_name);
    std::string get_name() const;
    std::string get_destination() const         {return destination;}
    void set_destination(std::string new_dest)  {destination = new_dest;}
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
    Letter(string input_name, string destin, string del_type);
};

class Package : public Shipment
{
    float weight;
public:
    Package(string input_name, string destin, string del_type, float weight);
    void set_weight(float new_weight);
    float get_weight() const;
};
