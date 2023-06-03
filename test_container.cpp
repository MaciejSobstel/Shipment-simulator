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