#include "catch/catch.hpp"

#include "parser/impl/tree_begin.hpp"
#include "langspec/default.hpp"
using namespace std;

TEST_CASE("tree begin", "[spartsi::parser::tree_begin") {
    auto spec = spartsi::default_::langspec;

    SECTION("nameless tree") {
        auto builder = spartsi::builder::build();
        std::string line = "treestructinfo \"2.0\"";
        auto result = spartsi::parser::tree_begin(builder, spec, line);
        REQUIRE(result);
        REQUIRE(builder.root->version == "2.0");
    }
}