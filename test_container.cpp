#define CATCH_CONFIG_MAIN

#include "shipment.cpp"
#include "catch.hpp"

TEST_CASE("Testing Container::add_shipment()") {
    Shipment ship("ship", "Szczecin", "Delivery_man");
    Container cont;
    cont.add_shipment(ship);
    REQUIRE(cont.get_shipments().size() == 1);
}

TEST_CASE("Testing Container::remove_shipment()") {
    Shipment ship("ship", "Szczecin", "Delivery_man");
    Container cont;
    cont.add_shipment(ship);
    REQUIRE(cont.get_shipments().size() == 1);
    cont.remove_shipment(ship.get_name());
    REQUIRE(cont.get_shipments().size() == 0);
}

TEST_CASE("Testing City::City()") {
    City wad("Wadowice", 2137);
    REQUIRE(wad.get_distance() == 2137);
    REQUIRE(wad.get_name() == "Wadowice");
}

TEST_CASE("Testing City::set_name()") {
    City wad("Wadowice", 2137);
    REQUIRE(wad.get_name() == "Wadowice");
    wad.set_name("Bestia");
    REQUIRE(wad.get_name() == "Bestia");
}

TEST_CASE("Testing City::set_distance()") {
    City wad("Wadowice", 2137);
    REQUIRE(wad.get_distance() == 2137);
    wad.set_distance(21.37);
    REQUIRE(wad.get_distance() == float(21.37));
}

TEST_CASE("Testing HQ::sendDeliveryMethod false"){
    HQ hq(1000);
    bool test = hq.sendDeliveryMethod("Parcel_locker");
    REQUIRE(test == false);
}

TEST_CASE("Testing HQ::sendDeliveryMethod true"){
    HQ hq(1000);
    hq.buy_parcel_locker();
    bool test = hq.sendDeliveryMethod("Parcel_locker");
    REQUIRE(test == true);
}

TEST_CASE("Testing HQ::buy_parcel_locker"){
    HQ hq(1000);
    hq.buy_parcel_locker();
    int bal = hq.get_balance();
    REQUIRE(bal == 880);
    REQUIRE(hq.get_delivery_methods().size() == 1);
    hq.sendDeliveryMethod("Parcel_locker");
    REQUIRE(hq.get_delivery_methods().size() == 0);
}

TEST_CASE("Testing HQ::buy_mailbox"){
    HQ hq(1000);
    hq.buy_mailbox();
    int bal = hq.get_balance();
    REQUIRE(bal == 800);
    REQUIRE(hq.get_delivery_methods().size() == 1);
    hq.sendDeliveryMethod("Mailbox");
    REQUIRE(hq.get_delivery_methods().size() == 0);
}

TEST_CASE("Testing HQ::buy_delivery_man"){
    HQ hq(1000);
    hq.buy_delivery_man();
    int bal = hq.get_balance();
    REQUIRE(bal == 700);
    REQUIRE(hq.get_delivery_methods().size() == 1);
    hq.sendDeliveryMethod("Delivery_man");
    REQUIRE(hq.get_delivery_methods().size() == 0);
}

TEST_CASE("Testing Delivery_method:get_name"){
    Parcel_locker par("Parcel_locker");
    Mailbox mail("Mailbox");
    Delivery_man del("Delivery_man");
    std::string par_name = par.get_name();
    std::string mail_name = mail.get_name();
    std::string del_name = del.get_name();
    REQUIRE(par_name == "Parcel_locker");
    REQUIRE(mail_name == "Mailbox");
    REQUIRE(del_name == "Delivery_man");
}

TEST_CASE("Testing Shipment getters"){
    Letter let("Letter", "Radom", "Mailbox");
    std::string let_name = let.get_name();
    std::string let_det = let.get_destination();
    std::string let_del = let.get_delivery_type();
    REQUIRE(let_name == "Letter");
    REQUIRE(let_det == "Radom");
    REQUIRE(let_del == "Mailbox");
}

TEST_CASE("Testing Shipment::getexpenses , getcost"){
    Letter let("Letter", "Radom", "Mailbox");
    let.set_expenses(1);
    let.set_cost(0.5);
    float exp = let.get_expenses();
    float cost = let.get_cost();
    REQUIRE(exp == 1);
    REQUIRE(cost == 0.5);
}

TEST_CASE("Testing Shipment::isCitySame"){
    Letter let("Letter", "Radom", "Mailbox");
    City radom("Radom", 100);
    REQUIRE(let.isCitySame(radom) == true);
}

TEST_CASE("Testing Shipment::set_delivery_type"){
    Letter let("Letter", "Radom", "Mailbox");
    let.set_delivery_type("Delivery_man");
    REQUIRE(let.get_delivery_type() == "Delivery_man");
}

TEST_CASE("Testing Package::set_weight"){
    Package pack("Package", "Radom", "Mailbox", 2.5);
    pack.set_weight(10);
    REQUIRE(pack.get_weight() == 10);
}

TEST_CASE("Testing HQ::add_delivery_method, remove_delivery_methhod"){
    HQ hq(1000);
    Delivery_man del("Delivery_man");
    hq.add_delivery_method(del);
    REQUIRE(hq.get_delivery_methods().size() == 1);
    hq.remove_delivery_method(del);
    REQUIRE(hq.get_delivery_methods().size() == 0);
}

TEST_CASE("Testing Delivery_method::set,get _name"){
    Delivery_method del("Delivery_man");
    del.set_name("Mailbox");
    REQUIRE(del.get_name() == "Mailbox");
}

TEST_CASE("Testing Delivery_method::set,get _base_price"){
    Delivery_method del("Delivery_man");
    del.set_base_price(5);
    REQUIRE(del.get_base_price() == 5);
}

TEST_CASE("Testing Delivery_method::set,get expenses"){
    Delivery_method del("Delivery_man");
    del.set_expenses(5);
    REQUIRE(del.get_expenses() == 5);
}

TEST_CASE("Testing Delivery_method::set,get delivery_type"){
    Delivery_method del("Delivery_man");
    del.set_delivery_type("Mailbox");
    REQUIRE(del.get_delivery_type() == "Mailbox");
}