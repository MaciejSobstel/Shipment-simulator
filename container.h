#include <map>
#include <iostream>

#include "delivery_method.cpp"

class Shipment;

class Container{
protected:
    std::map <std::string, Shipment> shipments;
public:
    Container(): shipments() {}
    void add_shipment(Shipment shipment);
    void remove_shipment(Shipment shipment);
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
    float get_distance() const {return distance;}
    void set_distance(float new_distance) {distance = new_distance;}
    std::string get_name() const {return name;}
    void set_name(std::string new_name) {name = new_name;}
};

class HQ : public Container{
    float balance;
    std::map<std::string, Delivery_method> delivery_methods;
    int mailbox_num;
    int delivery_man_num;
    int parcel_locker_num;
public:
    HQ(float input_balance): balance(input_balance), mailbox_num(1), delivery_man_num(1), parcel_locker_num(1){};
    void setMailboxNum(int num) { mailbox_num = num; }
    int getMailboxNum() const { return mailbox_num; }
    void countMailboxNumUp() { mailbox_num = mailbox_num + 1;}
    void setDeliveryManNum(int num) { delivery_man_num = num; }
    int getDeliveryManNum() const { return delivery_man_num; }
    void countDeliveryManNumUp() { delivery_man_num = delivery_man_num + 1;};
    void setParcelLockerNum(int num) { parcel_locker_num = num; }
    int getParcelLockerNum() const { return parcel_locker_num; }
    void countParcelLockerNumUp() { parcel_locker_num = parcel_locker_num + 1;};
    void send_shipment(Shipment ship);
    void set_balance(float new_balance)          { balance = new_balance; }
    void addjust_balance(float gain)             { set_balance(get_balance() + gain);}
    float get_balance() const {return balance;}
    std::map<std::string, Delivery_method> get_delivery_methods() const { return delivery_methods; }
    void print_delivery_methods() const;
    void add_delivery_method(Delivery_method delivery_method);
    void remove_delivery_method(Delivery_method delivery_method);
    std::string generate_parcel_locker_name();
    std::string generate_mailbox_name();
    std::string generate_delivery_man_name();
    void buy_parcel_locker();
    void buy_mailbox();
    void buy_delivery_man();
    void print_balance() const;
};