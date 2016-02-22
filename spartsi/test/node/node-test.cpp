#include "catch/catch.hpp"
#include "node/node.hpp"

#include <string>
using std::string;

TEST_CASE("Creation of simple nodes", "[spartsi::node]") {
    using node = spartsi::node<string>;

    SECTION("children-less, attribute-less") {
        auto name = "The sample object";
        auto version = "1.0";
        auto comment = "sample comment";

        auto node = node::spawn_root(name, version, comment);

        SECTION("Node is not null") {
            REQUIRE(node != nullptr);
        }

        SECTION("Infos are properly set") {
            REQUIRE(node->name == name);
            REQUIRE(node->version == version);
            REQUIRE(node->comment == comment);
        }
    }

    SECTION("node with attributes (lets invoke the second constructor)"){
        auto name = "Some name";
        auto version = "2.0";
        auto comment = "<insert hate here>";
        auto attr_key = "foo";
        auto attr_val = "bar";
        node::attributes_t attrs = {{attr_key, attr_val}};

        auto node = node::spawn_root(name, version, comment, attrs);

        SECTION("Node is not null") {
            REQUIRE(node != nullptr);
        }

        SECTION("Infos are properly set") {
            REQUIRE(node->name == name);
            REQUIRE(node->version == version);
            REQUIRE(node->comment == comment);
            REQUIRE(node->attributes[attr_key] == attr_val);
        }
    }
}