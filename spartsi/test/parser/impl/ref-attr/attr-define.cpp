#include "catch/catch.hpp"

#include "parser/text/impl/ref-attr/attr-define.hpp"
#include "langspec/default.hpp"
using namespace std;

TEST_CASE("define attr", "[spartsi::parser::attr_define") {
    auto spec = spartsi::default_::langspec;

    auto bld = spartsi::builder::build();
    bld.treestructinfo("");
    bld.req_attr("foo attr");
    bld.end_tree();

    SECTION("good") {
        REQUIRE(spartsi::parser::attr_define(bld, spec, std::string("ref attr foo attr \"val\"")));
        REQUIRE(bld.get()->attributes.count("foo attr"));
        REQUIRE(bld.get()->attributes.at("foo attr").first == "val");

        SECTION("bad") {
            REQUIRE_THROWS(spartsi::parser::attr_define(bld, spec, std::string("ref attr unknown \"val\"")));
        }
    }
}