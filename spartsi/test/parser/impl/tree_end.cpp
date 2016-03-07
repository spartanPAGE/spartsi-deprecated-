#include "catch/catch.hpp"

#include <parser/impl/tree_end.hpp>
#include "langspec/default.hpp"
using namespace std;

TEST_CASE("tree end", "[spartsi::parser::tree_end") {
    auto spec = spartsi::default_::langspec;
    auto bld = spartsi::builder::build();
    bld.treestructinfo("");

    SECTION("good") {
        REQUIRE(spartsi::parser::tree_end(bld, spec, std::string("end tree")));
    }

    SECTION("bad") {
        REQUIRE_FALSE(spartsi::parser::tree_end(bld, spec, std::string("whatever")));
    }
}