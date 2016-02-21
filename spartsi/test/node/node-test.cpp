#include "catch/catch.hpp"
#include "node/node.hpp"

#include <string>
using std::string;

TEST_CASE("Creation of simple nodes", "[spartsi::node]") {
    auto name = "The sample object";
    auto version = "1.0";
    auto comment = "sample comment";

    auto node = spartsi::create_node<string>(name, version, comment);

    SECTION("Node is not null") {
        REQUIRE(node != nullptr);
    }

    SECTION("Infos are properly set") {
        REQUIRE(node->name == name);
        REQUIRE(node->version == version);
        REQUIRE(node->comment == comment);
    }
}