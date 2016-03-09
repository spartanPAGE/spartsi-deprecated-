#include "catch/catch.hpp"

#include "parser/text/impl/ref-attr/attr-declare.hpp"
#include "langspec/default.hpp"
using namespace std;

TEST_CASE("declare attr", "[spartsi::parser::attr_declare") {
    auto spec = spartsi::default_::langspec;

    auto bld = spartsi::builder::build();
    bld.treestructinfo("");

    SECTION("good") {
        REQUIRE(spartsi::parser::attr_declare(bld, spec, std::string("ref attr  Some Name ")));
        REQUIRE(bld.get()->attributes.count("Some Name"));
    }

    SECTION("bad") {
        REQUIRE_FALSE(spartsi::parser::attr_declare(bld, spec, std::string("ref attr")));
    }
}