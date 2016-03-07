#include "catch/catch.hpp"

#include <parser/impl/node_end.hpp>
#include "langspec/default.hpp"
using namespace std;

TEST_CASE("node end", "[spartsi::parser::node_end") {
    auto spec = spartsi::default_::langspec;
    auto bld = spartsi::builder::build();
    bld.treestructinfo("");
    bld.node("");

    SECTION("good") {
        REQUIRE(spartsi::parser::node_end(bld, spec, std::string("end node")));
    }

    SECTION("bad") {
        REQUIRE_FALSE(spartsi::parser::node_end(bld, spec, std::string("whatever")));
    }
}