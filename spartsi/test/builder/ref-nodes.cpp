#include "catch/catch.hpp"
#include "builder/tree-builder.hpp"

TEST_CASE("Ref nodes", "[spartsi::builder]") {
    using namespace spartsi::builder;

    auto tree = build()
        .treestructinfo("2.0").name("ref nodes")
            ("foo")
            .req_node("refnode")
        .end_tree()

        ("bar")
        .ref_node("refnode")
            .attr("attr", "test val")
            .req_node("refsec")
            ("1")
            .req_node("reflast")
        .end_ref_node()

        .ref_node("refsec")
            .attr("attr", "test another val")
        .end_ref_node()

        ("2")
        .ref_node("reflast")
            .attr(":)", "last")
        .end_ref_node()

        .get();


    SECTION("asserts") {
        SECTION("comment") {
            REQUIRE((tree->children.at("refnode")->comment == "foo\nbar"));
        }

        SECTION("normal attr") {
            REQUIRE((tree->children.at("refnode")->attributes.at("attr").first == "test val"));
        }

        SECTION("attr in refsec") {
            REQUIRE((tree->children["refnode"]->children["refsec"]->attributes["attr"].first == "test another val"));
        }

        SECTION("reflast") {
            REQUIRE((tree->children["refnode"]->children["reflast"]->attributes[":)"].first == "last"));
            REQUIRE((tree->children["refnode"]->children["reflast"]->comment == "1\n2"));
        }
    }
}