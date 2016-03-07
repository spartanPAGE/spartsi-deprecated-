#include "catch/catch.hpp"

#include "parser/impl/ref-node/node-decl-def.hpp"
#include "langspec/default.hpp"
using namespace std;

TEST_CASE("declare & define node", "[spartsi::parser::node_decl_def") {
    auto spec = spartsi::default_::langspec;

    auto bld = spartsi::builder::build();
    bld.treestructinfo("");

    SECTION("asserts") {
        REQUIRE(spartsi::parser::node_decl_def(bld, spec, std::string("ref node Jim")));
        REQUIRE(bld.get()->children.count("Jim"));
        bld.end_tree();

        REQUIRE(spartsi::parser::node_decl_def(bld, spec, std::string("ref node Jim")));
        bld.attr("test", "val");

        REQUIRE(bld.get()->children.at("Jim")->attributes.at("test").first == "val");
    }
}