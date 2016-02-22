#include "catch/catch.hpp"
#include "node/node.hpp"

#include <utility>
#include <string>

using std::string;

TEST_CASE("Creation of simple nodes", "[spartsi::node]") {
    using spartsinode = spartsi::node<string>;

    SECTION("children-less, attribute-less") {
        auto name = "The sample object";
        auto version = "1.0";
        auto comment = "sample comment";

        auto node = spartsinode::spawn_root(name, version, comment);

        SECTION("Node is not null") {
            REQUIRE(node != nullptr);
        }

        SECTION("Infos are properly set") {
            REQUIRE(node->name == name);
            REQUIRE(node->version == version);
            REQUIRE(node->comment == comment);
        }
    }

    SECTION("node with attributes (lets invoke the second constructor)") {
        auto name = "Some name";
        auto version = "2.0";
        auto comment = "<insert hate here>";
        auto attr_key = "foo";
        auto attr = spartsinode::attribute_t{ "bar", "no comment" };
        auto attrs = spartsinode::attributes_t{{attr_key, attr}};

        auto node = spartsinode::spawn_root(name, version, comment, attrs);

        SECTION("Node is not null") {
            REQUIRE(node != nullptr);
        }

        SECTION("Infos are properly set") {
            REQUIRE(node->name == name);
            REQUIRE(node->version == version);
            REQUIRE(node->comment == comment);
            REQUIRE(node->attributes[attr_key] == attr);
        }
    }
}