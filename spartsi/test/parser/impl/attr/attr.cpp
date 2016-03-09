#include "catch/catch.hpp"

#include "parser/text/impl/attr/attr.hpp"
#include "langspec/default.hpp"
using namespace std;

TEST_CASE("attr", "[spartsi::parser::attr") {
    auto spec = spartsi::default_::langspec;

    auto bld = spartsi::builder::build();
    bld.treestructinfo("");

    SECTION("good") {
        REQUIRE(spartsi::parser::attr(bld, spec, std::string("attr  Some Name  \"  Some Value  \"  ")));
        REQUIRE(bld.get()->attributes.at("Some Name").first == "Some Value");
    }

    SECTION("bad") {
        REQUIRE_FALSE(spartsi::parser::attr(bld, spec, std::string("attr blah")));
    }
}