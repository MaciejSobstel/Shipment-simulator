#define CATCH_CONFIG_MAIN

#include "game.cpp"
#include "catch.hpp"

TEST_CASE("Testing Game::add,remove City"){
    Game game;
    City radom("Radom", 100);
    game.add_city(radom);
    REQUIRE(game.get_cities().size() == 1);
    game.remove_city(radom);
    REQUIRE(game.get_cities().size() == 0);
}

TEST_CASE("Testing Game::IsDeliveryTypeSame"){
    Game game;
    Letter let("Letter", "Radom", "Delivery_man");
    Delivery_man del("Delivery_man");
    REQUIRE(game.isDeliveryTypeSame(let, del) == true);
}

TEST_CASE("Tetsing Game::genShipmentInCity"){
    Game game;
    HQ hq(1000);
    City radom("Radom", 100);
    game.add_city(radom);
    game.genShipmentInCity();
    REQUIRE(game.get_city("Radom").get_shipments().size() == 1);
}

TEST_CASE("Testing Game::retreivePackage"){
    Game game;
    HQ hq(1000);
    City radom("Radom", 100);
    game.add_city(radom);
    game.genShipmentInCity();
    game.retreivePackage("Radom", hq);
    REQUIRE(game.get_city("Radom").get_shipments().size() == 0);
    REQUIRE(hq.get_shipments().size() == 1);
}

TEST_CASE("Testing Game::set, get RoundCout"){
    Game game;
    game.setRoundCount(2137);
    REQUIRE(game.getRoundCount() == 2137);
}

TEST_CASE("Testing Game::set, get, count PackageNum"){
    Game game;
    game.setPackageNum(420);
    game.countPackageNumUp();
    REQUIRE(game.getPackageNum() == 421);
}

TEST_CASE("Testing Game::set, get, count LetterNum"){
    Game game;
    game.setLetterNum(69);
    game.countLetterNumUp();
    REQUIRE(game.getLetterNum() == 70);
}

TEST_CASE("Testing Game::sendPackage"){
    Game game;
    HQ hq(1000);
    City radom("Radom", 100);
    game.add_city(radom);
    Shipment ship("Letter", "Radom", "Delivery_man");
    game.get_city("Radom").add_shipment(ship);
    game.retreivePackage("Radom", hq);
    game.sendPackage("Radom", "Delivery_man", "Letter", hq);
    REQUIRE(hq.get_shipments().size() == 0);
}

TEST_CASE("Testing Game::isShipmentInStorage"){
    Game game;
    HQ hq(1000);
    Shipment ship("Letter", "Radom", "Delivery_man");
    hq.add_shipment(ship);
    REQUIRE(game.isShipmentInStorage("Letter", hq));
}