#include "catch/catch.hpp"

#include "parser/impl/tree_begin.hpp"
#include "langspec/default.hpp"
using namespace std;

TEST_CASE("tree begin", "[spartsi::parser::tree_begin") {
    auto spec = spartsi::default_::langspec;

    auto bld = spartsi::builder::build();

    SECTION("nameless") {
        std::string line = "treestructinfo \"2.0\"";
        REQUIRE(spartsi::parser::tree_begin(bld, spec, line));
        REQUIRE(bld.root->version == "2.0");
        REQUIRE(bld.root->name == "");
    }

    SECTION("nameful") {
        std::string line = "treestructinfo \"2.0\" name \"Hello :)\"";
        REQUIRE(spartsi::parser::tree_begin(bld, spec, line));
        REQUIRE(bld.root->version == "2.0");
        REQUIRE(bld.root->name == "Hello :)");
    }

    SECTION("nothing") {
        std::string line = "*gibberish*";
        REQUIRE_FALSE(spartsi::parser::tree_begin(bld, spec, line));
        REQUIRE(bld.root->version == "");
        REQUIRE(bld.root->name == "");
    }
}