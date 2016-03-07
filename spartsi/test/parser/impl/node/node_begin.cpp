#include "catch/catch.hpp"

#include "parser/impl/node/node_begin.hpp"
#include "langspec/default.hpp"
using namespace std;

TEST_CASE("node begin", "[spartsi::parser::node_begin") {
    auto spec = spartsi::default_::langspec;

    auto bld = spartsi::builder::build();
    bld.treestructinfo("");

    SECTION("good") {
        REQUIRE(spartsi::parser::node_begin(bld, spec, std::string("node whatever")));
    }

    SECTION("bad") {
        REQUIRE_FALSE(spartsi::parser::node_begin(bld, spec, std::string("node")));
    }
}