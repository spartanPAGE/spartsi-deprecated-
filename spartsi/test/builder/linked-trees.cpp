#include "catch/catch.hpp"
#include "builder/tree-builder.hpp"

TEST_CASE("Linked trees", "[spartsi::builder]") {
    using namespace spartsi::builder;

    /*todo: comments to linked trees*/

    auto to_be_linked = build()
        ("real comment")
        .treestructinfo("2.0").name("to be linked")
            .attr("attr from linked tree", "bazinga")
        .end_tree().get();

    auto first_tree = build()
        .treestructinfo("2.0").name("first")
            ("comment of the first tree linkage")
            .tree("linked", to_be_linked)
        .end_tree().get();

    auto second_tree = build()
        .treestructinfo("2.0").name("second")
            ("comment of the second tree linkage")
            .tree("linked", to_be_linked)
        .end_tree().get();


    SECTION("asserts") {
        SECTION("first tree properly linked to_be_linked tree") {
            REQUIRE((first_tree->children["linked"]->attributes["attr from linked tree"].first == "bazinga"));
            REQUIRE((first_tree->alternative_comments["linked"] == "comment of the first tree linkage"));
        }

        SECTION("second tree properly linked to_be_linked tree") {
            REQUIRE((second_tree->children["linked"]->attributes["attr from linked tree"].first == "bazinga"));
            REQUIRE((second_tree->alternative_comments["linked"] == "comment of the second tree linkage"));
        }
    }
}