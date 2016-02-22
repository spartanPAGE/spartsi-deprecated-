#include "catch/catch.hpp"
#include "node/node.hpp"

#include <string>
using std::string;

TEST_CASE("Spawning child nodes", "[spartsi::node]") {
    using node = spartsi::node<string>;

    auto root = node::spawn_root("root", "1.0", "no comments...");
    const auto child = root->spawn_child("child", "some comment");

    SECTION("Spawned child contains valid data"){
        REQUIRE(child->name == "child");
        REQUIRE(child->version == "1.0");
        REQUIRE(child->comment == "some comment");
    }

    SECTION("Spawned child was properly registered") {
        REQUIRE(root->children.count(child->name));
    }
}