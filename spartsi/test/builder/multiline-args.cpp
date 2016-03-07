#include "catch/catch.hpp"
#include "builder/tree-builder.hpp"

TEST_CASE("multiline attrs", "[spartsi::builder]") {
    using namespace spartsi::builder;

    auto tree = build()
        .treestructinfo("2.0").name("ref attrs")
          .attr("1st", "foo")
             .attr_val("bar")
             .attr_val(":)")

          .req_attr("2nd")
        .end_tree()

        .ref_attr("2nd", "fizz")
               .attr_val("buzz")
               .attr_val(":)")
        .get();


    SECTION("asserts") {
        REQUIRE(tree->attributes.at("1st").first == "foo\nbar\n:)");
        REQUIRE(tree->attributes.at("2nd").first == "fizz\nbuzz\n:)");
    }
}